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
class UIRender {
public:
    /// コンストラクタ
    UIRender();
    /// 描画
    void render(const Game& aGame) const;
private:
    void renderHPGage(const Status& aStatus) const;
    void renderMPGage(const Status& aStatus) const;
};

} // namespace game
} // namespace qwitch