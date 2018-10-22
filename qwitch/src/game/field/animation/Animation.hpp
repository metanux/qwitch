//---------------------------------------------------------------------
// 
//  
// 
//
#pragma once

namespace qwitch {
namespace game {

//---------------------------------------------------------------------
// 
//  
// 
//
class Animation {
public:

    /// 更新処理
    Animation();

    /// 更新処理
    void update();

    /// 変更処理
    void change(int aKind);

    /// getter
    int animeIndex() const;
    int imageIndex() const;

private:
    /// 次の画像に変更
    void nextIndex();

    /// 次の画像に変更するか
    bool isNextIndex();

    /// member
    /// アニメーションのindex
    int mAnimeIndex;
    /// アニメーションのindex
    int mImageIndex;
    /// 経過フレーム
    int mFrame;
    /// アニメーションの画像枚数
    int mImageNum;
    /// アニメーションのスピード
    int mSpeed;

};

} // namespace game
} // namespace qwitch