﻿//---------------------------------------------------------------------
// 
//  
// 
//
#pragma once
#include "game/Game.hpp"
#include "game/field/FieldRender.hpp"

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
    FieldRender mFieldRender;
};

} // namespace game
} // namespace qwitch