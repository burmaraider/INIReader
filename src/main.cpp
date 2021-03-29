#include "INIReader.h"

int main(int argc, char* argv[])
{

    INIReader ini;

    ini.ReadFile("serverconfig.txt");
    ini.SaveFile("newfile.txt");
    std::string temp = ini.GetValueFromKey("WeaponBan", "shotgun");
    ini.PrintFileDebug();
    printf("\n\nSelected from section: [WeaponBan]\n"
           "                       |_Key: shotgun\n"
           "                       |_Value: %s\n", temp.c_str());
}