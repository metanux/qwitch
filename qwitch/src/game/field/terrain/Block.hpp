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
    Block();
    int image() const;

    /// getter

private:
    /// member
};

} // namespace game
} // namespace qwitch