/*
** EPITECH PROJECT, 2024
** B_OOP_400_LIL_4_1_arcade_achille_bourgault
** File description:
** Created by Achille Bourgault
*/

#include <functional>
#include <dlfcn.h>
#include <cstring>
#include "constants.hpp"
#include "DisplayHandler.hpp"

DisplayHandler::DisplayHandler(std::string libpath)
{
    void* libGraph = dlopen(libpath.c_str(), RTLD_LAZY);
    if (!libGraph) {
        std::cerr << "Cannot open library: " << dlerror() << std::endl;
        std::exit(84);
    }
    dlerror();
    create_t *create_lib = (create_t*) dlsym(libGraph, "create_object");
    const char* dlsym_error = dlerror();
    if (dlsym_error) {
        std::cerr << "Cannot load symbol create_object: " << dlsym_error << '\n';
        std::exit(84);
    }
    destroy_t *destroy_lib = (destroy_t*) dlsym(libGraph, "destroy_object");
    dlsym_error = dlerror();
    if (dlsym_error) {
        std::cerr << "Cannot load symbol destroy_object: " << dlsym_error << '\n';
        std::exit(84);
    }
    _currentLib = create_lib();
    if (strstr(libpath.c_str(), "lib/arcade_sfml.so"))
        _id = SFML;
    else if (strstr(libpath.c_str(), "lib/arcade_sdl2.so"))
        _id = SDL2;
    else if (strstr(libpath.c_str(), "lib/arcade_ncurses.so"))
        _id = NCURSES;
    else
        _id = -1;
    if (_id == -1) {
        std::cerr << "Incompatible library" << std::endl;
        exit(84);
    }

}

DisplayHandler::~DisplayHandler()
{
    dlclose(_currentLib);
}

DisplayHandler::DisplayHandler()
{
}

IDisplayModule *DisplayHandler::getCurrentLib() const
{
    return _currentLib;
}

int DisplayHandler::getId() const {
    return _id;
}

