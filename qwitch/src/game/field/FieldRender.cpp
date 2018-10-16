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
    std::vector<std::reference_wrapper<const FieldObject>> objects;

    // 地形ブロック
    const Terrain& terrain = aField.terrain();
    int countBlocks = terrain.blockNum();
    printf("%d\n", countBlocks);
    for (int i = 0; i < countBlocks; i++) {
        const Block& block = terrain.block(i);
        objects.push_back(block);
    }
    // キャラクター
    const Characters& charas = aField.characters();
    int countCharas = charas.countCharacter();
    for (int i = 0; i < countCharas; i++) {
        const Character& chara = charas.character(i);
        objects.push_back(chara);
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
    int image = aObject.image();
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
    int x = 0;
    x += (int)aObject.pos().x();
    x -= (int)aObject.pos().y();
    x -= (int)aObject.size().x();
    x -= (int)aField.camera().pos().x();
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
    int y = 0;
    y += (int)aObject.pos().x() / 2;
    y += (int)aObject.pos().y() / 2;
    y -= (int)aObject.pos().z();
    y -= (int)aObject.size().z();
    y -= (int)aField.camera().pos().y();
    return y;
}

} // namespace game
} // namespace qwitch