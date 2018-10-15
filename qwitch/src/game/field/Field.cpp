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