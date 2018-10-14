//---------------------------------------------------------------------
// 
//  
// 
//
#include "TitleRender.hpp"
#include "DxLib.h"
#include "assets/Images.hpp"
#include "system/System.hpp"

namespace qwitch {
namespace title {

//---------------------------------------------------------------------
// 
//  
// 
//
TitleRender::TitleRender()
{
}

//---------------------------------------------------------------------
// 
//  
// 
//
void TitleRender::render(const Title& aTitle) const
{
    DxLib::DrawGraph(0, 0, Images::ins().titleBack(), TRUE);
}

} // namespace title
} // namespace qwitch