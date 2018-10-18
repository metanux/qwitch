//---------------------------------------------------------------------
// 
//  
// 
//
#include "Data.hpp"
#include "DxLib.h"
#include "util/FileReader.hpp"

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
    int countTerrain = 1;
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
            printf("%d %d %d %d\n", x, y, z, kind);
        }
        mTerrain.push_back(terrain);
    }
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