//---------------------------------------------------------------------
// 
//  
// 
//
#include "Data.hpp"
#include "DxLib.h"
#include "util/FileReader.hpp"
#include "game/field/terrain/Terrain.hpp"
#include "assets/data/TerrainBoxData.hpp"

namespace qwitch {

//---------------------------------------------------------------------
// 
//  
// 
//
Data::Data()
    : mTerrain()
    , mMagic()
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
    //----- 魔法データの読込み
    loadMagic();
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
    int countTerrain = 5;
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

        // 
        file.nextLine();
        int countArea = file.nextInteger();
        for (int j = 0; j < countArea; j++) {
            file.nextLine();
            int areaIndex = file.nextInteger();
            int terrainId = file.nextInteger();
            terrain.setId(areaIndex, terrainId);
        }
        terrain.setId(13, i);

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
void Data::loadMagic()
{
    //----- ファイル読込み
    char url[100];
    sprintf_s(url, "assets/data/magic.dat");
    FileReader file(url);

    //----- データ数
    file.nextLine();
    int count = file.nextInteger();

    //----- データ
    for (int i = 0; i < count; i++) {
        //--- データ読込み
        file.nextLine();
        int id = file.nextInteger();
        std::string name = file.nextString();
        int rank = file.nextInteger();

        //--- データ追加
        MagicData magic;
        magic.setId(id);
        magic.setName(name);
        magic.setRank(rank);
        int countValue = file.nextInteger();
        for (int i = 0; i < countValue; i++) {
            std::string kind = file.nextString();
            int base = file.nextInteger();
            int level = file.nextInteger();
            magic.addValue(kind, base, level);
        }
        mMagic.push_back(magic);
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
//---------------------------------------------------------------------
const MagicData& Data::magic(int aIndex) const
{
    return mMagic[aIndex];
}

} // namespace qwitch