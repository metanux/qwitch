//---------------------------------------------------------------------
// 
//  
// 
//
#include "SceneManager.hpp"
#include "system/Input.hpp"
#include "scene/SceneChanger.hpp"

namespace qwitch {

//---------------------------------------------------------------------
// 
//  
// 
//
SceneManager::SceneManager()
    : mSceneName("title")
    , mPrevSceneName("title")
    , mGame()
{
}

//---------------------------------------------------------------------
// 
//  
// 
//
void SceneManager::update()
{
    //----- シーン更新
    scene().update();

    //----- シーン変更
    if (isChange()) {
        change();
    }
}

//---------------------------------------------------------------------
// 
//  
// 
//
void SceneManager::render()
{
    //----- 各シーン
    scene().render();
}

//---------------------------------------------------------------------
// 
//  
// 
//
void SceneManager::change()
{
    mSceneName = SceneChanger::ins().sceneName();
    scene().change();
}

//---------------------------------------------------------------------
// 
//  
// 
//
bool SceneManager::isChange()
{
    if (mSceneName != SceneChanger::ins().sceneName()) {
        return true;
    }
    return false;
}

//---------------------------------------------------------------------
// 
//  
// 
//
Scene& SceneManager::scene()
{
    //----- 
    if (mSceneName == "title") { return mTitle; }
    if (mSceneName == "game") { return mGame; }
    return mGame;
}
//---------------------------------------------------------------------


} // namespace qwitch