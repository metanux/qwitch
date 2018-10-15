//---------------------------------------------------------------------
// 
//  
// 
//
#pragma once
#include "game/field/Field.hpp"

namespace qwitch {
namespace game {

//---------------------------------------------------------------------
// 
//  
// 
//
class FieldRender {
public:
    FieldRender();
    void render(const Field& aField) const;
private:
};

} // namespace game
} // namespace qwitch