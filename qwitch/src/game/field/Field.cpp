//---------------------------------------------------------------------
// 
//  
// 
//
#include "Field.hpp"
#include "DxLib.h"
#include "system/System.hpp"
#include "game/field/FieldParameter.hpp"

namespace qwitch {
namespace game {

//---------------------------------------------------------------------
// 
//  
// 
//
Field::Field()
    : mCamera()
    , mTerrain()
    , mCharacters()
{
}

//---------------------------------------------------------------------
// 
//  
// 
//
void Field::update()
{
    //----- キャラクターの更新
    mCharacters.update(mCamera);
    updateCharacters();

    //----- カメラの更新
    updateCamera();

    //----- 表示地形の更新
    mTerrain.update(mCamera);
}

//---------------------------------------------------------------------
// 
//  
// 
//
void Field::updateCharacters()
{
    int count = mCharacters.countCharacter();
    for (int i = 0; i < count; i++) {
        updateCharacter(i);
    }
}

//---------------------------------------------------------------------
// 
//  
// 
//
void Field::updateCharacter(int aIndex)
{
    //-----
    const Character& chara = mCharacters.character(aIndex);

    //----- 重力
    double gravity = 0.5;
    mCharacters.addForce(aIndex, Vector3d(0, 0, gravity * -1));

    //----- 外力更新
    double forceX = chara.force().x();
    double forceY = chara.force().y();
    double forceZ = chara.force().z();
    characterMove(aIndex, Vector3d(forceX, forceY, forceZ));

    //----- アニメーション更新
    if (isGround(aIndex) == false) {
        if (chara.force().z() < 0) {
            mCharacters.setAnimation(aIndex, Animation::Kind_Fall);
        }
        else {
            mCharacters.setAnimation(aIndex, Animation::Kind_Rise);
        }
    }
}

//---------------------------------------------------------------------
// 
//  
// 
//
void Field::updateCamera()
{
    //----- 状態更新
    const Character& player = mCharacters.player();
    mCamera.update(player);
}

//---------------------------------------------------------------------
// 
//  
// 
//
void Field::load(int aFieldIndex)
{
    mTerrain.load(0);
}

//---------------------------------------------------------------------
// 
//  
// 
//
void Field::playerWalk(int aX, int aY)
{
    characterWalk(FieldParameter::PlayerIndex, Vector3d(aX, aY, 0));
}

//---------------------------------------------------------------------
// 
//  
// 
//
void Field::playerJump()
{
    characterJump(FieldParameter::PlayerIndex);
}

//---------------------------------------------------------------------
// 
//  
// 
//
void Field::playerAttack()
{
    characterAttack(FieldParameter::PlayerIndex);
}

//---------------------------------------------------------------------
// 
//  
// 
//
void Field::characterWalk(int aIndex, const Vector3d& aPos)
{
    //----- キャラクター
    const Character& chara = mCharacters.character(aIndex);

    //----- プレイヤーオブジェクトの移動
    double speed = chara.status().moveSpeed();
    double dx = aPos.x() * speed;
    double dy = aPos.y() * speed;
    double dz = aPos.z();
    characterMove(aIndex, Vector3d(dx, dy, dz));

    //----- 向きの更新
    mCharacters.setDirection(aIndex, dx, dy, dz);

    //----- アニメーションの更新
    mCharacters.setAnimation(aIndex, Animation::Kind_Walk);
}

//---------------------------------------------------------------------
// 
//  
// 
//
void Field::characterMove(int aIndex, const Vector3d& aPos)
{
    // z軸の移動
    characterMoveZ(aIndex, aPos.z());
    // xy軸の移動
    characterMoveX(aIndex, aPos.x());
    characterMoveY(aIndex, aPos.y());
}

//---------------------------------------------------------------------
// 
//  
// 
//
void Field::characterMoveX(int aIndex, double aX)
{
    const Character& chara = mCharacters.character(aIndex);
    int absX = (int)abs(aX);
    int unitX = (aX >= 0) ? 1 : -1;
    for (int i = 0; i < absX; i++) {
        mCharacters.move(aIndex, Vector3d(unitX, 0, 0));
        if (isCollision(chara)) {
            mCharacters.move(aIndex, Vector3d(unitX * -1, 0, 0));
            mCharacters.setForceX(aIndex, 0);
        }
    }
}
//---------------------------------------------------------------------
void Field::characterMoveY(int aIndex, double aY)
{
    const Character& chara = mCharacters.character(aIndex);
    int absY = (int)abs(aY);
    int unitY = (aY >= 0) ? 1 : -1;
    for (int i = 0; i < absY; i++) {
        mCharacters.move(aIndex, Vector3d(0, unitY, 0));
        if (isCollision(chara)) {
            mCharacters.move(aIndex, Vector3d(0, unitY * -1, 0));
            mCharacters.setForceY(aIndex, 0);
        }
    }
}
//---------------------------------------------------------------------
void Field::characterMoveZ(int aIndex, double aZ)
{
    const Character& chara = mCharacters.character(aIndex);
    int absZ = (int)abs(aZ);
    int unitZ = (aZ >= 0) ? 1 : -1;
    for (int i = 0; i < absZ; i++) {
        mCharacters.move(aIndex, Vector3d(0, 0, unitZ));
        if (isCollision(chara)) {
            mCharacters.move(aIndex, Vector3d(0, 0, unitZ * -1));
            mCharacters.setForceZ(aIndex, 0);
        }
    }
}

//---------------------------------------------------------------------
// 
//  
// 
//
void Field::characterJump(int aIndex)
{
    //----- ジャンプ可能判定
    if (isJump(mCharacters.character(aIndex)) == false) {
        return;
    }

    //----- ジャンプ処理
    mCharacters.jump(aIndex);
}

//---------------------------------------------------------------------
// 
//  
// 
//
void Field::characterAttack(int aIndex)
{
    //-----
    const Character& attackChara = mCharacters.character(aIndex);

    //----- 攻撃可能判定
    if (isAttack(attackChara) == false) {
        return;
    }

    //----- 攻撃範囲内のキャラクター取得
    const Vector3d& areaPos = attackChara.attackAreaPos();
    const Vector3d& areaSize = attackChara.attackAreaSize();
    printf("areaPos %lf %lf %lf\n", areaPos.x(), areaPos.y(), areaPos.z());
    auto damagedIndex = findCharacterIndex(areaPos, areaSize);;

    //----- 攻撃処理
    int count = (int)damagedIndex.size();
    for (int i = 0; i < count; i++) {
        const Character& damagedChara = mCharacters.character(damagedIndex[i]);
        if (damagedChara.id() == attackChara.id()) { continue; }

        //--- 回避判定
        //--- ダメージ算出
        int damage = 0;
        damage += attackChara.status().attack();

        //--- 被ダメ処理
        mCharacters.receiveDamage(damagedIndex[i], damage);
        printf("hp %d\n", damagedChara.status().hp());
    }

    //----- アニメーション更新処理
    mCharacters.setAnimation(aIndex, Animation::Kind_Attack);
}

//---------------------------------------------------------------------
// 
//  
// 
//
bool Field::isCollision(const FieldObject& aObject) const
{
    //----- 地形との当たり判定
    if (mTerrain.isCollision(aObject)) {
        return true;
    }
    //----- キャラクターとの当たり判定
    if (mCharacters.isCollision(aObject)) {
        return true;
    }

    return false;
}

//---------------------------------------------------------------------
// 
//  
// 
//
bool Field::isGround(int aIndex)
{
    mCharacters.move(aIndex, Vector3d(0, 0, -1));
    bool result = isCollision(mCharacters.character(aIndex));
    mCharacters.move(aIndex, Vector3d(0, 0, 1));
    return result;
}

//---------------------------------------------------------------------
// 
//  
// 
//
bool Field::isJump(const Character& aChara) const
{
    //----- 空中ならジャンプできない
    if (aChara.animation().kind() == Animation::Kind_Fall) { return false; }
    if (aChara.animation().kind() == Animation::Kind_Rise) { return false; }

    //-----
    return true;
}

//---------------------------------------------------------------------
// 
//  
// 
//
bool Field::isAttack(const Character& aChara) const
{
    //----- 攻撃モーション中は攻撃できない
    if (aChara.animation().kind() == Animation::Kind_Attack) { return false; }

    //----- 空中なら攻撃できない
    if (aChara.animation().kind() == Animation::Kind_Fall) { return false; }
    if (aChara.animation().kind() == Animation::Kind_Rise) { return false; }

    //-----
    return true;
}

//---------------------------------------------------------------------
// 
//  
// 
//
std::vector<int> Field::findCharacterIndex(
    const Vector3d& aPos,
    const Vector3d& aSize) const
{
    std::vector<int> result;

    int count = mCharacters.countCharacter();
    for (int i = 0; i < count; i++) {
        const Character& chara = mCharacters.character(i);
        if (chara.isCollision(aPos, aSize)) {
            result.push_back(i);
        }
    }

    return result;
}

//---------------------------------------------------------------------
// 
//  
// 
//
const Camera& Field::camera() const
{
    return mCamera;
}
//---------------------------------------------------------------------
const Terrain& Field::terrain() const
{
    return mTerrain;
}
//---------------------------------------------------------------------
const Characters& Field::characters() const
{
    return mCharacters;
}

} // namespace game
} // namespace qwitch