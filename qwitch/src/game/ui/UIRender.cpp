//---------------------------------------------------------------------
// 
//  
// 
//
#include "UIRender.hpp"
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
UIRender::UIRender()
{
}

//---------------------------------------------------------------------
// 
//  
// 
//
void UIRender::render(const Game& aGame) const
{
    //----- HPゲージ
    const Status& status = aGame.field().characters().player().status();
    renderHPGage(status);

    //----- MPゲージ
    renderMPGage(status);
}

//---------------------------------------------------------------------
// 
//  
// 
//
void UIRender::renderHPGage(const Status& aStatus) const
{
    int sx = 100;
    int sy = 10;
    int x1 = System::ins().windowSizeX() / 2 - sx / 2;
    int y1 = 500;
    int x2 = x1 + sx;
    int y2 = y1 + sy;
    double rate = aStatus.hpRate();
    int x3 = x1 + (int)(sx * rate);
    int y3 = y1 + sy;
    DxLib::DrawBox(x1, y1, x2, y2, DxLib::GetColor(30, 30, 30), TRUE);
    DxLib::DrawBox(x1, y1, x3, y3, DxLib::GetColor(255, 0, 0), TRUE);
    DxLib::DrawBox(x1, y1, x2, y2, DxLib::GetColor(0, 0, 0), FALSE);
}

//---------------------------------------------------------------------
// 
//  
// 
//
void UIRender::renderMPGage(const Status& aStatus) const
{
    int sx = 100;
    int sy = 10;
    int x1 = System::ins().windowSizeX() / 2 - sx / 2;
    int y1 = 515;
    int x2 = x1 + sx;
    int y2 = y1 + sy;
    double rate = aStatus.mpRate();
    int x3 = x1 + (int)(sx * rate);
    int y3 = y1 + sy;
    DxLib::DrawBox(x1, y1, x2, y2, DxLib::GetColor(30, 30, 30), TRUE);
    DxLib::DrawBox(x1, y1, x3, y3, DxLib::GetColor(120, 225, 255), TRUE);
    DxLib::DrawBox(x1, y1, x2, y2, DxLib::GetColor(0, 0, 0), FALSE);
}

} // namespace game
} // namespace qwitch