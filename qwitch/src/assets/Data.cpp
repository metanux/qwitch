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
    : mArea()
    , mTerrain()
    , mMagic()
    , mStructure()
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
    //----- エリアデータ読込み
    loadArea();
    //----- 地形データの読込み
    loadTerrain();
    //----- 魔法データの読込み
    loadMagic();
    //----- 構造物データの読込み
    loadStructure();
}

//---------------------------------------------------------------------
// 
//  
// 
//
void Data::loadArea()
{
    //-----
    char url[100];

    //-----
    int countArea = 1;
    for (int i = 0; i < countArea; i++) {
        //--- ファイルオープン
        sprintf_s(url, "assets/data/area/%d.dat", i);
        FileReader file(url);

        //----- ファイル読込み
        AreaData area;
        // (0,0,0)の座標
        file.nextLine();
        int x = file.nextInteger();
        int y = file.nextInteger();
        int z = file.nextInteger();
        area.setPos(Vector3d(x, y, z));
        // 近傍のID
        file.nextLine();
        int countArea = file.nextInteger();
        for (int j = 0; j < countArea; j++) {
            file.nextLine();
            int areaIndex = file.nextInteger();
            int terrainId = file.nextInteger();
            area.setId(areaIndex, terrainId);
        }
        area.setId(13, i);
        // 構造物
        file.nextLine();
        int countStructure = file.nextInteger();
        for (int j = 0; j < countStructure; j++) {
            file.nextLine();
            int x = file.nextInteger();
            int y = file.nextInteger();
            int z = file.nextInteger();
            int kind = file.nextInteger();
            area.addStructure(Vector3d(x, y, z), kind);
        }

        //----- 追加
        mArea.push_back(area);
    }
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
void Data::loadStructure()
{
    //----- ファイル読込み
    char url[100];
    sprintf_s(url, "assets/data/structure.dat");
    FileReader file(url);

    //----- データ数
    file.nextLine();
    int count = file.nextInteger();

    //----- データ
    for (int i = 0; i < count; i++) {
        //--- データ読込み
        file.nextLine();
        int id = file.nextInteger();
        int sizeX = file.nextInteger();
        int sizeY = file.nextInteger();
        int sizeZ = file.nextInteger();
        mStructure.push_back(StructureData(
            sizeX,
            sizeY,
            sizeZ));
    }
}

//---------------------------------------------------------------------
// 
//  
// 
//
const AreaData& Data::area(int aId) const
{
    return mArea[aId];
}
//---------------------------------------------------------------------
const TerrainData& Data::terrain(int aId) const
{
    return mTerrain[aId];
}
//---------------------------------------------------------------------
const MagicData& Data::magic(int aId) const
{
    return mMagic[aId];
}
//---------------------------------------------------------------------
const StructureData& Data::structure(int aId) const
{
    return mStructure[aId];
}

} // namespace qwitch