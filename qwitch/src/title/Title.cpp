//---------------------------------------------------------------------
// 
//  
// 
//
#include "Title.hpp"
#include "DxLib.h"
#include "system/Input.hpp"
#include "scene/SceneChanger.hpp"

namespace qwitch {
namespace title {

//---------------------------------------------------------------------
// 
//  
// 
//
Title::Title()
{
}

//---------------------------------------------------------------------
// 
//  
// 
//
void Title::update()
{
    if (Input::ins().key(KEY_INPUT_Z) == 1) {
        SceneChanger::ins().setSceneName("game");
    }
}

} // namespace title
} // namespace qwitch