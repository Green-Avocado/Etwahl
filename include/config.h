#ifndef CONFIG_H
#define CONFIG_H

#include <string>
#include <vector>
#include <cstring>

typedef struct keybind {
    char hexBytes[8];
    std::string keystring;

    bool operator==(const keybind& other) const
    {
        bool bytesMatch = (strncmp(hexBytes, other.hexBytes, 6) == 0);
        bool stringsMatch = (keystring == other.keystring);
        return bytesMatch && stringsMatch;
    }
} keybind;

std::vector<keybind> loadConfig(std::string filename);

#endif

