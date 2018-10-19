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
    std::vector<std::reference_wrapper<const FieldObject>> addObjects;

    // 地形ブロック
    const Terrain& terrain = aField.terrain();
    int countBlocks = terrain.blockNum();
    printf("blockNum: %d\n", countBlocks);
    for (int i = 0; i < countBlocks; i++) {
        const Block& block = terrain.block(i);
        objects.push_back(block);
    }

    // キャラクター
    const Characters& charas = aField.characters();
    int countCharas = charas.countCharacter();
    for (int i = 0; i < countCharas; i++) {
        const Character& chara = charas.character(i);
        addObjects.push_back(chara);
    }

    //----- 描画オブジェクトを描画順にソート
    int countObjects = (int)objects.size();
    int countAddObjects = (int)addObjects.size();
    for (int i = 0; i < countAddObjects; i++) {
        // 二分挿入ソート
        int lb = 0;
        int ub = countObjects;
        while (lb < ub) {
            int mid = (lb + ub) / 2;
            const FieldObject& object1 = objects[mid];
            const FieldObject& object2 = addObjects[i];
            int x1 = (int)(object1.pos().x());
            int y1 = (int)(object1.pos().y());
            int z1 = (int)(object1.pos().z());
            int x2 = (int)(object2.pos().x() + object2.size().x());
            int y2 = (int)(object2.pos().y() + object2.size().y());
            int z2 = (int)(object2.pos().z() + object2.size().z());
            if (z1 > z2) {
                ub = mid;
            }
            else if ((z1 == z2) && (y1 > y2)) {
                ub = mid;
            }
            else if ((z1 == z2) && (y1 == y2) && (x1 > x2)) {
                ub = mid;
            }
            else {
                lb = mid + 1;
            }
        }
        objects.insert(objects.begin() + lb, addObjects[i]);
        countObjects++;
    }


    //----- オブジェクトの描画
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
    x += (int)aObject.convertWindowPosX();
    x -= (int)aField.camera().windowPos().x();
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
    y += (int)aObject.convertWindowPosY();
    y -= (int)aField.camera().windowPos().y();
    return y;
}

} // namespace game
} // namespace qwitch