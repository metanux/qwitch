//---------------------------------------------------------------------
// 
//  
// 
//
#pragma once
#include "DxLib.h"
#include "system/FpsManager.hpp"
#include "scene/SceneManager.hpp"

namespace qwitch {

//---------------------------------------------------------------------
// 
//  
// 
//
class SystemManager {
public:
    SystemManager();
    int run();            // ゲームを実行します。
private:
    int initialize();     // ゲーム情報を初期化します。
    int update();         // ゲーム情報を更新します。

    FpsManager mFpsManager;
    SceneManager mSceneManager;
};

} // namespace qwitch