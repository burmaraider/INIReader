#include "INIReader.h"

int main(int argc, char* argv[])
{

    INIReader ini;

    ini.ReadFile("configfile.txt");
    ini.AddSection("NewSection");
    ini.AddKeyValue("NewSection", "NewKey", "NewValue");
    std::string tempValue = ini.GetValueFromKey("NewSection", "NewKey");
    ini.SaveFile("newconfigfile.txt");
    ini.PrintFileDebug();
}