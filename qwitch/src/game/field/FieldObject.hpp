//---------------------------------------------------------------------
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
    FieldObject();

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
    //@}

    /// @name getter
    //@{
    const Vector3d& pos() const;
    const Vector3d& size() const;
    const Vector3d& force() const;
    //@}

private:
    /// member
    /// オブジェクトの現在座標
    Vector3d mPos;
    /// オブジェクトの大きさ
    Vector3d mSize;
    /// オブジェクトに加わる力
    Vector3d mForce;
};

} // namespace game
} // namespace qwitch