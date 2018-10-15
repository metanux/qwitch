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

    /// getter
    const Character& character(int aIndex) const;

private:
    std::vector<Character> mCharacters;
};

} // namespace game
} // namespace qwitch