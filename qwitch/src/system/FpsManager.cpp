//---------------------------------------------------------------------
// 
//  
// 
//
#include "FpsManager.hpp"

namespace qwitch {

//---------------------------------------------------------------------
// 
//  
// 
//
FpsManager::FpsManager()
    : mStartTime(0)
    , mCounter(0)
    , mFps(0)
{
}

//---------------------------------------------------------------------
// 
//  
// 
//
void FpsManager::update()
{
    if (mCounter == 0) {
        mStartTime = DxLib::GetNowCount();
    }
    if (mCounter == N) {
        int t = DxLib::GetNowCount();
        mFps = 1000.f / ((t - mStartTime) / (double)N);
        mCounter = 0;
        mStartTime = t;
    }
    mCounter++;
}

//---------------------------------------------------------------------
// 
//  
// 
//
void FpsManager::wait() {
    int tookTime = DxLib::GetNowCount() - mStartTime;
    int waitTime = mCounter * 1000 / FPS - tookTime;
    if (waitTime > 0) {
        Sleep(waitTime);
    }
}

//---------------------------------------------------------------------
// 
//  
// 
//
double FpsManager::fps() const
{
    return mFps;
}

} // namespace qwitch