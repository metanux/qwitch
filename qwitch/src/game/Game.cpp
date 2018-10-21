//---------------------------------------------------------------------
// 
//  
// 
//
#include "Game.hpp"
#include "DxLib.h"
#include "system/Input.hpp"
#include "scene/SceneChanger.hpp"

namespace qwitch {
namespace game {

//---------------------------------------------------------------------
// 
//  
// 
//
Game::Game()
    : mField()
{
}

//---------------------------------------------------------------------
// 
//  
// 
//
void Game::initialize()
{
    mField.load(0);
}

//---------------------------------------------------------------------
// 
//  
// 
//
void Game::update()
{
    //----- 入力処理
    input();

    //----- 状態更新処理
    mField.update();
}

//---------------------------------------------------------------------
// 
//  
// 
//
void Game::input()
{
    //----- 移動処理
    int dx = 0;
    int dy = 0;
    if (Input::ins().key(KEY_INPUT_UP)) {
        dx += -1;
        dy += -1;
    }
    if (Input::ins().key(KEY_INPUT_RIGHT)) {
        dx += 1;
        dy += -1;
    }
    if (Input::ins().key(KEY_INPUT_DOWN)) {
        dx += 1;
        dy += 1;
    }
    if (Input::ins().key(KEY_INPUT_LEFT)) {
        dx += -1;
        dy += 1;
    }
    if (dx != 0 || dy != 0) {
        mField.playerMove(dx, dy);
    }

    //------ ジャンプ処理
    if (Input::ins().key(KEY_INPUT_C) == 1) {
        mField.playerJump();
    }
}

//---------------------------------------------------------------------
// 
//  
// 
//
const Field& Game::field() const
{
    return mField;
}

} // namespace game
} // namespace qwitch