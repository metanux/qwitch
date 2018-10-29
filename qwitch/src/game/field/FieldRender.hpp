//---------------------------------------------------------------------
// 
//  
// 
//
#pragma once
#include "game/field/Field.hpp"

namespace qwitch {
namespace game {

//---------------------------------------------------------------------
// 
//  
// 
//
class FieldRender {
public:
    /// コンストラクタ
    FieldRender();

    /// 描画
    void render(
        const Field& aField) const;

private:
    /// オブジェクト一覧の描画
    void renderObjects(
        const Field& aField) const;

    /// オブジェクトを描画する
    void renderObject(
        const Field& aField,
        const FieldObject& aObject,int order) const;

    /// ダメージエフェクトの描画
    void renderDamageEffect(
        const Field& aField) const;

    /// オブジェクトの描画座標 x を算出する
    int calcRenderPosX(
        const Field& aField,
        const FieldObject& aObject) const;

    /// オブジェクトの描画座標 y を算出する
    int calcRenderPosY(
        const Field& aField,
        const FieldObject& aObject) const;

    /// 
    int calcRenderPosX(
        const Field& aField,
        int aX) const;

    ///
    int calcRenderPosY(
        const Field& aField,
        int aY) const;

    /// 2オブジェクト間の順序関係を判定
    /// オブジェクト1を先に描画：true
    /// オブジェクト2を先に描画：false
    bool isPreRenderObject(
        const FieldObject& aObject1,
        const FieldObject& aObject2) const;

    /// オブジェクトのソート
    void sortObjects(
        std::vector<std::reference_wrapper<const FieldObject>>& aObjects,
        std::vector<int>& aIndex) const;
    ///
    void sortObjectsVisit(
        int aI,
        int aN,
        std::vector<int>& aA,
        std::vector<int>& aV,
        std::vector<int>& aIndex) const;
};

} // namespace game
} // namespace qwitch