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
    , mAreaDisplay()
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
    //-----
    loadAreaDisplay();
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
    int countArea = 2;
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
void Data::loadAreaDisplay()
{
    //----- ファイル読込み
    char url[100];
    sprintf_s(url, "assets/data/area/display.dat");
    FileReader file(url);

    //----- データ数
    file.nextLine();
    int count = file.nextInteger();

    //----- データ
    for (int i = 0; i < count; i++) {
        AreaDisplayData data;
        file.nextLine();
        int countArea = file.nextInteger();
        for (int j = 0; j < countArea; j++) {
            file.nextLine();
            int posX = file.nextInteger();
            int posY = file.nextInteger();
            int posZ = file.nextInteger();
            int sizeX = file.nextInteger();
            int sizeY = file.nextInteger();
            int sizeZ = file.nextInteger();
            data.add(posX, posY, posZ, sizeX, sizeY, sizeZ);
        }
        mAreaDisplay.push_back(data);
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
    int groupSum = 0;

    //----- 地形データの読み込み
    int countTerrain = 2;
    for (int i = 0; i < countTerrain; i++) {
        //--- ファイルオープン
        sprintf_s(url, "assets/data/terrain/%d.dat", i);
        FileReader file(url);

        //--- ファイル読込み
        TerrainData terrain;
        terrain.set0GroupIndex(groupSum);
        // グループ
        file.nextLine();
        int countGroup = file.nextInteger();
        for (int j = 0; j < countGroup; j++) {
            file.nextLine();
            int posX = file.nextInteger();
            int posY = file.nextInteger();
            int posZ = file.nextInteger();
            int sizeX = file.nextInteger();
            int sizeY = file.nextInteger();
            int sizeZ = file.nextInteger();
            terrain.addGroup(posX, posY, posZ, sizeX, sizeY, sizeZ);
        }
        // ブロック
        file.nextLine();
        int countBlock = file.nextInteger();
        for (int j = 0; j < countBlock; j++) {
            file.nextLine();
            int x = file.nextInteger();
            int y = file.nextInteger();
            int z = file.nextInteger();
            int kind = file.nextInteger();
            terrain.addBlock(groupSum, x, y, z, kind);
        }

        //-----
        mTerrain.push_back(terrain);
        groupSum += countGroup;
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
int Data::findAreaDisplayId(const Vector3d& aPos) const
{
    int count = (int)mAreaDisplay.size();
    for (int i = 0; i < count; i++) {
        const auto& data = areaDisplay(i);
        if (data.isInclusion(aPos)) {
            return i;
        }
    }
    return -1;
}
//---------------------------------------------------------------------
// 
//  
// 
//
bool Data::isDisplay(int aId, const Vector3d& aPos) const
{
    if (aId == -1) {
        int count = (int)mAreaDisplay.size();
        for (int i = 0; i < count; i++) {
            const auto& data = areaDisplay(i);
            if (data.isInclusion(aPos)) {
                return false;
            }
        }
        return true;
    }
    else {
        const auto& data = areaDisplay(aId);
        if (data.isInclusion(aPos)) {
            return true;
        }
        return false;
    }
    return false;
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
const AreaDisplayData& Data::areaDisplay(int aId) const
{
    return mAreaDisplay[aId];
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