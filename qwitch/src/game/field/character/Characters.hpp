//---------------------------------------------------------------------
// 
//  
// 
//
#pragma once
#include "game/field/character/Character.hpp"
#include "game/field/camera/Camera.hpp"
#include <vector>

namespace qwitch {
namespace game {

//---------------------------------------------------------------------
// 
//  
// 
//
class Characters {
public:
    Characters();

    /// 更新処理
    void update(const Camera& aCamera);

    /// 当たり判定
    bool isCollision(const FieldObject& aObject) const;

    /// @name 移動
    void move(int aIndex, const Vector3d& aPos);

    /// ジャンプ
    void jump(int aIndex);

    ///
    void addForce(int aIndex, const Vector3d& aForce);

    /// @ name 
    void setForceX(int aIndex, double aX);
    void setForceY(int aIndex, double aY);
    void setForceZ(int aIndex, double aZ);

    /// キャラクター数
    int countCharacter() const;
    int countDisplayCharacter() const;

    /// getter
    const Character& character(int aIndex) const;
    const Character& player() const;
    const Character& displayCharacter(int aIndex) const;

private:
    /// キャラクター
    std::vector<Character> mCharacters;
    /// 描画キャラクター
    std::vector<std::reference_wrapper<const Character>> mDisplayCharacters;
};

} // namespace game
} // namespace qwitch