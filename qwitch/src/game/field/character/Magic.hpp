//---------------------------------------------------------------------
// 
//  
// 
//
#pragma once

namespace qwitch {
namespace game {

//---------------------------------------------------------------------
// 
//  
// 
//
class Magic {
public:
    /// コンストラクタ
    Magic();

    /// setter
    void setId(int aId);
    void setLevel(int aLevel);

    /// getter
    int id() const;
    int level() const;
    int rank() const;
    int attack() const;
    int mp() const;
    int cast() const;

private:
    /// 魔法ID
    int mId;
    /// 魔法レベル
    int mLevel;
};

} // namespace game
} // namespace qwitch