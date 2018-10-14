//---------------------------------------------------------------------
// 
//  
// 
//
#pragma once
#include <string>

namespace qwitch {

//---------------------------------------------------------------------
// 
//  
// 
//
class SceneChanger {
public:
    static SceneChanger& ins();

    /// setter
    void setSceneName(std::string aName);

    /// getter
    std::string sceneName() const;

private:
    SceneChanger();

    /// member
    std::string mSceneName; // 遷移先のシーン名
};

} // namespace qwitch