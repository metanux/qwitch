//---------------------------------------------------------------------
// 
//  
// 
//
#include "Terrain.hpp"
#include "assets/Data.hpp"
#include "game/field/FieldParameter.hpp"
#include "game/field/area/Area.hpp"

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
{
    mCollision.resize(AreaData::AreaNum);
    for (int i = 0; i < AreaData::AreaNum; i++) {
        mCollision[i].resize(AreaData::BlockNum);
        for (int z = 0; z < AreaData::BlockNum; z++) {
            mCollision[i][z].resize(AreaData::BlockNum);
            for (int y = 0; y < AreaData::BlockNum; y++) {
                mCollision[i][z][y].resize(AreaData::BlockNum);
                for (int x = 0; x < AreaData::BlockNum; x++) {
                    mCollision[i][z][y][x] = 0;
                }
            }
        }
    }

    mBlocks.resize(AreaData::AreaNum);
}

//---------------------------------------------------------------------
// 
//  
// 
//
void Terrain::update(const Camera& camera)
{
    //----- 表示ブロックの更新
    updateDisplayBlocks(camera);
}

//---------------------------------------------------------------------
// 
//  
// 
//
void Terrain::updateDisplayBlocks(const Camera& camera)
{
    //----- 描画ブロックリストの初期化
    mDisplayBlocks.clear();

    //----- 描画ブロックの構成
    int count = (int)mSortedBlocks.size();
    for (int i = 0; i < count; i++) {
        const Block& block = mSortedBlocks[i];

        // 描画範囲外の確認
        if (camera.isRender(block)) {
            // リストに追加
            mDisplayBlocks.push_back(block);
        }
    }
}

//---------------------------------------------------------------------
// 
//  
// 
//
void Terrain::load(int aAreaId)
{
    //----- ブロックの読込み
    for (int i = 0; i < AreaData::AreaNum; i++) {
        int id = Data::ins().area(aAreaId).id(i);
        load(i, id);
    }

    //----- ブロックのソート
    sort();
    printf("terrain load\n");
}

//---------------------------------------------------------------------
// 
//  
// 
//
void Terrain::load(int aAreaIndex, int aAreaId)
{
    //----- 読込むエリア位置のデータ消去
    deleteArea(aAreaIndex);

    //----- 例外処理
    if (aAreaId == -1) {
        for (int z = 0; z < AreaData::BlockNum; z++) {
            for (int y = 0; y < AreaData::BlockNum; y++) {
                for (int x = 0; x < AreaData::BlockNum; x++) {
                    setCollision(aAreaIndex, x, y, z);
                }
            }
        }
        return;
    }

    //----- データ読込み
    const TerrainData& data = Data::ins().terrain(aAreaId);
    int count = data.countBlock();
    for (int i = 0; i < count; i++) {
        createBlock(
            aAreaIndex,
            data.x(i),
            data.y(i),
            data.z(i),
            data.kind(i)
        );
    }
}

//---------------------------------------------------------------------
// 
//  
// 
//
void Terrain::scroll(int aX, int aY, int aZ)
{
    //----- スクロール判定
    int centerId = Area::ins().centerId();
    const int* index = AreaData::area3(aX, aY, aZ);
    for (int i = 0; i < 9; i++) {
        int terrainId = Data::ins().area(centerId).id(index[i]);
        load(index[i], terrainId);
    }

    //----- 
    sort();
    printf("terrain scroll %d %d %d\n", aX, aY, aZ);
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
    int aBlockKind)
{
    //----- ブロック生成
    Block block;
    int sx = Block::PIXEL_SIZE;
    int sy = Block::PIXEL_SIZE;
    int sz = Block::PIXEL_SIZE;
    const Vector3d& areaPos = Area::ins().pos(aAreaIndex);
    int px = aX * sx + (int)areaPos.x();
    int py = aY * sy + (int)areaPos.y();
    int pz = aZ * sz + (int)areaPos.z();
    block.setPos(Vector3d(px, py, pz));
    block.setSize(Vector3d(sx, sy, sz));
    block.setKind(aBlockKind);

    //----- 配列に追加
    int index = Area::ins().arrayIndex(aAreaIndex);
    mBlocks[index].push_back(block);

    //----- 当たり判定の設定
    setCollision(aAreaIndex, aX, aY, aZ);
}

