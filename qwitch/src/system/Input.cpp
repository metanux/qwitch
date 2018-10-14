//--------------------------------------------------------------------
//
//  
//
#include "Input.hpp"

namespace qwitch {

//--------------------------------------------------------------------
//
//  
//
Input::Input()
    : mKey()
    , mPointX()
    , mPointY()
    , mClick()
    , mPreClick()
    , mWheel()
{
}


//--------------------------------------------------------------------
//
//  インスタンス取得
//
Input& Input::ins()
{
    static Input instance;
    return instance;
}

//--------------------------------------------------------------------
//
//  
//

//--------------------------------------------------------------------
//
//  
//
void Input::update()
{
    keyUpdate();
    mouseUpdate();
}

//--------------------------------------------------------------------
//
//  
//
void Input::keyUpdate()
{
    char tmp_key[KEY_MAX];

    GetHitKeyStateAll(tmp_key);
    for (int i = 0; i < KEY_MAX; i++) {
        mKey[i] = (tmp_key[i]) ? mKey[i] + 1 : 0;
    }
}

//--------------------------------------------------------------------
//
//  
//
void Input::mouseUpdate()
{
    // マウスホイール
    mWheel = GetMouseWheelRotVol();

    // マウスの座標
    if (GetMousePoint(&mPointX, &mPointY) == -1) {
        return;
    }
    // 前フレームのクリック状態
    for (int i = 0; i < CLICK_MAX; i++) {
        mPreClick[i] = mClick[i];
    }
    // マウスのクリック状態
    int MouseInput = GetMouseInput();
    for (int i = 0; i < CLICK_MAX; i++) {
        mClick[i] = (MouseInput & 1 << i) ? mClick[i] + 1 : 0;
    }
}

//--------------------------------------------------------------------
//
//  
//
int Input::key(int n) const { return mKey[n]; }
int Input::mouseWheel() const { return mWheel; }
int Input::pointX() const { return mPointX; }
int Input::pointY() const { return mPointY; }
int Input::click(int n) const { return mClick[n - 1]; }
int Input::leftClick() const { return click(MOUSE_INPUT_LEFT); }
int Input::rightClick() const { return click(MOUSE_INPUT_RIGHT); }
int Input::preClick(int n) const { return mPreClick[n - 1]; }
bool Input::isRereaseClick(int n) const { return (mClick[n - 1] == 0 && mPreClick[n - 1] >= 1); }

} // namespace qwitch