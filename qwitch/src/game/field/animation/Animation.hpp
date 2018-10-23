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
    /// アニメーションの種類
    enum Kind {
        Kind_Wait,     // 待機
        Kind_Walk,     // 歩行
        Kind_Rise,     // 上昇
        Kind_Fall,     // 落下
        Kind_Attack,   // 攻撃
    };

    /// 更新処理
    Animation();

    /// 更新処理
    void update();

    ///
    void setNextKind(Kind aKind);

    /// getter
    int animeIndex() const;
    int imageIndex() const;

private:
    /// アニメーション更新処理
    void updateAnime();

    /// 変更処理
    void change(Kind aKind);

    /// 次の画像に変更
    void nextIndex();

    /// 次の画像に変更するか
    bool isNextIndex();

    /// member
    /// Kindとanime indexの対応
    int mKindToAnime[10];
    /// 現在のアニメーションの種類
    Kind mKind;
    /// 次のアニメーションの種類
    Kind mNextKind;
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