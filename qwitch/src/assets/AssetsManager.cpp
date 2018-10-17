//---------------------------------------------------------------------
// 
//  
// 
//
#include "AssetsManager.hpp"
#include "DxLib.h"
#include "assets/Images.hpp"
#include "assets/Data.hpp"

namespace qwitch {

//---------------------------------------------------------------------
// 
//  
// 
//
AssetsManager::AssetsManager()
{

}


//---------------------------------------------------------------------
// 
//  
// 
//
AssetsManager& AssetsManager::ins()
{
    static AssetsManager instance;
    return instance;
}

//---------------------------------------------------------------------
// 
//  
// 
//
void AssetsManager::load()
{
    //----- データ読込み
    Data::ins().load();

    //----- 画像読込み
    Images::ins().load();
}

} // namespace qwitch