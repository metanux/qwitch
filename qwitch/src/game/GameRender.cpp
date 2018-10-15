//---------------------------------------------------------------------
// 
//  
// 
//
#include "GameRender.hpp"
#include "DxLib.h"
#include "assets/Images.hpp"
#include "system/System.hpp"

namespace qwitch {
namespace game {

//---------------------------------------------------------------------
// 
//  
// 
//
GameRender::GameRender()
    : mFieldRender()
{
}

//---------------------------------------------------------------------
// 
//  
// 
//
void GameRender::render(const Game& aGame) const
{
    //----- 
    const Field& field = aGame.field();
    mFieldRender.render(field);
}

} // namespace game
} // namespace qwitch