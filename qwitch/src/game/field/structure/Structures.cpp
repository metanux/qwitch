//---------------------------------------------------------------------
// 
//  
// 
//
#include "Structures.hpp"
#include "DxLib.h"
#include "assets/Data.hpp"

namespace qwitch {
namespace game {

//---------------------------------------------------------------------
// 
//  
// 
//
Structures::Structures()
{
}

//---------------------------------------------------------------------
// 
//  
// 
//
void Structures::update()
{
    //----- 状態の更新
    int count = mStructures.size();
    for (int i = 0; i < count; i++) {
        mStructures[i].update();
    }

    //----- 表示オブジェクトの更新
    mDisplayStructures.clear();
    for (int i = 0; i < count; i++) {
        const Structure& obj = mStructures[i];
        mDisplayStructures.push_back(obj);
    }
}

//---------------------------------------------------------------------
// 
//  
// 
//
void Structures::load(int aAreaId)
{
    const auto& data = Data::ins().area(aAreaId);
    int count = data.countStructure();
    for (int i = 0; i < count; i++) {
        Structure structure;
        const Vector3d& pos = data.structurePos(i);
        int kind = data.structureKind(i);
        const Vector3d& size = Data::ins().structure(kind).size();
        structure.setPos(pos);
        structure.setKind(kind);
        structure.setSize(size);
        mStructures.push_back(structure);
    }
}


//---------------------------------------------------------------------
// 
//  
// 
//
bool Structures::isCollision(const FieldObject& aObject) const
{
    int count = (int)mStructures.size();
    for (int i = 0; i < count; i++) {
        if (mStructures[i].isEqual(aObject)) { continue; }
        if (mStructures[i].isCollision(aObject)) {
            return true;
        }
    }
    return false;
}

//---------------------------------------------------------------------
// 
//  
// 
//
int Structures::countDisplayStructure() const
{
    return (int)mDisplayStructures.size();
}

//---------------------------------------------------------------------
// 
//  
// 
//
const Structure& Structures::structure(int aIndex)
{
    return mStructures[aIndex];
}
//---------------------------------------------------------------------
const Structure& Structures::displayStructure(int aIndex) const
{
    return mDisplayStructures[aIndex];
}

} // namespace game
} // namespace qwitch