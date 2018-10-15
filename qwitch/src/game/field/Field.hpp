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

    ///
    void playerMove(int aX, int aY);

    /// getter
    const Camera& camera() const;
    const Terrain& terrain() const;
    const Characters& characters() const;

private:
    /// member
    /// カメラ
    Camera mCamera;
    /// 地形データ
    Terrain mTerrain;
    /// キャラクター
    Characters mCharacters;
};

} // namespace game
} // namespace qwitch