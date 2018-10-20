//---------------------------------------------------------------------
// 
//  
// 
//
#pragma once
#include <string>
#include "scene/Scene.hpp"
#include "title/TitleScene.hpp"
#include "game/GameScene.hpp"

namespace qwitch {

//---------------------------------------------------------------------
// 
//  
// 
//
class SceneManager {
public:
    SceneManager();

    /// シーンの更新処理
    /// 毎フレーム呼び出される
    void update();

    /// シーンの描画処理
    /// 毎フレーム update後に呼び出される
    void render();

    /// シーン変更時の処理
    /// シーンの開始時に呼出される
    void change();

    /// シーン変更確認
    /// true: シーン変更
    bool isChange();

private:
    Scene& scene();


    /// member
    std::string mSceneName;
    std::string mPrevSceneName;
    title::TitleScene mTitle;
    game::GameScene mGame;
};

} // namespace qwitch