/*
** EPITECH PROJECT, 2024
** B_OOP_400_LIL_4_1_arcade_achille_bourgault
** File description:
** Created by Achille Bourgault
*/

#include <fstream>
#include <cstring>
#include "Arcade.hpp"

char *isValidLibrary(char *libpath)
{
    std::string lib(libpath);
    std::ifstream file(lib.c_str());

    if (!file || (!strstr(libpath, ".so") && !strstr(libpath, ".dylib")))
        return nullptr;
    return libpath;
}

int usage()
{
    std::cout << "ARCADE USAGE" << std::endl;
    std::cout << "  ./arcade ./libs/<name>.so" << std::endl;
    return 0;
}

int invalidLibrary()
{
    std::cerr << "Error: The dynamic library doesn't exist or is incompatible."
        << std::endl;
    return 84;
}

int main(int ac, char **av)
{
    char *libpath;

    if (ac != 2){
        usage();
        return 84;
    }
    if (ac >= 2) {
        if ((libpath = isValidLibrary(av[1])) != nullptr) {
            Arcade core = Arcade(libpath);
        } else
            return invalidLibrary();
    } else
        return usage();
    return 0;
}


