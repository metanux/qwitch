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
    //----- オブジェクトの描画
    renderObjects(aField);

    //----- ダメージの描画
    renderDamageEffect(aField);
}

//---------------------------------------------------------------------
// 
//  
// 
//
void FieldRender::renderObjects(
    const Field& aField) const
{
    //----- 描画オブジェクトを取得
    int countObjects = 0;
    std::vector<std::reference_wrapper<const FieldObject>> objects;
    std::vector<int> index;

    // 地形ブロック
    const Terrain& terrain = aField.terrain();
    int countBlocks = terrain.countBlock();
    //printf("blockNum: %d\n", countBlocks);
    for (int i = 0; i < countBlocks; i++) {
        const Block& block = terrain.block(i);
        objects.push_back(block);
        index.push_back(countObjects++);
    }

    // 攻撃オブジェクト
    const Bullets& bullets = aField.bullets();
    int countBullets = bullets.count();
    for (int i = 0; i < countBullets; i++) {
        const Bullet& bullet = bullets.bullet(i);
        objects.push_back(bullet);
        index.push_back(countObjects++);
    }

    // キャラクター
    const Characters& charas = aField.characters();
    int countCharas = charas.countDisplayCharacter();
    for (int i = 0; i < countCharas; i++) {
        const Character& chara = charas.displayCharacter(i);
        objects.push_back(chara);
        index.push_back(countObjects++);
    }

    // 構造物
    const Structures& structures = aField.structures();
    int countStructures = structures.countDisplayStructure();
    for (int i = 0; i < countStructures; i++) {
        const Structure& structure = structures.displayStructure(i);
        objects.push_back(structure);
        index.push_back(countObjects++);
    }

    //----- 描画オブジェクトを描画順にソート
    // とりあえず挿入ソート
    // O(n^2)なので変更する必要がある
    for (int i = countBlocks; i < countObjects; i++) {
        for (int j = i; j > 0; j--) {
            int i1 = index[j];
            int i2 = index[j - 1];
            const FieldObject& object1 = objects[i1];
            const FieldObject& object2 = objects[i2];
            //int x1 = (int)(object1.pos().x());
            //int y1 = (int)(object1.pos().y());
            //int z1 = (int)(object1.pos().z());
            int x1 = (int)(object1.pos().x() + object1.size().x());
            int y1 = (int)(object1.pos().y() + object1.size().y());
            int z1 = (int)(object1.pos().z() + object1.size().z());
            int x2 = (int)(object2.pos().x());
            int y2 = (int)(object2.pos().y());
            int z2 = (int)(object2.pos().z());
            //int x2 = (int)(object2.pos().x() + object2.size().x());
            //int y2 = (int)(object2.pos().y() + object2.size().y());
            //int z2 = (int)(object2.pos().z() + object2.size().z());
            // 1を先に描画
            //if ((x1+y1+z1) <= (x2+y2+z2)) {
            if (x1 <= x2 || y1 <= y2 || z1 <= z2) {
                std::swap(index[j - 1], index[j]);
            }
            else {
                printf("%d ", j);
                break;
            }
        }
    }
    printf("\n");

    //----- オブジェクトの描画
    for (int i = 0; i < countObjects; i++) {
        renderObject(aField, objects[index[i]]);
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
void FieldRender::renderDamageEffect(
    const Field& aField) const
{
    const DamageEffects& effects = aField.damageEffects();
    int count = effects.count();
    for (int i = 0; i < count; i++) {
        const DamageEffect& effect = effects.effect(i);
        int damage = effect.damage();
        int x = (int)effect.windowPosX();
        int y = (int)effect.windowPosY();
        int posX = calcRenderPosX(aField, x);
        int posY = calcRenderPosY(aField, y);
        DxLib::DrawFormatString(posX, posY, DxLib::GetColor(255, 255, 255), "%d", damage);
    }
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

//---------------------------------------------------------------------
// 
//  
// 
//
int FieldRender::calcRenderPosX(
    const Field& aField,
    int aX) const
{
    int x = 0;
    x += aX;
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
    int aY) const
{
    int y = 0;
    y += aY;
    y -= (int)aField.camera().windowPos().y();
    return y;
}

} // namespace game
} // namespace qwitch