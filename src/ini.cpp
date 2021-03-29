#include "ini.h"

INIReader::INIReader()
{
    return;
}
bool INIReader::ReadFile(std::string szFileName)
{
    std::ifstream file(szFileName);
    std::string line;
    std::string szTokens[2];
    std::string szSectionString = "";
    bool result = false;
    while(std::getline(file, line))
    {
        if(line.size() > 0 && line.rfind(';') == -1 && line.rfind('#') == -1)
        {
            if(!line.rfind('['))
            {
                //found our section
                int pEnd = line.find_first_of(']');
                szSectionString = line.substr(1, pEnd - 1);
                AddSection(szSectionString);
            }
            else
            {
                //things!
                int lStart = 0;
                int lEnd = line.find('=');
                while(lEnd != std::string::npos)
                {
                    szTokens[0] = trim(line.substr(lStart, lEnd - lStart));
                    lStart = lEnd + 1;
                    lEnd = line.find(1, lStart);
                }
                szTokens[1] = trim(line.substr(lStart, lEnd));

                //Check if we have a key starting without a [Section]
                if(szSectionString.empty())
                    return false;
                //Now that we have clean keys and values lets go
                AddKeyValue(szSectionString, szTokens[0], szTokens[1]);
                //result = true;
            }
        }
    }
    return result;
}
bool INIReader::SaveFile(std::string szFileName)
{
    std::ofstream file(szFileName);

    if(!file.is_open()) 
        return false;

    for (int i = 0; i < sectionList.size(); i++)
    {
        file << "[" << sectionList[i].szSectionName << "]\n";   //Write the section
        
        for (int t = 0; t < keyValueList.size(); t++)
        {
            if(keyValueList[t].sParent.szSectionName == sectionList[i].szSectionName)
                file << keyValueList[t].szKey << " = " << keyValueList[t].szValue << "\n";  //Write the key/value pair
        }
        file << "\n";
    }

    file.close();
    return true; 
}
void INIReader::PrintFileDebug()
{

    if(sectionList.size() == 0 && keyValueList.size() == 0)
        return;

    for (int i = 0; i < sectionList.size(); i++)
    {
        printf("[%s]\n", sectionList[i].szSectionName.c_str());
        
        for (int t = 0; t < keyValueList.size(); t++)
        {
            if(keyValueList[t].sParent.szSectionName == sectionList[i].szSectionName)
                printf("%s = %s\n",keyValueList[t].szKey.c_str(), keyValueList[t].szValue.c_str());
        }
        printf("\n");
    }

}
bool INIReader::AddSection (std::string szSection)
{
    //ensure our section name is not already defined
    for (size_t i = 0; i < sectionList.size(); i++)
    {
        if(sectionList[i].szSectionName == szSection)
            return false;
    }

    //no matches, lets add the section
    _Section myNewSection;
    myNewSection.szSectionName = szSection;
    sectionList.push_back(myNewSection);
    //printf("Section: [%s] added\n", szSection.c_str());
    return true;
}
bool INIReader::AddKeyValue (std::string szSectionName, std::string szKey, std::string szValue)
{
    for (int i = 0; i < sectionList.size(); i++)
    {
        if(trim(szSectionName) == trim(sectionList[i].szSectionName))
        {   
            _KeyValue myNewKeyValue;
            myNewKeyValue.sParent = sectionList[i];
            myNewKeyValue.szKey = szKey;
            myNewKeyValue.szValue = szValue;
            
            keyValueList.push_back(myNewKeyValue);
            return true;
        }
    }
    return false;
}
bool INIReader::RemoveKeyValueFromSection(std::string szSectionName, std::string szKey)
{
    for (int i = 0; i < keyValueList.size(); i++)
    {
        if(szSectionName == keyValueList[i].sParent.szSectionName)
        {
            //found a match lets remove it
            keyValueList.erase(keyValueList.begin() + i);
            return true;
        }
    }
    return false;
}
int INIReader::RemoveSection(std::string szSectionName)
{
    int removeCount = 0;
    for (int i = 0; i < sectionList.size(); i++)
    {
        if(szSectionName == sectionList[i].szSectionName)
        {
            for (int t = 0; t < keyValueList.size(); t++)
            {
                if(keyValueList[t].sParent.szSectionName == szSectionName)
                {
                    keyValueList.erase(keyValueList.begin() + t);
                    removeCount++;
                }
            }
            sectionList.erase(sectionList.begin() + i);
            removeCount++;
        }
    }
    return removeCount;
}
std::string INIReader::GetValueFromKey(std::string szSectionName, std::string szKey)
{
    std::string result = "";
    for (int i = 0; i < keyValueList.size(); i++)
    {
        if(keyValueList[i].sParent.szSectionName == szSectionName && keyValueList[i].szKey == szKey)
                result = keyValueList[i].szValue;
    }
    return result;
}
std::string INIReader::ltrim(const std::string& s)
{
    size_t start = s.find_first_not_of(WHITESPACE);
    return (start == std::string::npos) ? "" : s.substr(start);
}
std::string INIReader::rtrim(const std::string& s)
{
    size_t end = s.find_last_not_of(WHITESPACE);
    return (end == std::string::npos) ? "" : s.substr(0, end + 1);
}
std::string INIReader::trim(const std::string& s)
{
    return rtrim(ltrim(s));
}