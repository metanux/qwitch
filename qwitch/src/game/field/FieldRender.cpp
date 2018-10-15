//---------------------------------------------------------------------
// 
//  
// 
//
#include "FieldRender.hpp"
#include "DxLib.h"
#include "assets/Images.hpp"
#include "system/System.hpp"

namespace qwitch {
namespace game {

//---------------------------------------------------------------------
// 
//  
// 
//
FieldRender::FieldRender()
{
}

//---------------------------------------------------------------------
// 
//  
// 
//
void FieldRender::render(const Field& aField) const
{
    //----- 描画オブジェクトを取得
    std::vector<FieldObject> objects;

    // 地形ブロック
    const Terrain& terrain = aField.terrain();
    int countBlocks = terrain.countBlocks();
    for (int i = 0; i < countBlocks; i++) {
        const Block& block = terrain.block(i);
        objects.push_back(block);
    }

    //----- 描画オブジェクトを描画順にソート
    
    //----- オブジェクトの描画
    int countObjects = (int)objects.size();
    for (int i = 0; i < countObjects; i++) {
        renderObject(aField, objects[i]);
    }
}

//---------------------------------------------------------------------
// 
//  
// 
//
void FieldRender::renderObject(
    const Field& aField,
    const FieldObject& aObject) const
{
    int x = calcRenderPosX(aField, aObject);
    int y = calcRenderPosY(aField, aObject);
    int image = Images::ins().block(0);
    DxLib::DrawGraph(x, y, image, TRUE);
}

//---------------------------------------------------------------------
// 
//  
// 
//
int FieldRender::calcRenderPosX(
    const Field& aField,
    const FieldObject& aObject) const
{
    int x = (int)aObject.pos().x();
    return x;
}

//---------------------------------------------------------------------
// 
//  
// 
//
int FieldRender::calcRenderPosY(
    const Field& aField,
    const FieldObject& aObject) const
{
    int y = (int)aObject.pos().y();
    return y;
}

} // namespace game
} // namespace qwitch