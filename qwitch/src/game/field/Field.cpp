﻿//---------------------------------------------------------------------
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
const Terrain& Field::terrain() const
{
    return mTerrain;
}

} // namespace game
} // namespace qwitch