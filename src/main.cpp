#include "ini.h"

int main(int argc, char* argv[])
{

    INIReader ini;

    ini.ReadFile("serverconfig.txt");
    ini.SaveFile("newfile.txt");
    ini.PrintFileDebug();
}