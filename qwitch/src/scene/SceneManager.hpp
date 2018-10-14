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
    void update();   // シーン更新
    void render();   // シーン描画
    void change();   // シーン遷移
    bool isChange(); // シーン変更確認

private:
    Scene& scene();


    /// member
    std::string mSceneName;
    std::string mPrevSceneName;
    title::TitleScene mTitle;
    game::GameScene mGame;
};

} // namespace qwitch