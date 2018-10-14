//---------------------------------------------------------------------
// 
//  
// 
//
#pragma once
#include "title/Title.hpp"

namespace qwitch {
namespace title {

//---------------------------------------------------------------------
// 
//  
// 
//
class TitleRender {
public:
    TitleRender();
    void render(const Title& aTitle) const;
private:
};

} // namespace title
} // namespace qwitch