//---------------------------------------------------------------------
// 
//  
// 
//
#include "Area.hpp"
#include "assets/Data.hpp"
#include "game/field/terrain/Terrain.hpp"

namespace qwitch {
namespace game {

//---------------------------------------------------------------------
// 
//  
// 
//
Area::Area()
    : mCenterId(0)
    , mPos0()
    , mArrayIndex()
{
    mArrayIndex.resize(AreaData::AreaNum);
    for (int i = 0; i < AreaData::AreaNum; i++) {
        mArrayIndex[i] = i;
    }
}

//---------------------------------------------------------------------
// 
//  
// 
//
Area& Area::ins()
{
    static Area instance;
    return instance;
}

//---------------------------------------------------------------------
// 
//  
// 
//
void Area::load(int aCenterId)
{
    mCenterId = aCenterId;

    const Vector3d& centerPos = pos();
    int size = AreaData::BlockNum * Block::PIXEL_SIZE;
    mPos0.setX(centerPos.x() - size);
    mPos0.setY(centerPos.y() - size);
    mPos0.setZ(centerPos.z() - size);
}

//---------------------------------------------------------------------
// 
//  
// 
//
void Area::scroll(int aX, int aY, int aZ)
{
    int cenerIndex = 0;
    int index1[9];
    int index2[9];
    int index3[9];

    if (aX <= -1) {
        cenerIndex = 12;
        const int* index1t = AreaData::areaYZ(1);
        const int* index2t = AreaData::areaYZ(0);
        const int* index3t = AreaData::areaYZ(-1);
        memcpy(index1, index1t, sizeof(index1));
        memcpy(index2, index2t, sizeof(index2));
        memcpy(index3, index3t, sizeof(index3));
    }
    else if (aX >= 1) {
        cenerIndex = 14;
        const int* index1t = AreaData::areaYZ(-1);
        const int* index2t = AreaData::areaYZ(0);
        const int* index3t = AreaData::areaYZ(1);
        memcpy(index1, index1t, sizeof(index1));
        memcpy(index2, index2t, sizeof(index2));
        memcpy(index3, index3t, sizeof(index3));
    }
    else if (aY <= -1) {
        cenerIndex = 10;
        const int* index1t = AreaData::areaXZ(1);
        const int* index2t = AreaData::areaXZ(0);
        const int* index3t = AreaData::areaXZ(-1);
        memcpy(index1, index1t, sizeof(index1));
        memcpy(index2, index2t, sizeof(index2));
        memcpy(index3, index3t, sizeof(index3));
    }
    else if (aY >= 1) {
        cenerIndex = 16;
        const int* index1t = AreaData::areaXZ(-1);
        const int* index2t = AreaData::areaXZ(0);
        const int* index3t = AreaData::areaXZ(1);
        memcpy(index1, index1t, sizeof(index1));
        memcpy(index2, index2t, sizeof(index2));
        memcpy(index3, index3t, sizeof(index3));
    }
    else if (aZ <= -1) {
        cenerIndex = 4;
        const int* index1t = AreaData::areaXY(1);
        const int* index2t = AreaData::areaXY(0);
        const int* index3t = AreaData::areaXY(-1);
        memcpy(index1, index1t, sizeof(index1));
        memcpy(index2, index2t, sizeof(index2));
        memcpy(index3, index3t, sizeof(index3));
    }
    else if (aZ >= 1) {
        cenerIndex = 22;
        const int* index1t = AreaData::areaXY(-1);
        const int* index2t = AreaData::areaXY(0);
        const int* index3t = AreaData::areaXY(1);
        memcpy(index1, index1t, sizeof(index1));
        memcpy(index2, index2t, sizeof(index2));
        memcpy(index3, index3t, sizeof(index3));
    }

    //----- 移動
    int nextCenterId = Data::ins().area(mCenterId).id(cenerIndex);
    if (nextCenterId != -1) {
        load(nextCenterId);
        for (int i = 0; i < 9; i++) {
            int t = mArrayIndex[index1[i]];
            mArrayIndex[index1[i]] = mArrayIndex[index2[i]];
            mArrayIndex[index2[i]] = mArrayIndex[index3[i]];
            mArrayIndex[index3[i]] = t;
        }
    }
}

//---------------------------------------------------------------------
// 
//  
// 
//
int Area::calcScrollX(const Camera& camera) const
{
    double cx = camera.fieldPos().x();
    int size = AreaData::BlockNum * Block::PIXEL_SIZE;
    int minX = (int)mPos0.x() + size;
    int maxX = minX + size;
    int dx = 0;
    dx = (cx <= minX) ? -1 : dx;
    dx = (cx > maxX) ? 1 : dx;
    return dx;
}
//---------------------------------------------------------------------
int Area::calcScrollY(const Camera& camera) const
{
    double cy = camera.fieldPos().y();
    int size = AreaData::BlockNum * Block::PIXEL_SIZE;
    int minY = (int)mPos0.y() + size;
    int maxY = minY + size;
    int dy = 0;
    dy = (cy <= minY) ? -1 : dy;
    dy = (cy > maxY) ? 1 : dy;
    return dy;
}
//---------------------------------------------------------------------
int Area::calcScrollZ(const Camera& camera) const
{
    double cz = camera.fieldPos().z();
    int size = AreaData::BlockNum * Block::PIXEL_SIZE;
    int minZ = (int)mPos0.z() + size;
    int maxZ = minZ + size;
    int dz = 0;
    dz = (cz <= minZ) ? -1 : dz;
    dz = (cz > maxZ) ? 1 : dz;
    return dz;
}

//---------------------------------------------------------------------
// 
//  
// 
//
int Area::id(int aAreaIndex) const
{
    return Data::ins().area(mCenterId).id(aAreaIndex);
}
//---------------------------------------------------------------------
int Area::centerId() const
{
    return mCenterId;
}
//---------------------------------------------------------------------
const Vector3d& Area::pos() const
{
    return Data::ins().area(mCenterId).pos();
}
//---------------------------------------------------------------------
const Vector3d& Area::pos0() const
{
    return mPos0;
}
//---------------------------------------------------------------------
const Vector3d& Area::pos(int aAreaIndex) const
{
    int id = Data::ins().area(mCenterId).id(aAreaIndex);
    return Data::ins().area(id).pos();
}
//---------------------------------------------------------------------
int Area::arrayIndex(int aAreaIndex) const
{
    return mArrayIndex[aAreaIndex];
}

} // namespace game
} // namespace qwitch