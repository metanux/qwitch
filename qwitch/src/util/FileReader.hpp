//---------------------------------------------------------------------
// 
//  
// 
//
#pragma once
#include <string>
#include <sstream>

namespace qwitch {

//---------------------------------------------------------------------
// 
//  
// 
//
class FileReader {
public:
    FileReader(char* aUrl);
    ~FileReader();
    int nextLine();
    int nextInteger();
    double nextDouble();
    std::string nextString();

private:
    int mFilePointer;
    std::stringstream mStringLine;
};

} // namespace qwitch