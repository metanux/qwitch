//---------------------------------------------------------------------
// 
//  
// 
//
#pragma once
#include "game/field/camera/Camera.hpp"
#include "game/field/terrain/Terrain.hpp"
#include "game/field/character/characters.hpp"
#include "game/field/effect/DamageEffects.hpp"
#include "game/field/bullet/Bullets.hpp"

namespace qwitch {
namespace game {

//---------------------------------------------------------------------
// 
//  
// 
//
class Field {
public:
    /// コンストラクタ
    Field();

    /// 更新処理
    void update();

    /// フィールドのローディング
    void load(int aFieldIndex);

    /// プレイキャラクターの移動処理
    void playerWalk(int aX, int aY);
    /// プレイキャラクターのジャンプ処理
    void playerJump();
    /// プレイキャラクターの攻撃処理
    void playerMagic(int aMagicIndex);

    /// getter
    const Camera& camera() const;
    const Terrain& terrain() const;
    const Characters& characters() const;
    const DamageEffects& damageEffects() const;
    const Bullets& bullets() const;

private:
    /// 更新処理
    void updateCharacters();
    void updateCharacter(int aIndex);
    void updateCamera();
    void updateBullets();
    void updateBullet(int aIndex);

    /// キャラクターの移動処理
    void characterWalk(int aIndex, const Vector3d& aPos);
    void characterMove(int aIndex, const Vector3d& aPos);
    void characterMoveX(int aIndex, double aX);
    void characterMoveY(int aIndex, double aY);
    void characterMoveZ(int aIndex, double aZ);
    /// キャラクターのジャンプ処理
    void characterJump(int aIndex);
    /// キャラクターの攻撃処理
    void characterMagic(int aCharaIndex, int aMagicIndex);

    /// 当たり判定
    bool isCollision(const FieldObject& aObject) const;
    /// 接地判定
    bool isGround(int aIndex);
    /// ジャンプ可能判定[
    bool isJump(const Character& aChara) const;
    /// 魔法発動判定
    bool isMagic(const Character& aChara) const;

    /// キャラクターの検索
    /// 引数のエリアに含まれるキャラクターの一覧を配列で返却
    std::vector<int> findCharacterIndex(
        const Vector3d& aPos,
        const Vector3d& aSize) const;

    /// member
    /// カメラ
    Camera mCamera;
    /// 地形データ
    Terrain mTerrain;
    /// キャラクター
    Characters mCharacters;
    /// ダメージエフェクト
    DamageEffects mDamageEffects;
    /// 攻撃オブジェクト
    Bullets mBullets;
};

} // namespace game
} // namespace qwitch