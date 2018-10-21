//---------------------------------------------------------------------
// 
//  
// 
//
#include "Field.hpp"
#include "DxLib.h"
#include "system/System.hpp"

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
void Field::playerMove(int aX, int aY)
{
    //----- プレイヤーオブジェクトの移動
    int playerIndex = 0;
    int speed = 3;
    characterMove(playerIndex, Vector3d(aX * speed, aY * speed, 0));
}

//---------------------------------------------------------------------
// 
//  
// 
//
void Field::playerJump()
{
    mCharacters.jump(0);
}

//---------------------------------------------------------------------
// 
//  
// 
//
void Field::characterMove(int aIndex, const Vector3d& aPos)
{
    /// 
    //mCharacters.move(aIndex, Vector3d(aX, aY, 0));
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