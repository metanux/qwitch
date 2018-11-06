//---------------------------------------------------------------------
// 
//  
// 
//
#include "System.hpp"
#include "DxLib.h"

namespace qwitch {

//---------------------------------------------------------------------
// 
//  
// 
//
const int System::DefaultWindowSizeX = 1280;
const int System::DefaultWindowSizeY = 720;
//const int System::DefaultWindowSizeX = 960;
//const int System::DefaultWindowSizeY = 540;
const int System::DefaultWindowDepthColor = 32;

//---------------------------------------------------------------------
// 
//  
// 
//
System::System()
    : mWindowSizeX(DefaultWindowSizeX)
    , mWindowSizeY(DefaultWindowSizeY)
    , mWindowDepthColor(DefaultWindowDepthColor)
{
}

//---------------------------------------------------------------------
// 
//  
// 
//
System& System::ins()
{
    static System instance;
    return instance;
}

//---------------------------------------------------------------------
// 
//  
// 
//
void System::load()
{
    /// システム設定の読込み
    //mWindowSizeX = 960;
    //mWindowSizeY = 540;
}

//---------------------------------------------------------------------
// 
//  
// 
//
int System::windowSizeX() const
{
    return mWindowSizeX;
}
//---------------------------------------------------------------------
int System::windowSizeY() const
{
    return mWindowSizeY;
}
//---------------------------------------------------------------------
int System::windowDepthColor() const
{
    return mWindowDepthColor;
}
//---------------------------------------------------------------------

} // namespace qwitch