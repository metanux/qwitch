//---------------------------------------------------------------------
// 
//  
// 
//
#include "SceneChanger.hpp"
#include "DxLib.h"

namespace qwitch {

//---------------------------------------------------------------------
// 
//  
// 
//
SceneChanger::SceneChanger()
    : mSceneName("title")
{
}

//---------------------------------------------------------------------
// 
//  
// 
//
SceneChanger& SceneChanger::ins()
{
    static SceneChanger instance;
    return instance;
}

//---------------------------------------------------------------------
// 
//  
// 
//
void SceneChanger::setSceneName(std::string aName)
{
    mSceneName = aName;
}

//---------------------------------------------------------------------
// 
//  
// 
//
std::string SceneChanger::sceneName() const
{
    return mSceneName;
}

} // namespace qwitch