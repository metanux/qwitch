//---------------------------------------------------------------------
// 
//  
// 
//
#include "Images.hpp"
#include "DxLib.h"

namespace qwitch {

//---------------------------------------------------------------------
// 
//  
// 
//
Images::Images()
    : mBlock()
    , mChara()
    , mMonster()
    , mTitleBack()
{
}

//---------------------------------------------------------------------
// 
//  
// 
//
Images& Images::ins()
{
    static Images instance;
    return instance;
}

//---------------------------------------------------------------------
// 
//  
// 
//
void Images::load()
{

}

//---------------------------------------------------------------------
// 
//  
// 
//
int Images::block(int aIndex) const
{
    return mBlock[aIndex];
}
//---------------------------------------------------------------------
int Images::chara(int aKind, int aIndex) const
{
    return mChara[aKind][aIndex];
}
//---------------------------------------------------------------------
int Images::monster(int aKind, int aIndex) const
{
    return mMonster[aKind][aIndex];
}
//---------------------------------------------------------------------
int Images::titleBack() const
{
    return mTitleBack;
}

} // namespace qwitch