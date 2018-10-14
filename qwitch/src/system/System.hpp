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
class System {
public:
    ///
    static System& ins();
    void load();

    /// getter
    int windowSizeX() const;
    int windowSizeY() const;
    int windowDepthColor() const;

private:
    /// 
    static const int DefaultWindowSizeX;
    static const int DefaultWindowSizeY;
    static const int DefaultWindowDepthColor;

    ///
    System();

    /// member
    int mWindowSizeX;
    int mWindowSizeY;
    int mWindowDepthColor;
};

} // namespace qwitch