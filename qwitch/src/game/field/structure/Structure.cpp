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
    addImage(0);
}

//---------------------------------------------------------------------
// 
//  
// 
//
void Structure::update()
{
    FieldObject::update();

    int handl = Images::ins().structure(kind());
    setImageHandl(0, handl);
    setImagePos(0, pos());
    setImageSize(0, size());
}

} // namespace game
} // namespace qwitch