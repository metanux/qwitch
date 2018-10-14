//---------------------------------------------------------------------
// 
//  
// 
//
#include "AssetsManager.hpp"
#include "DxLib.h"
#include "assets/Images.hpp"

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
    //----- 画像読み込み
    Images::ins().load();
}

} // namespace qwitch