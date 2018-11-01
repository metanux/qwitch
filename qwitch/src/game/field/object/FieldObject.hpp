//---------------------------------------------------------------------
// 
//  
// 
//
#pragma once
#include "util/Vector3d.hpp"
#include "game/field/animation/Animation.hpp"
#include "game/field/object/ObjectImage.hpp"
#include <unordered_map>

namespace qwitch {
namespace game {

//---------------------------------------------------------------------
// 
//  
// 
//
class FieldObject {
public:
    /// 向き
    enum Direction {
        Direction_Down,
        Direction_LeftDown,
        Direction_Left,
        Direction_LeftUp,
        Direction_Up,
        Direction_RightUp,
        Direction_Right,
        Direction_RightDown,
    };

    /// 敵対関係
    enum Relation {
        Relation_Neutral,  // 中立
        Relation_Enemy,    // 敵
        Relation_Friend,   // 味方
    };

    /// コンストラクタ
    FieldObject();

    /// 更新処理
    void update();

    /// 当たり判定
    bool isCollision(const FieldObject& aObject) const;
    bool isCollision(
        const Vector3d& aPos,
        const Vector3d& aSize) const;
    /// 同じオブジェクトか判定
    bool isEqual(const FieldObject& aObject) const;
    /// 敵オブジェクトか判定
    bool isEnemy(const FieldObject& aObject) const;
    /// オブジェクトが移動したか
    bool isMoved() const;
    /// 2オブジェクト間の順序関係を判定
    /// 自分を先に描画：true
    /// 引数のオブジェクトを先に描画：false
    bool isPreRender(
        const FieldObject& aObject) const;

    /// 座標を移動
    void move(const Vector3d& aPos);

    /// 力を加える
    void addForce(const Vector3d& aForce);

    /// field座標をwindow座標に変換
    double convertWindowPosX() const;
    double convertWindowPosY() const;

    /// 画像追加
    void addImage(int aHandl);
    void addImage(
        int aHandl,
        const Vector3d& aPos,
        const Vector3d& aSize);
    /// 画像の設定
    void setImageHandl(
        int aIndex,
        int aHandl);
    /// 画像の位置設定
    void setImagePos(
        int aIndex,
        const Vector3d& aPos);
    /// 画像のサイズ設定
    void setImageSize(
        int aIndex,
        const Vector3d& aSize);

    /// アニメーションの変更
    void setAnimation(Animation::Kind aKind);

    /// @name setter
    //@{
    void setPos(const Vector3d& aPos);
    void setSize(const Vector3d& aSize);
    void setForce(const Vector3d& aForce);
    void setForceX(double aX);
    void setForceY(double aY);
    void setForceZ(double aZ);
    void setKind(int aKind);
    void setDirection(int aX, int aY, int aZ);
    void setDirection(Direction aDirection);
    void setRelation(Relation aRelation);
    void setAnimeSpeed(int aSpeed);
    void setImmutableOrder(int aObjectId, int aValue);
    void setDynamicOrder(int aObjectId, int aValue);
    //@}

    /// @name getter
    //@{
    /// 描画に使用する画像ハンドルを返却
    int id() const;
    const Vector3d& pos() const;
    const Vector3d& size() const;
    const Vector3d& force() const;
    int kind() const;
    const std::vector<ObjectImage>& images() const;
    Direction direction() const;
    int directionX() const;
    int directionY() const;
    const Animation& animation() const;
    Relation relation() const;
    int order(int aObjectId) const;
    //@}

private:
    /// member
    /// 固有ID
    int mId;
    /// オブジェクトの現在座標
    Vector3d mPos;
    /// オブジェクトの大きさ
    Vector3d mSize;
    /// オブジェクトに加わる力
    Vector3d mForce;
    /// 種類
    int mKind;
    /// 画像
    std::vector<ObjectImage> mImages;
    /// 向き
    Direction mDirection;
    /// アニメーション
    Animation mAnimation;
    /// 敵対関係
    Relation mRelation;
    /// 順序関係が不変のオブジェクトとの順序関係
    std::unordered_map<int,int> mImmutableOrder;
    /// 順序関係が動的なオブジェクトとの順序関係
    std::unordered_map<int, int> mDynamicOrder;
    /// 移動フラグ
    /// 1フレーム内にオブジェクトの移動が行われたか
    /// true: 移動した
    bool mMovedFlag;
};

} // namespace game
} // namespace qwitch