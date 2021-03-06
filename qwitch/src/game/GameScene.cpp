﻿//---------------------------------------------------------------------
// 
//  
// 
//
#include "GameScene.hpp"

namespace qwitch {
namespace game {

//---------------------------------------------------------------------
// 
//  
// 
//
GameScene::GameScene()
    : mGame()
    , mGameRender()
{
}

//---------------------------------------------------------------------
// 
//  
// 
//
void GameScene::init()
{

}

//---------------------------------------------------------------------
// 
//  
// 
//
void GameScene::update()
{
    mGame.update();
}

//---------------------------------------------------------------------
// 
//  
// 
//
void GameScene::render() const
{
    mGameRender.render(mGame);
}

//---------------------------------------------------------------------
// 
//  
// 
//
void GameScene::change()
{
    mGame.initialize();
}

//---------------------------------------------------------------------

} // namespace battle
} // namespace qwitch