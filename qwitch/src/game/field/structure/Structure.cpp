//---------------------------------------------------------------------
// 
//  
// 
//
#include "Structure.hpp"
#include "DxLib.h"
#include "assets/Images.hpp"

namespace qwitch {
namespace game {

//---------------------------------------------------------------------
// 
//  
// 
//
Structure::Structure()
{
}

//---------------------------------------------------------------------
// 
//  
// 
//
int Structure::image() const
{
    return Images::ins().structure(kind());
}

} // namespace game
} // namespace qwitch