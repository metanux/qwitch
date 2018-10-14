//---------------------------------------------------------------------
// 
//  FPSManager
// 
//
#pragma once
#include "DxLib.h"

namespace qwitch {

//---------------------------------------------------------------------
// 
//  
// 
//
class FpsManager {
public:
    static const int FPS = 60;

    FpsManager();
    void update();
    void wait();

    double fps() const;

private:
    static const int N = 60;   // 計測のサンプル数
    int mStartTime;
    int mCounter;
    double mFps;
};

} // namespace qwitch