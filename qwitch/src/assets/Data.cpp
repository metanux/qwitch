//---------------------------------------------------------------------
// 
//  
// 
//
#include "Data.hpp"
#include "DxLib.h"
#include "util/FileReader.hpp"
#include "game/field/terrain/Terrain.hpp"

namespace qwitch {

//---------------------------------------------------------------------
// 
//  
// 
//
Data::Data()
    : mTerrain()
{
}

//---------------------------------------------------------------------
// 
//  
// 
//
Data& Data::ins()
{
    static Data instance;
    return instance;
}

//---------------------------------------------------------------------
// 
//  
// 
//
void Data::load()
{
    //----- 地形データの読込み
    loadTerrain();
    loadTerrainLink();
}

//---------------------------------------------------------------------
// 
//  
// 
//
void Data::loadTerrain()
{
    //-----
    char url[100];

    //----- 地形データの読み込み
    int countTerrain = 4;
    for (int i = 0; i < countTerrain; i++) {
        //--- ファイルオープン
        sprintf_s(url, "assets/data/terrain/%d.dat", i);
        FileReader file(url);

        //--- ファイル読込み
        TerrainData terrain;

        // (0,0,0)の座標
        file.nextLine();
        int x = file.nextInteger();
        int y = file.nextInteger();
        int z = file.nextInteger();
        terrain.setPos(Vector3d(x, y, z));

        // ブロック
        file.nextLine();
        int countBlock = file.nextInteger();
        for (int j = 0; j < countBlock; j++) {
            file.nextLine();
            int x = file.nextInteger();
            int y = file.nextInteger();
            int z = file.nextInteger();
            int kind = file.nextInteger();
            terrain.addBlock(x, y, z, kind);
        }

        //-----
        mTerrain.push_back(terrain);
    }
}

//---------------------------------------------------------------------
// 
//  
// 
//
void Data::loadTerrainLink()
{
    //----- ファイルオープン
    char url[100];
    sprintf_s(url, "assets/data/terrain/link.dat");
    FileReader file(url);

    //----- 縦横上下の設定
    file.nextLine();
    int count = file.nextInteger();
    for (int i = 0; i < count; i++) {
        file.nextLine();
        int terrainId1 = file.nextInteger();
        int terrainId2 = file.nextInteger();
        int areaIndex1 = file.nextInteger();
        int areaIndex2 = reverseAreaIndex(areaIndex1);
        mTerrain[terrainId1].setId(areaIndex1, terrainId2);
        mTerrain[terrainId2].setId(areaIndex2, terrainId1);
    }
    
    //----- 斜めの設定


    //----- 中心の設定
    int countTerrain = (int)mTerrain.size();
    for (int i = 0; i < countTerrain; i++) {
        mTerrain[i].setId(13, i);
    }
}

//---------------------------------------------------------------------
// 
//  
// 
//
int Data::reverseAreaIndex(int aAreaIndex) const
{
    if (aAreaIndex == 12) { return 14; }
    if (aAreaIndex == 14) { return 12; }
    if (aAreaIndex == 10) { return 16; }
    if (aAreaIndex == 16) { return 10; }
    if (aAreaIndex == 4) { return 22; }
    if (aAreaIndex == 22) { return 4; }
    return 0;
}

//---------------------------------------------------------------------
// 
//  
// 
//
const TerrainData& Data::terrain(int aIndex) const
{
    return mTerrain[aIndex];
}

} // namespace qwitch