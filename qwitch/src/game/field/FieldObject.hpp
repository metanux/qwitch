﻿//---------------------------------------------------------------------
// 
//  
// 
//
#pragma once
#include "util/Vector3d.hpp"

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
        Direction_Right_Up,
        Direction_Right,
        Direction_Right_Down,
    };

    /// コンストラクタ
    FieldObject();

    /// 当たり判定
    bool isCollision(const FieldObject& aObject) const;

    /// 同じオブジェクトか判定
    bool isEqual(const FieldObject& aObject) const;

    /// 描画に使用する画像ハンドルを返却
    virtual int image() const = 0;

    /// 座標を移動
    void move(const Vector3d& aPos);

    /// 力を加える
    void addForce(const Vector3d& aForce);

    /// field座標をwindow座標に変換
    double convertWindowPosX() const;
    double convertWindowPosY() const;

    /// @name setter
    //@{
    void setPos(const Vector3d& aPos);
    void setSize(const Vector3d& aSize);
    void setForce(const Vector3d& aForce);
    void setForceX(double aX);
    void setForceY(double aY);
    void setForceZ(double aZ);
    void setKind(int aKind);
    //@}

    /// @name getter
    //@{
    int id() const;
    const Vector3d& pos() const;
    const Vector3d& size() const;
    const Vector3d& force() const;
    int kind() const;
    int animeKind() const;
    Direction direction() const;
    int animeIndex() const;
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
    /// アニメーションの種類
    int mAnimeKind;
    /// 向き
    Direction mDirection;
    /// アニメーションのindex
    int mAnimeIndex;

};

} // namespace game
} // namespace qwitch