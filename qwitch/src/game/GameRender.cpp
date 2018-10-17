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
    //----- フィールドの描画
    const Field& field = aGame.field();
    mFieldRender.render(field);

    //----- デバッグ情報の描画
    renderDebug(aGame);
}

//---------------------------------------------------------------------
// 
//  
// 
//
void GameRender::renderDebug(const Game& aGame) const
{
    // カメラ座標
    const Camera& camera = aGame.field().camera();
    DxLib::DrawFormatString(
        0,
        30,
        GetColor(255, 0, 0),
        "camera (x:%d, y:%d, z:%d)",
        (int)camera.fieldPos().x(),
        (int)camera.fieldPos().y(),
        (int)camera.fieldPos().z()
    );
    // プレイヤー座標
    const Character& player = aGame.field().characters().player();
    DxLib::DrawFormatString(
        0,
        45,
        GetColor(255, 0, 0),
        "playerPos (x:%d, y:%d, z:%d)",
        (int)player.pos().x(),
        (int)player.pos().y(),
        (int)player.pos().z()
    );
}

} // namespace game
} // namespace qwitch