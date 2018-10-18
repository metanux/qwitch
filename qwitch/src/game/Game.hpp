//---------------------------------------------------------------------
// 
//  
// 
//
#pragma once
#include "game/field/Field.hpp"

namespace qwitch {
namespace game {

//---------------------------------------------------------------------
// 
//  
// 
//
class Game {
public:
    Game();
    void initialize();
    void update();

    /// getter
    const Field& field() const;

private:
    /// member
    Field mField;
};

} // namespace game
} // namespace qwitch