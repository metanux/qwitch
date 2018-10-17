//---------------------------------------------------------------------
// 
//  
// 
//
#pragma once
#include "game/field/character/Character.hpp"
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

    /// getter
    const Character& character(int aIndex) const;
    const Character& player() const;

private:
    std::vector<Character> mCharacters;
};

} // namespace game
} // namespace qwitch