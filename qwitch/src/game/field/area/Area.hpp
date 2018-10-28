//---------------------------------------------------------------------
// 
//  
// 
//
#pragma once
#include <vector>
#include "util/Vector3d.hpp"
#include "game/field/camera/Camera.hpp"

namespace qwitch {
namespace game {

//---------------------------------------------------------------------
// 
//  
// 
//
class Area {
public:
    /// インスタンス
    static Area& ins();
    /// 読込み処理
    void load(int aCenterId);
    /// スクロール
    void scroll(int aX, int aY, int aZ);
    /// X方向へのスクロール量取得
    int calcScrollX(const Camera& camera) const;
    /// Y方向へのスクロール量取得
    int calcScrollY(const Camera& camera) const;
    /// Z方向へのスクロール量取得
    int calcScrollZ(const Camera& camera) const;

    /// getter
    int id(int aAreaIndex) const;
    int centerId() const;
    const Vector3d& pos() const;
    const Vector3d& pos0() const;
    const Vector3d& pos(int aAreaIndex) const;
    int arrayIndex(int aAreaIndex) const;

private:
    /// コンストラクタ
    Area();

    /// 現在の中心エリアID
    int mCenterId;
    /// 000の座標
    Vector3d mPos0;
    /// areaIndexと配列indexの対応
    std::vector<int> mArrayIndex;
};

} // namespace game
} // namespace qwitch