//---------------------------------------------------------------------
// 
//  
// 
//
bool Terrain::isCollision(const FieldObject& aObject) const
{
    //----- 
    const Vector3d& pos0 = Area::ins().pos0();
    int px = (int)aObject.pos().x() - (int)pos0.x();
    int py = (int)aObject.pos().y() - (int)pos0.y();
    int pz = (int)aObject.pos().z() - (int)pos0.z();
    int sx = (int)aObject.size().x();
    int sy = (int)aObject.size().y();
    int sz = (int)aObject.size().z();

    //----- 探索範囲
    int rangeXmin = px / Block::PIXEL_SIZE;
    int rangeYmin = py / Block::PIXEL_SIZE;
    int rangeZmin = pz / Block::PIXEL_SIZE;
    int rangeXmax = (px + sx - 1) / Block::PIXEL_SIZE;
    int rangeYmax = (py + sy - 1) / Block::PIXEL_SIZE;
    int rangeZmax = (pz + sz - 1) / Block::PIXEL_SIZE;

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
void Terrain::sort()
{
    //-----
    mSortedBlocks.clear();

    //-----
    for (int i = 0; i < AreaData::AreaNum; i++) {
        int count = (int)mBlocks[i].size();
        for (int j = 0; j < count; j++) {
            const Block& block = mBlocks[i][j];
            insertSortedBlocks(block);
        }
    }
    printf("terrain sort\n");
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
    int x2 = (int)aBlock.pos().x();
    int y2 = (int)aBlock.pos().y();
    int z2 = (int)aBlock.pos().z();
    int order2 = x2 + y2 * 100 + z2 * 10000;
    while (lb < ub) {
        int mid = (lb + ub) / 2;
        const Block& block = mSortedBlocks[mid];
        int x1 = (int)block.pos().x();
        int y1 = (int)block.pos().y();
        int z1 = (int)block.pos().z();
        int order1 = x1 + y1 * 100 + z1*10000;
        if (order1 > order2) {
            ub = mid;
        }
        else {
            lb = mid + 1;
        }
    }
    mSortedBlocks.insert(mSortedBlocks.begin() + lb, aBlock);
}

//---------------------------------------------------------------------
// 
//  
// 
//
void Terrain::deleteArea(int aAreaIndex)
{
    //----- index
    int index = Area::ins().arrayIndex(aAreaIndex);

    //----- ブロックの削除
    mBlocks[index].clear();

    //----- 当たり判定
    for (int z = 0; z < AreaData::BlockNum; z++) {
        for (int y = 0; y < AreaData::BlockNum; y++) {
            for (int x = 0; x < AreaData::BlockNum; x++) {
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
void Terrain::setCollision(int aAreaIndex, int aX, int aY, int aZ)
{
    int index = Area::ins().arrayIndex(aAreaIndex);
    mCollision[index][aZ][aY][aX] = 1;
}

//---------------------------------------------------------------------
// 
//  
// 
//
int Terrain::countBlock() const
{
    return (int)mDisplayBlocks.size();
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
int Terrain::collision(int aX, int aY, int aZ) const
{
    int areaIndex = convertAreaIndex(aX, aY, aZ);
    int arrayIndex = Area::ins().arrayIndex(areaIndex);
    int x = aX % AreaData::BlockNum;
    int y = aY % AreaData::BlockNum;
    int z = aZ % AreaData::BlockNum;
    return mCollision[arrayIndex][z][y][x];
}

//---------------------------------------------------------------------
// 
//  
// 
//
int Terrain::convertAreaIndex(int aX, int aY, int aZ) const
{
    
    int x = aX % AreaData::BlockNum;
    int y = aY % AreaData::BlockNum;
    int z = aZ % AreaData::BlockNum;
    int dx = aX / AreaData::BlockNum;
    int dy = aY / AreaData::BlockNum;
    int dz = aZ / AreaData::BlockNum;
    int index = 0;
    index += dx;
    index += dy * AreaData::AreaNum1;
    index += dz * AreaData::AreaNum1 * AreaData::AreaNum1;
    return index;
}

} // namespace game
} // namespace qwitch