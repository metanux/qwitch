//---------------------------------------------------------------------
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
    /// デバッグ情報の描画
    void renderDebug(const Game& aGame) const;

    /// フィールド描画
    FieldRender mFieldRender;
};

} // namespace game
} // namespace qwitch