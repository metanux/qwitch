//---------------------------------------------------------------------
/// @file
/// @author 
///
//
#include "DxLib.h"
#include "system/SystemManager.hpp"

//---------------------------------------------------------------------
// 
//  
// 
//
int WINAPI WinMain(
    HINSTANCE hInstance,
    HINSTANCE hPrevInstance,
    LPSTR lpCmdLine,
    int nCmdShow)
{
    //----- デバッグ用コンソール
    /*
    AllocConsole();
    FILE* fp;
    freopen_s(&fp, "CONOUT$", "w", stdout);
    freopen_s(&fp, "CONIN$", "r", stdin);
    */

    //----- ゲーム処理
    qwitch::SystemManager systemManager;
    systemManager.run();

    //----- 終了処理
    DxLib::DxLib_End();
    return false;
}