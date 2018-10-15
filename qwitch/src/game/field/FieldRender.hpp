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
    FieldRender();

    void render(
        const Field& aField) const;

private:
    /// オブジェクトを描画する
    void renderObject(
        const Field& aField,
        const FieldObject& aObject) const;

    /// オブジェクトの描画座標 x を算出する
    int calcRenderPosX(
        const Field& aField,
        const FieldObject& aObject) const;

    /// オブジェクトの描画座標 y を算出する
    int calcRenderPosY(
        const Field& aField,
        const FieldObject& aObject) const;
};

} // namespace game
} // namespace qwitch