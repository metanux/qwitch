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

    /// 移動
    void move(int aIndex, const Vector3d& aPos);

    /// キャラクター数
    int countCharacter() const;

    /// getter
    const Character& character(int aIndex) const;

private:
    std::vector<Character> mCharacters;
};

} // namespace game
} // namespace qwitch