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
class Character : public FieldObject {
public:
    Character();

    int image() const;

    /// getter

private:
};

} // namespace game
} // namespace qwitch