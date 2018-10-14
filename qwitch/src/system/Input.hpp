//--------------------------------------------------------------------
//
//  Input.h
//
//
#pragma once
#include "DxLib.h"

namespace qwitch {

//--------------------------------------------------------------------
//
//  
//
//
class Input
{
public:
    static const int KEY_MAX = 256;
    static const int CLICK_MAX = 8;

public:
    static Input& ins();
    void update();

    int key(int) const;
    int mouseWheel() const;        // マウスホイール回転量取得
    int pointX() const;            // 座標xを取得
    int pointY() const;            // 座標yを取得
    int click(int) const;          // クリック情報取得
    int leftClick() const;
    int rightClick() const;
    int preClick(int) const;        // 前フレームクリック情報取得
    bool isRereaseClick(int) const; // 指定クリックが離されたか

private:
    Input();

    int mKey[KEY_MAX];             // キー入力状態
    int mPointX;                   // マウスの座標x
    int mPointY;                   // マウスの座標y
    int mClick[CLICK_MAX];         // クリック情報
    int mPreClick[CLICK_MAX];      // 前フレームのクリック情報
    int mWheel;                    // マウス回転量

    void keyUpdate();              // キー入力状態更新
    void mouseUpdate();            // マウス入力状態更新
};

} // namespace qwitch