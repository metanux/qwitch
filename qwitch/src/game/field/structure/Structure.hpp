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
class Structure : public FieldObject {
public:
    Structure();

    /// getter
    int image() const;
private:
};

} // namespace game
} // namespace qwitch