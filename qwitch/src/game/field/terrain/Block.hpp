//---------------------------------------------------------------------
// 
//  
// 
//
#pragma once
#include "game/field/object/FieldObject.hpp"

namespace qwitch {
namespace game {

//---------------------------------------------------------------------
// 
//  
// 
//
class Block : public FieldObject {
public:
    /// 1ブロックのピクセルサイズ
    static const int PIXEL_SIZE;

    /// コンストラクタ
    Block();
    /// 更新処理
    void update();

    /// setter
    void setKind(int aKind);
    void setGroup(
        int aId,
        const Vector3d& aPos,
        const Vector3d& aSize);

    /// getter
    int groupId() const;
    const Vector3d& groupPos() const;
    const Vector3d& groupSize() const;

private:
    /// member
    int mKind;
    /// グループID
    int mGroupId;
    ///
    Vector3d mGroupPos;
    ///
    Vector3d mGroupSize;
};

} // namespace game
} // namespace qwitch