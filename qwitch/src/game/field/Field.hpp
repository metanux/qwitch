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
    void updateCharacters();
    void updateCharacter(int aIndex);
    void updateCamera();

    /// フィールドのローディング
    void load(int aFieldIndex);

    /// プレイキャラクターの移動処理
    void playerWalk(int aX, int aY);
    /// プレイキャラクターのジャンプ処理
    void playerJump();

    /// getter
    const Camera& camera() const;
    const Terrain& terrain() const;
    const Characters& characters() const;

private:
    /// 
    /// キャラクターの移動処理
    void characterMove(int aIndex, const Vector3d& aPos);
    void characterMoveX(int aIndex, double aX);
    void characterMoveY(int aIndex, double aY);
    void characterMoveZ(int aIndex, double aZ);

    /// 当たり判定
    bool isCollision(const FieldObject& aObject) const;

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