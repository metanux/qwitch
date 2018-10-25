﻿//---------------------------------------------------------------------
// 
//  
// 
//
#pragma once
#include "game/Game.hpp"
#include "game/field/FieldRender.hpp"
#include "game/ui/UIRender.hpp"

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
    /// デバッグ情報の描画
    void renderDebug(const Game& aGame) const;

    /// フィールド描画
    FieldRender mFieldRender;
    /// UIの描画
    UIRender mUIRender;
};

} // namespace game
} // namespace qwitch