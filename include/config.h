#ifndef CONFIG_H
#define CONFIG_H

#include <string>
#include <vector>
#include <cstring>

typedef struct keybind {
    char hexBytes[8];
    std::string keystring;
    bool keydown;
} keybind;

std::vector<keybind> loadConfig(std::string filename);

#endif

