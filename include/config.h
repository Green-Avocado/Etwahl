#ifndef CONFIG_H
#define CONFIG_H

#include <vector>

typedef struct {
    const char bytes[7];
    const char keystring[16];
} keybind;

std::vector<keybind> loadConfig(char* filename);

#endif

