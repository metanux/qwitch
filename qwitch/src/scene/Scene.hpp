//---------------------------------------------------------------------
// 
//  
// 
//
#pragma once

namespace qwitch {

//---------------------------------------------------------------------
// 
//  
// 
//
class Scene {
public:
    Scene();
    virtual void init() = 0;         // シーン開始時
    virtual void update() = 0;
    virtual void render() const = 0;
    virtual void change() = 0;
private:
};

} // namespace qwitch