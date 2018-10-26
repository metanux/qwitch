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
    , mDamageEffects()
    , mBullets()
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
    updateCharacters();

    //----- カメラの更新
    updateCamera();

    //----- 表示地形の更新
    mTerrain.update(mCamera);

    //----- エフェクトの更新
    mDamageEffects.update();

    //----- 攻撃オブジェクトの更新
    updateBullets();
}

//---------------------------------------------------------------------
// 
//  
// 
//
void Field::updateCharacters()
{
    mCharacters.update(mCamera);

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

    //----- 摩擦
    if (isGround(aIndex)) {
        double friction = 0.20;
        double fx = chara.force().x();
        double fy = chara.force().y();
        double dx = (fx >= 0) ? friction * -1 : friction;
        double dy = (fy >= 0) ? friction * -1 : friction;
        /*
        if ((fx >= 0) && ((fx + dx) < 0)) { dx = 0; }
        else if ((fx < 0) && ((fx + dx) >= 0)) { dx = 0; }
        if ((fy >= 0) && ((fy + dy) < 0)) { dy = 0; }
        else if ((fy < 0) && ((fy + dy) >= 0)) { dy = 0; }
        */
        mCharacters.addForce(aIndex, Vector3d(dx, dy, 0));
    }

    //----- 外力更新
    double forceX = chara.force().x();
    double forceY = chara.force().y();
    double forceZ = chara.force().z();
    printf("%lf %lf %lf\n", forceX, forceY, forceZ);
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

    //----- 魔法発動
    if (chara.animation().kind() == Animation::Kind_Magic) {
        int magicIndex = chara.magicIndex();
        const Magic& magic = chara.activeMagic(magicIndex);
        mBullets.add(
            chara.pos(),
            chara.direction(),
            chara.relation(),
            magic.attack(),
            0);
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
void Field::updateBullets()
{
    //------ 状態の更新
    mBullets.update();
    int n = mBullets.count();
    for (int i = n - 1; i >= 0; i--) {
        updateBullet(i);
    }
    //----- 削除処理
    n = mBullets.count();
    for (int i = n - 1; i >= 0; i--) {
        const Bullet& bullet = mBullets.bullet(i);
        if (bullet.isDelete()) {
            mBullets.del(i);
        }
    }
}

//---------------------------------------------------------------------
// 
//  
// 
//
void Field::updateBullet(int aIndex)
{
    //-----
    const Bullet& bullet = mBullets.bullet(aIndex);
    bool deleteFlag = false;

    //----- 当たり判定
    std::vector<int> index = findCharacterIndex(bullet.pos(), bullet.size());
    int count = (int)index.size();
    for (int i = 0; i < count; i++) {
        const Character& damagedChara = mCharacters.character(index[0]);
        if (damagedChara.isEnemy(bullet) == false) { continue; }
        // ダメージ処理
        int damage = 0;
        damage += bullet.attackPower();
        mCharacters.receiveDamage(index[i], damage);
        // ダメージエフェクト表示
        int x = (int)damagedChara.convertWindowPosX();
        int y = (int)damagedChara.convertWindowPosY();
        mDamageEffects.add(damage, x, y);
        // 
        deleteFlag = true;
    }

    // 攻撃オブジェクトの削除
    if (deleteFlag) {
        mBullets.del(aIndex);
    }
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
    characterWalk(FieldParameter::PlayerIndex, aX, aY);
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
void Field::playerMagic(int aMagicIndex)
{
    characterMagic(FieldParameter::PlayerIndex, aMagicIndex);
}

//---------------------------------------------------------------------
// 
//  
// 
//
void Field::characterWalk(int aIndex, int aX, int aY)
{
    //----- キャラクター
    const Character& chara = mCharacters.character(aIndex);

    //----- 移動可能判定
    if (isWalk(chara) == false) {
        return;
    }

    //----- 移動速度設定
    double x = aX;
    double y = aY;
    if (aX >= 2) { x = 1.5; }
    if (aX <= -2) { x = -1.5; }
    if (aY >= 2) { y = 1.5; }
    if (aY <= -2) { y = -1.5; }
    double accel = 0.4;
    double dx = x * accel;
    double dy = y * accel;
    double speedMax = 3;
    double speedMaxX = speedMax * x;
    double speedMaxY = speedMax * y;
    speedMaxX = (speedMaxX >= 0) ? speedMaxX : speedMaxX * -1;
    speedMaxY = (speedMaxY >= 0) ? speedMaxY : speedMaxY * -1;
    double fx = chara.force().x() + dx;
    double fy = chara.force().y() + dy;
    fx = (fx < 0) ? fx * -1 : fx;
    fy = (fy < 0) ? fy * -1 : fy;
    if (fx >= speedMaxX) { dx = 0; }
    if (fy >= speedMaxY) { dy = 0; }
    if ((fx + fy) >= (speedMaxX + speedMaxY)) {
        dx = 0;
        dy = 0;
    }
    mCharacters.addForce(FieldParameter::PlayerIndex, Vector3d(dx, dy, 0));

    //----- プレイヤーオブジェクトの移動
    //characterMove(aIndex, Vector3d(dx, dy, dz));

    //----- 向きの更新
    mCharacters.setDirection(aIndex, aX, aY, 0);

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
void Field::characterMagic(int aCharaIndex, int aMagicIndex)
{
    //-----
    const Character& chara = mCharacters.character(aCharaIndex);
    const Magic& magic = chara.activeMagic(aMagicIndex);

    //----- 魔法発動判定
    if (isMagic(chara) == false) {
        return;
    }

    //----- 魔法設定
    mCharacters.setMagicIndex(aCharaIndex, aMagicIndex);

    //----- MP消費
    int mp = magic.mp();
    mCharacters.reduceMp(aCharaIndex, mp);

    //----- アニメーション更新処理
    mCharacters.setAnimation(aCharaIndex, Animation::Kind_MagicPrev);

    //----- 
    int speed = magic.cast();
    mCharacters.setAnimeSpeed(aCharaIndex, speed);
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
bool Field::isWalk(const Character& aChara) const
{
    //----- 攻撃モーション中は移動できない
    if (aChara.animation().kind() == Animation::Kind_MagicPrev) { return false; }
    if (aChara.animation().kind() == Animation::Kind_Magic) { return false; }
    if (aChara.animation().kind() == Animation::Kind_MagicPost) { return false; }

    return true;
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
bool Field::isMagic(const Character& aChara) const
{
    //----- 攻撃モーション中は攻撃できない
    if (aChara.animation().kind() == Animation::Kind_MagicPrev) { return false; }
    if (aChara.animation().kind() == Animation::Kind_Magic) { return false; }
    if (aChara.animation().kind() == Animation::Kind_MagicPost) { return false; }

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
//---------------------------------------------------------------------
const DamageEffects& Field::damageEffects() const
{
    return mDamageEffects;
}
//---------------------------------------------------------------------
const Bullets& Field::bullets() const
{
    return mBullets;
}

} // namespace game
} // namespace qwitch