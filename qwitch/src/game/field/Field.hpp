//---------------------------------------------------------------------
// 
//  
// 
//
#pragma once
#include "game/field/camera/Camera.hpp"
#include "game/field/terrain/Terrain.hpp"
#include "game/field/character/characters.hpp"

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
    const Camera& camera() const;
    const Terrain& terrain() const;
    const Characters& characters() const;

private:
    /// member
    /// 地形データ
    Camera mCamera;
    Terrain mTerrain;
    Characters mCharacters;
};

} // namespace game
} // namespace qwitch