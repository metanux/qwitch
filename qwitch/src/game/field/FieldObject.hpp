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

    /// 移動
    void move(const Vector3d& aPos);

    /// @name setter
    //@{
    void setPos(const Vector3d& aPos);
    void setSize(const Vector3d& aSize);
    //@}

    /// @name getter
    //@{
    const Vector3d& pos() const;
    const Vector3d& size() const;
    //@}

private:
    /// member
    /// オブジェクトの現在座標
    Vector3d mPos;
    /// オブジェクトの大きさ
    Vector3d mSize;
};

} // namespace game
} // namespace qwitch