//---------------------------------------------------------------------
// 
//  
// 
//
#pragma once
#include "game/field/FieldObject.hpp"

namespace qwitch {
namespace game {

//---------------------------------------------------------------------
// 
//  
// 
//
class Block : public FieldObject {
public:
    static const int PIXEL_SIZE;

    Block();

    int image() const;

    /// getter

private:
    /// member
};

} // namespace game
} // namespace qwitch