#ifndef CONFIG_H
#define CONFIG_H

#include <string>
#include <vector>

typedef struct keybind {
    char bytesHex[6];
    std::string keystring;
} keybind;

std::vector<keybind> loadConfig(std::string filename);

#endif

