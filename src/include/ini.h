#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <fstream>

class INIReader
{

    typedef struct _Section
    {
        std::string szSectionName;
    }SECTION;

    typedef struct _KeyValue
    {
        std::string szKey;
        std::string szValue;
        struct _Section sParent;
    }KEYVALUE;


  //Public
  public:
    INIReader();

    bool ReadFile(std::string szFileName);
    bool SaveFile(std::string szFileName);
    void PrintFileDebug();

    bool AddSection(std::string szSectionName);
    bool AddKeyValue(std::string szSectionName, std::string szKey, std::string szValue);

    bool RemoveKeyValueFromSection(std::string szSectionName, std::string szKey);
    int RemoveSection(std::string szSectionName);

    std::string GetValueFromKey(std::string szSectionName, std::string szKey);


  private:
    const std::string WHITESPACE = " \n\r\t\f\v";
    std::vector<_Section> sectionList;
    std::vector<_KeyValue> keyValueList;
    std::string ltrim(const std::string& s);
    std::string rtrim(const std::string& s);
    std::string trim(const std::string& s);

};