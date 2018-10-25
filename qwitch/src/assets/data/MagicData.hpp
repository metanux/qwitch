//---------------------------------------------------------------------
// 
//  
// 
//
#pragma once
#include <vector>
#include <map>
#include "util/Vector3d.hpp"

namespace qwitch {

//---------------------------------------------------------------------
// 
//  
// 
//
class MagicData {
public:
    /// コンストラクタ
    MagicData();

    /// setter
    void setId(int aId);
    void setName(std::string aName);
    void setRank(int aId);
    void addValue(std::string aKind, int aBase, int aLevel);


    /// getter
    int id() const;
    std::string name() const;
    int rank() const;
    int value(std::string aKind, int aLevel) const;

private:
    /// member
    /// ID
    int mId;
    /// 名前
    std::string mName;
    /// ランク
    int mRank;
    ///
    std::map<std::string, int> mValueIndex;
    /// その他の値-基礎
    std::vector<int> mValueBase;
    /// その他の値-レベル
    std::vector<int> mValueLevel;
};

} // namespace qwitch