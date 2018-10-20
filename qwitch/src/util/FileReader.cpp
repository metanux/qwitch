//---------------------------------------------------------------------
// 
//  
// 
//
#include "FileReader.hpp"
#include "DxLib.h"

namespace qwitch {

//---------------------------------------------------------------------
// 
//  
// 
//
FileReader::FileReader(char* aUrl)
{
    //----- ファイルオープン
    mFilePointer = FileRead_open(aUrl);
    if (mFilePointer == 0) {
        printfDx("ファイルデータ %s の読み込みに失敗しました\n", aUrl);
    }
}

//---------------------------------------------------------------------
// 
//  
// 
//
FileReader::~FileReader()
{
    FileRead_close(mFilePointer);
}

//---------------------------------------------------------------------
// 
//  -1：エラー
// 
//
int FileReader::nextLine()
{
    //-----
    char str[1024];
    int result = FileRead_gets(str, 256, mFilePointer);
    mStringLine.clear();
    mStringLine.str(str);

    //-----
    return result;
}

//---------------------------------------------------------------------
// 
//  
// 
//
int FileReader::nextInteger()
{
    std::string stringWord;
    mStringLine >> stringWord;
    return std::atoi(stringWord.c_str());
}

//---------------------------------------------------------------------
// 
//  
// 
//
double FileReader::nextDouble()
{
    std::string stringWord;
    mStringLine >> stringWord;
    return std::atof(stringWord.c_str());
}

//---------------------------------------------------------------------
// 
//  
// 
//
std::string FileReader::nextString()
{
    std::string stringWord;
    mStringLine >> stringWord;
    return stringWord;
}

} // namespace qwitch