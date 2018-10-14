//---------------------------------------------------------------------
// 
//  
// 
//
#pragma once
#include "scene/Scene.hpp"
#include "game/Game.hpp"
#include "game/GameRender.hpp"

namespace qwitch {
namespace game {

//---------------------------------------------------------------------
// 
//  
// 
//
class GameScene : public Scene {
public:
    GameScene();
    void init();
    void update();
    void render() const;
    void change();

private:
    Game mGame;
    GameRender mGameRender;
};

} // namespace game
} // namespace qwitch