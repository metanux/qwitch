﻿//---------------------------------------------------------------------
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
void Game::update()
{
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