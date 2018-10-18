//---------------------------------------------------------------------
// 
//  
// 
//
#include "Terrain.hpp"
#include "assets/Data.hpp"

namespace qwitch {
namespace game {

//---------------------------------------------------------------------
// 
//  
// 
//
Terrain::Terrain()
    : mBlocks()
    , mSortedBlocks()
    , mDisplayBlocks()
    , mCollision()
    , mArea0Pos()
    , mCenterTerrainId(0)
{
    mArea0Pos.setX(0);
    mArea0Pos.setY(0);
    mArea0Pos.setZ(0);

    mBlocks.resize(AREA_NUM);

    mAreaIndex.resize(AREA_NUM);
    for (int i = 0; i < AREA_NUM; i++) {
        mAreaIndex[i] = i;
    }
}

//---------------------------------------------------------------------
// 
//  
// 
//
void Terrain::update(const Camera& camera)
{
    //----- 地形データの読込み
    double cx = camera.fieldPos().x();
    double cy = camera.fieldPos().y();
    double cz = camera.fieldPos().z();
    int size = AREA_BLOCK_NUM * Block::PIXEL_SIZE;
    int minX = (int)mArea0Pos.x() + size;
    int minY = (int)mArea0Pos.y() + size;
    int minZ = (int)mArea0Pos.z() + size;
    int maxX = minX + size;
    int maxY = minY + size;
    int maxZ = minZ + size;

    // エリアの境界なら更新
    int dx = 0;
    int dy = 0;
    int dz = 0;
    dx = (cx < minX) ? -1 : dx;
    dy = (cy < minY) ? -1 : dy;
    dz = (cz < minZ) ? -1 : dz;
    dx = (cx > maxX) ? 1 : dx;
    dy = (cy > maxY) ? 1 : dy;
    dz = (cz > maxZ) ? 1 : dz;
    if (dx != 0 || dy != 0 || dz != 0) {
        scroll(dx, dy, dz);
    }

    //----- 描画ブロックの更新
    updateDisplayBlocks(camera);
}

//---------------------------------------------------------------------
// 
//  
// 
//
void Terrain::updateDisplayBlocks(
    const Camera& camera)
{
    //----- 描画ブロックリストの初期化
    mDisplayBlocks.clear();

    //----- 描画ブロックの構成
    double cx = camera.fieldPos().x();
    double cy = camera.fieldPos().y();
    double cz = camera.fieldPos().z();
    double renderSize = 600;
    int count = (int)mSortedBlocks.size();
    for (int i = 0; i < count; i++) {
        // 描画範囲外の確認
        const Block& block = mSortedBlocks[i];
        double px = block.pos().x();
        double py = block.pos().y();
        double pz = block.pos().z();
        if (px < cx - renderSize) { continue; }
        if (py < cy - renderSize) { continue; }
        if (pz < cz - renderSize) { continue; }
        if (px > cx + renderSize) { continue; }
        if (py > cy + renderSize) { continue; }
        if (pz > cz + renderSize) { continue; }
        // リストに追加
        mDisplayBlocks.push_back(block);
    }
}

//---------------------------------------------------------------------
// 
//  
// 
//
void Terrain::load(
    int aCenterTerrainId)
{
    //-----
    const TerrainData& data = Data::ins().terrain(aCenterTerrainId);

    //-----
    mCenterTerrainId = aCenterTerrainId;

    //----- (0,0,0)の座標設定
    mArea0Pos.setX(data.pos().x() - AREA_BLOCK_NUM * Block::PIXEL_SIZE);
    mArea0Pos.setY(data.pos().y() - AREA_BLOCK_NUM * Block::PIXEL_SIZE);
    mArea0Pos.setZ(data.pos().z() - AREA_BLOCK_NUM * Block::PIXEL_SIZE);

    //----- 各エリアごとの地形データ読込み
    for (int i = 0; i < AREA_NUM; i++) {
        int terrainId = data.id(i);
        loadArea(i, terrainId);
    }

    //----- ブロックのソート
    sortBlocks();
}

//---------------------------------------------------------------------
// 
//  
// 
//
void Terrain::loadArea(
    int aAreaIndex,
    int aTerrainId)
{
    //----- 読込むエリア位置のデータ消去
    deleteArea(aAreaIndex);

    //----- 例外処理
    if (aTerrainId == -1) {
        for (int z = 0; z < AREA_BLOCK_NUM; z++) {
            for (int y = 0; y < AREA_BLOCK_NUM; y++) {
                for (int x = 0; x < AREA_BLOCK_NUM; x++) {
                    setCollision(aAreaIndex, x, y, z);
                }
            }
        }
        return;
    }

    //----- データ読込み
    const TerrainData& data = Data::ins().terrain(aTerrainId);
    int count = data.countBlock();
    for (int i = 0; i < count; i++) {
        createBlock(
            aAreaIndex,
            data.x(i),
            data.y(i),
            data.z(i),
            data.kind(i),
            data.pos()
        );
    }
}

//---------------------------------------------------------------------
// 
//  
// 
//
void Terrain::scroll(
    int dx,
    int dy,
    int dz)
{
    printf("scroll %d %d %d\n", dx, dy, dz);
    // 削除するindex x:2のところ全て
    // 追加するindex x:0のところに
    
    if (dx <= -1) {
        // index1 = index2
        // index2 = index3
        // index3 = index1
        // index1 = loadArea
        int cenerIndex = 12;
        mCenterTerrainId = Data::ins().terrain(mCenterTerrainId).id(cenerIndex);
        int index1[] = { 2, 5, 8, 11, 14, 17, 20, 23, 26 };
        int index2[] = { 1, 4, 7, 10, 13, 16, 19, 22, 25 };
        int index3[] = { 0, 3, 6, 9, 12, 15, 18, 21, 24 };
        for (int i = 0; i < 9; i++) {
            int t = mAreaIndex[index1[i]];
            mAreaIndex[index1[i]] = mAreaIndex[index2[i]];
            mAreaIndex[index2[i]] = mAreaIndex[index3[i]];
            mAreaIndex[index3[i]] = t;
            int terrainId = Data::ins().terrain(mCenterTerrainId).id(index3[i]);
            printf("%d %d ", index3[i], terrainId);
            loadArea(index3[i], terrainId);
        }
    }

    //----- 中心位置
    const TerrainData& data = Data::ins().terrain(mCenterTerrainId);
    mArea0Pos.setX(data.pos().x() - AREA_BLOCK_NUM * Block::PIXEL_SIZE);
    mArea0Pos.setY(data.pos().y() - AREA_BLOCK_NUM * Block::PIXEL_SIZE);
    mArea0Pos.setZ(data.pos().z() - AREA_BLOCK_NUM * Block::PIXEL_SIZE);
    
    //----- ブロックのソート
    sortBlocks();;
}

//---------------------------------------------------------------------
// 
//  
// 
//
void Terrain::sortBlocks()
{
    //-----
    mSortedBlocks.clear();

    //-----
    for (int i = 0; i < AREA_NUM; i++) {
        int count = (int)mBlocks[i].size();
        for (int j = 0; j < count; j++) {
            const Block& block = mBlocks[i][j];
            insertSortedBlocks(block);
        }
    }
}

//---------------------------------------------------------------------
// 
//  
// 
//
void Terrain::insertSortedBlocks(const Block& aBlock)
{
    int lb = 0;
    int ub = (int)mSortedBlocks.size();
    while (ub - lb > 1) {
        int mid = (lb + ub) / 2;
        const Block& block = mSortedBlocks[mid];
        if (
            (block.pos().z() >= aBlock.pos().z()) &&
            (block.pos().y() >= aBlock.pos().y()) &&
            (block.pos().x() >= aBlock.pos().x())) {
            ub = mid;
        }
        /*
        if (block.pos().z() > aBlock.pos().z()) {
            ub = mid;
        }
        else if (block.pos().y() > aBlock.pos().y()) {
            ub = mid;
        }
        else if (block.pos().x() > aBlock.pos().x()) {
            ub = mid;
        }
        */
        else {
            lb = mid;
        }
    }
    mSortedBlocks.insert(mSortedBlocks.begin() + ub, aBlock);
}

//---------------------------------------------------------------------
// 
//  
// 
//
void Terrain::createBlock(
    int aAreaIndex,
    int aX,
    int aY,
    int aZ,
    int aBlockKind,
    const Vector3d& aAreaPos)
{
    //----- ブロック生成
    Block block;
    int sx = Block::PIXEL_SIZE;
    int sy = Block::PIXEL_SIZE;
    int sz = Block::PIXEL_SIZE;
    int px = aX * sx + (int)aAreaPos.x();
    int py = aY * sy + (int)aAreaPos.y();
    int pz = aZ * sz + (int)aAreaPos.z();
    block.setPos(Vector3d(px, py, pz));
    block.setSize(Vector3d(sx, sy, sz));
    block.setKind(aBlockKind);

    //----- ブロック追加
    addBlock(aAreaIndex, block);
    
    
    //----- 当たり判定の設定
    setCollision(aAreaIndex, aX, aY, aZ);
}

//---------------------------------------------------------------------
// 
//  
// 
//
void Terrain::addBlock(
    int aAreaIndex,
    const Block& block)
{
    int index = mAreaIndex[aAreaIndex];
    mBlocks[index].push_back(block);
}

//---------------------------------------------------------------------
// 
//  
// 
//
void Terrain::deleteArea(int aAreaIndex)
{
    //----- ブロックの削除
    int index = mAreaIndex[aAreaIndex];
    mBlocks[index].clear();

    //----- 当たり判定
    for (int z = 0; z < AREA_BLOCK_NUM; z++) {
        for (int y = 0; y < AREA_BLOCK_NUM; y++) {
            for (int x = 0; x < AREA_BLOCK_NUM; x++) {
                mCollision[index][z][y][x] = 0;
            }
        }
    }
}

//---------------------------------------------------------------------
// 
//  
// 
//
bool Terrain::isCollision(const FieldObject& aObject) const
{
    //----- 
    int px = (int)aObject.pos().x() - (int)mArea0Pos.x();
    int py = (int)aObject.pos().y() - (int)mArea0Pos.y();
    int pz = (int)aObject.pos().z() - (int)mArea0Pos.z();
    int sx = (int)aObject.size().x();
    int sy = (int)aObject.size().y();
    int sz = (int)aObject.size().z();

    //----- 範囲外の対応
    /*
    if (px < 0) { return true; }
    if (py < 0) { return true; }
    if (pz < 0) { return true; }
    if (px + sx - 1 >= AREA_BLOCK_NUM * Block::PIXEL_SIZE) { return true; }
    if (py + sy - 1 >= AREA_BLOCK_NUM * Block::PIXEL_SIZE) { return true; }
    if (pz + sz - 1 >= AREA_BLOCK_NUM * Block::PIXEL_SIZE) { return true; }
    */
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
                if (collision(x, y, z)) {
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

//---------------------------------------------------------------------
// 
//  
// 
//
int Terrain::collision(int aX, int aY, int aZ) const
{
    int index = convertAreaIndex(aX, aY, aZ);
    index = mAreaIndex[index];
    int x = aX % AREA_BLOCK_NUM;
    int y = aY % AREA_BLOCK_NUM;
    int z = aZ % AREA_BLOCK_NUM;
    return mCollision[index][z][y][x];
}


//---------------------------------------------------------------------
// 
//  
// 
//
void Terrain::setCollision(int aAreaIndex, int aX, int aY, int aZ)
{
    int index = mAreaIndex[aAreaIndex];
    mCollision[index][aZ][aY][aX] = 1;
}

//---------------------------------------------------------------------
// 
//  
// 
//
int Terrain::convertAreaIndex(int aX, int aY, int aZ) const
{
    int x = aX % AREA_BLOCK_NUM;
    int y = aY % AREA_BLOCK_NUM;
    int z = aZ % AREA_BLOCK_NUM;
    int dx = aX / AREA_BLOCK_NUM;
    int dy = aY / AREA_BLOCK_NUM;
    int dz = aZ / AREA_BLOCK_NUM;
    int index = 0;
    index += dx;
    index += dy * AREA_NUM_1;
    index += dz * AREA_NUM_1 * AREA_NUM_1;
    return index;
}

} // namespace game
} // namespace qwitch