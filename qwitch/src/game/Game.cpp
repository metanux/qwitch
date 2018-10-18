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
    if (Input::ins().key(KEY_INPUT_UP)) {
        mField.playerMove(-1, -1);
    }
    if (Input::ins().key(KEY_INPUT_RIGHT)) {
        mField.playerMove(1, -1);
    }
    if (Input::ins().key(KEY_INPUT_DOWN)) {
        mField.playerMove(1, 1);
    }
    if (Input::ins().key(KEY_INPUT_LEFT)) {
        mField.playerMove(-1, 1);
    }
    if (Input::ins().key(KEY_INPUT_C) == 1) {
        mField.playerJump();
    }

    //----- 状態更新処理
    mField.update();
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