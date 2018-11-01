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
    /*
    const Terrain& terrain = aField.terrain();
    int countBlocks = terrain.countBlock();
    printf("blockNum: %d\n", countBlocks);
    for (int i = 0; i < countBlocks; i++) {
        const Block& block = terrain.block(i);
        objects.push_back(block);
        //index.push_back(countObjects++);
    }
    */
    const Terrain& terrain = aField.terrain();
    int countGroups = terrain.countGroup();
    for (int i = 0; i < countGroups; i++) {
        const BlockGroup& group = terrain.group(i);
        objects.push_back(group);
    }

    // 攻撃オブジェクト
    const Bullets& bullets = aField.bullets();
    int countBullets = bullets.count();
    for (int i = 0; i < countBullets; i++) {
        const Bullet& bullet = bullets.bullet(i);
        objects.push_back(bullet);
        //index.push_back(countObjects++);
    }

    // キャラクター
    const Characters& charas = aField.characters();
    int countCharas = charas.countDisplayCharacter();
    for (int i = 0; i < countCharas; i++) {
        const Character& chara = charas.displayCharacter(i);
        objects.push_back(chara);
        //index.push_back(countObjects++);
    }

    // 構造物
    const Structures& structures = aField.structures();
    int countStructures = structures.countDisplayStructure();
    for (int i = 0; i < countStructures; i++) {
        const Structure& structure = structures.displayStructure(i);
        objects.push_back(structure);
        //index.push_back(countObjects++);
    }


    //----- 描画オブジェクトを描画順にソート
    // とりあえず挿入ソート
    // O(n^2)なので変更する必要がある
    sortObjects(objects, index);

    //----- オブジェクトの描画
    int count = (int)index.size();
    printf("objects %d\n", count);
    for (int i = 0; i < count; i++) {
        renderObject(aField, objects[index[i]], i);
    }
}

//---------------------------------------------------------------------
// 
//  
// 
//
void FieldRender::renderObject(
    const Field& aField,
    const FieldObject& aObject,int order) const
{
    const auto& images = aObject.images();
    int count = (int)images.size();
    for (int i = 0; i < count; i++) {
        //int dx = (int)images[i].posX();
        //int dy = (int)images[i].posY();
        int posX = calcRenderPosX(aField, images[i]);
        int posY = calcRenderPosY(aField, images[i]);
        int handl = images[i].handl();
        DxLib::DrawGraph(posX, posY, handl, TRUE);
    }
    //DxLib::DrawFormatString(x + 16, y + 8, GetColor(0, 0, 0), "%d", order);
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

//---------------------------------------------------------------------
// 
//  
// 
//
int FieldRender::calcRenderPosX(
    const Field& aField,
    const ObjectImage& aImage) const
{
    int x = 0;
    x += (int)aImage.convertWindowPosX();
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
    const ObjectImage& aImage) const
{
    int y = 0;
    y += (int)aImage.convertWindowPosY();
    y -= (int)aField.camera().windowPos().y();
    return y;
}

//---------------------------------------------------------------------
// 
//  
// 
//
void FieldRender::sortObjects(
    std::vector<std::reference_wrapper<const FieldObject>>& aObjects,
    std::vector<int>& aIndex) const
{
    //----- 隣接行列の構築
    int n = (int)aObjects.size();
    std::vector<int> a(n * n); // 隣接行列
    for (int i = 0; i < (n - 1); i++) {
        for (int j = (i + 1); j < n; j++) {
            const FieldObject& object1 = aObjects[i];
            const FieldObject& object2 = aObjects[j];
            if (object1.isPreRender(object2)) {
                a[i + j * n] = 1;
            }
            if (object2.isPreRender(object1)) {
                a[j + i * n] = 1;
            }
        }
    }

    //----- 深さ優先探索 (DFS)
    std::vector<int> v(n);           // 訪問フラグ
    for (int i = 0; i < n; i++) {
        if (v[i] == 0) {
            sortObjectsVisit(i, n, a, v, aIndex);
        }
    }
    /*
    int count = (int)aObjects.size();
    for (int i = 0; i < count; i++) {
        for (int j = i; j > 0; j--) {
            int i1 = aIndex[j];
            int i2 = aIndex[j - 1];
            const FieldObject& object1 = aObjects[i1];
            const FieldObject& object2 = aObjects[i2];
            if (isPreRenderObject(object1, object2)) {
                std::swap(aIndex[j - 1], aIndex[j]);
            }
            else {
                break;
            }
        }
    }
    */
}

//---------------------------------------------------------------------
// 
//  
// 
//
void FieldRender::sortObjectsVisit(
    int aI,
    int aN,
    std::vector<int>& aA,
    std::vector<int>& aV,
    std::vector<int>& aIndex) const
{
    aV[aI] = 1;
    for (int j = 0; j < aN; j++) {
        if ((aA[j + aI * aN] == 1) && (aV[j] == 0)) {
            sortObjectsVisit(j, aN, aA, aV, aIndex);
        }
    }
    aIndex.push_back(aI);
}

} // namespace game
} // namespace qwitch