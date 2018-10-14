//---------------------------------------------------------------------
// 
//  
// 
//
#pragma once
#include "scene/Scene.hpp"
#include "title/Title.hpp"
#include "title/TitleRender.hpp"

namespace qwitch {
namespace title {

//---------------------------------------------------------------------
// 
//  
// 
//
class TitleScene : public Scene {
public:
    TitleScene();
    void init();
    void update();
    void render() const;
    void change();

private:
    Title mTitle;
    TitleRender mTitleRender;
};

} // namespace title
} // namespace qwitch