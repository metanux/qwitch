//---------------------------------------------------------------------
// 
//  
// 
//
#include "Terrain.hpp"

namespace qwitch {
namespace game {

//---------------------------------------------------------------------
// 
//  
// 
//
Terrain::Terrain()
    : mBlocks()
    , mDisplayBlocks()
    , mCollision()
    , mArea0MapPos()
{        
    mArea0MapPos.setX(AREA_BLOCK_NUM);
    mArea0MapPos.setY(AREA_BLOCK_NUM);
    mArea0MapPos.setZ(AREA_BLOCK_NUM);

    // デバッグ用
    load(0, 0);
}

//---------------------------------------------------------------------
// 
//  
// 
//
void Terrain::update()
{

}

//---------------------------------------------------------------------
// 
//  
// 
//
void Terrain::updateDisplayBlocks(
    const Camera& camera)
{
    //-----
    mDisplayBlocks.clear();

    //-----
    int countBlocks = (int)mBlocks.size();
    for (int i = 0; i < countBlocks; i++) {
        mDisplayBlocks.push_back(mBlocks[i]);
    }
}

//---------------------------------------------------------------------
// 
//  
// 
//
void Terrain::load(int aAreaIndex, int aAreaNum)
{
    //----- データ消去

    //----- 地形データ読み込み
    // デバッグ用
    for (int y = 0; y < 48; y++) {
        for (int x = 0; x < 48; x++) {
            createBlock(x, y, 0, 1);
        }
    }
}

//---------------------------------------------------------------------
// 
//  
// 
//
void Terrain::createBlock(
    int aX,
    int aY,
    int aZ,
    int aBlockKind)
{
    //----- ブロック生成
    Block block;
    int sx = Block::PIXEL_SIZE;
    int sy = Block::PIXEL_SIZE;
    int sz = Block::PIXEL_SIZE;
    int px = aX * sx;
    int py = aY * sy;
    int pz = aZ * sz;
    block.setPos(Vector3d(px, py, pz));
    block.setSize(Vector3d(sx, sy, sz));

    //----- ブロック追加
    mBlocks.push_back(block);
    
    //----- 当たり判定の設定
    mCollision[aZ][aY][aX] = 1;
}


//---------------------------------------------------------------------
// 
//  
// 
//
bool Terrain::isCollision(const FieldObject& aObject) const
{
    //----- 
    int px = (int)aObject.pos().x();
    int py = (int)aObject.pos().y();
    int pz = (int)aObject.pos().z();
    int sx = (int)aObject.size().x();
    int sy = (int)aObject.size().y();
    int sz = (int)aObject.size().z();

    //----- 範囲外の対応
    if (px < 0) { return true; }
    if (py < 0) { return true; }
    if (pz < 0) { return true; }
    if (px + sx - 1 >= AREA_BLOCK_NUM * Block::PIXEL_SIZE) { return true; }
    if (py + sy - 1 >= AREA_BLOCK_NUM * Block::PIXEL_SIZE) { return true; }
    if (pz + sz - 1 >= AREA_BLOCK_NUM * Block::PIXEL_SIZE) { return true; }

    //----- 探索範囲
    int rangeXmin = px / Block::PIXEL_SIZE;
    int rangeYmin = py / Block::PIXEL_SIZE;
    int rangeZmin = pz / Block::PIXEL_SIZE;
    int rangeXmax = (px + sx - 1) / Block::PIXEL_SIZE;
    int rangeYmax = (py + sy - 1) / Block::PIXEL_SIZE;
    int rangeZmax = (pz + sz - 1) / Block::PIXEL_SIZE;

    /*
    rangeXmin = (rangeXmin < 0) ? 0 : rangeXmin;
    rangeYmin = (rangeYmin < 0) ? 0 : rangeYmin;
    rangeZmin = (rangeZmin < 0) ? 0 : rangeZmin;
    rangeXmax = (rangeXmax >= AREA_BLOCK_NUM) ? (int)(AREA_BLOCK_NUM - 1) : rangeXmax;
    rangeYmax = (rangeYmax >= AREA_BLOCK_NUM) ? (int)(AREA_BLOCK_NUM - 1) : rangeYmax;
    rangeZmax = (rangeZmax >= AREA_BLOCK_NUM) ? (int)(AREA_BLOCK_NUM - 1) : rangeZmax;
    */
    
    //----- 判定
    for (int z = rangeZmin; z <= rangeZmax; z++) {
        for (int y = rangeYmin; y <= rangeYmax; y++) {
            for (int x = rangeXmin; x <= rangeXmax; x++) {
                if (mCollision[z][y][x]) {
                    return true;
                }
            }
        }
    }
    return false;
}

//---------------------------------------------------------------------
// 
//  
// 
//
const Block& Terrain::block(int aIndex) const
{
    return mDisplayBlocks[aIndex];
}

//---------------------------------------------------------------------
// 
//  
// 
//
int Terrain::blockNum() const
{
    return (int)mDisplayBlocks.size();
}

} // namespace game
} // namespace qwitch