//---------------------------------------------------------------------
// 
//  
// 
//
#include "SystemManager.hpp"
#include "DxLib.h"
#include "system/Input.hpp"
#include "assets/AssetsManager.hpp"
#include "system/System.hpp"

namespace qwitch {

//---------------------------------------------------------------------
// 
//  
// 
//
SystemManager::SystemManager()
    : mFpsManager()
    , mSceneManager()
{

}

//---------------------------------------------------------------------
// 
//  
// 
//
int SystemManager::run()
{
    //----- 初期処理
    if (initialize() != 0) {
        return -1;
    }

    //----- 更新処理
    while (1) {
        if (DxLib::ProcessMessage() != 0) { return -1; }
        if (DxLib::ClearDrawScreen() != 0) { return -1; }
        if (update() != 0) { return -1; }
    }

    //----- 終了処理
    return 0;
}

//---------------------------------------------------------------------
// 
//  
// 
//
int SystemManager::initialize()
{
    //----- システム初期化
    System::ins().load();
    if (DxLib::SetGraphMode(
        System::ins().windowSizeX(),
        System::ins().windowSizeY(),
        System::ins().windowDepthColor()) ||
        DxLib::SetWindowSizeChangeEnableFlag(TRUE) ||
        //DxLib::SetWindowSizeExtendRate(0.8) ||
        DxLib::ChangeWindowMode(TRUE) ||
        DxLib::SetWindowText("qwitch") ||
        DxLib::SetOutApplicationLogValidFlag(FALSE) ||
        DxLib::DxLib_Init() ||
        DxLib::SetDrawScreen(DX_SCREEN_BACK) ||
        DxLib::SetAlwaysRunFlag(TRUE)) {
        return -1;
    }

    //----- アセット読み込み
    AssetsManager::ins().load();

    //----- デバッグ処理

    return 0;
}

//---------------------------------------------------------------------
// 
//  
// 
//
int SystemManager::update()
{
    //----- FPS調整
    mFpsManager.wait();
    mFpsManager.update();

    //----- 更新処理
    Input::ins().update();
    mSceneManager.update();

    //----- 描画処理
    mSceneManager.render();
    DxLib::DrawFormatString(1150, 10, GetColor(255, 0, 0), "FPS【%lf】", mFpsManager.fps());
    DxLib::ScreenFlip();
    return 0;
}

} // namespace qwitch