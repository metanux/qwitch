//---------------------------------------------------------------------
// 
//  
// 
//
#include "Field.hpp"
#include "DxLib.h"

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
}

//---------------------------------------------------------------------
// 
//  
// 
//
void Field::playerMove(int aX, int aY)
{
    int playerIndex = 0;
    mCharacters.move(playerIndex, Vector3d(aX, aY, 0));
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