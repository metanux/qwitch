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
class ObjectImage {
public:
    /// コンストラクタ
    ObjectImage();

    /// 座標の変換
    double convertWindowPosX() const;
    double convertWindowPosY() const;

    /// setter
    void setHandl(int aHandl);
    void setPos(double aX, double aY, double aZ);
    void setPos(const Vector3d& aPos);
    void setSize(double aX, double aY, double aZ);
    void setSize(const Vector3d& aSize);

    /// getter
    int handl() const;
    const Vector3d& pos() const;
    const Vector3d& size() const;

private:
    /// member
    /// 画像ハンドル
    int mHandl;
    /// 表示位置
    Vector3d mPos;
    /// 表示大きさ
    Vector3d mSize;
};

} // namespace game
} // namespace qwitch