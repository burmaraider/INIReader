#include "ini.h"

int main(int argc, char* argv[])
{

    INIReader ini;

    ini.ReadFile("serverconfig.txt");
    printf("My value I need is: %s", ini.GetValueFromKey("Settings", "Fullscreen").c_str());
}