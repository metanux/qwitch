//---------------------------------------------------------------------
// 
//  
// 
//
#pragma once
#include "game/Game.hpp"

namespace qwitch {
namespace game {

//---------------------------------------------------------------------
// 
//  
// 
//
class GameRender {
public:
    GameRender();
    void render(const Game& aGame) const;
private:
};

} // namespace game
} // namespace qwitch