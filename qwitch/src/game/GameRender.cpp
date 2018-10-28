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
    , mUIRender()
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

    //----- UIの描画
    mUIRender.render(aGame);

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
    // 表示オブジェクト数
    int objectNum = aGame.field().terrain().countBlock();
    objectNum += aGame.field().characters().countDisplayCharacter();
    objectNum += aGame.field().bullets().count();
    DxLib::DrawFormatString(
        0,
        15,
        GetColor(255, 0, 0),
        "objects (%d)",
        objectNum
    );
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
        "player (x:%d, y:%d, z:%d)",
        (int)player.pos().x(),
        (int)player.pos().y(),
        (int)player.pos().z()
    );
}

} // namespace game
} // namespace qwitch