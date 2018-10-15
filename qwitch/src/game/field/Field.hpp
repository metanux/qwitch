﻿//---------------------------------------------------------------------
// 
//  
// 
//
#pragma once
#include "game/field/terrain/Terrain.hpp"

namespace qwitch {
namespace game {

//---------------------------------------------------------------------
// 
//  
// 
//
class Field {
public:
    Field();
    void update();

    /// getter
    const Terrain& terrain() const;

private:
    /// member
    /// 地形データ
    Terrain mTerrain;
};

} // namespace game
} // namespace qwitch