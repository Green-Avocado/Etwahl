#include "config.h"
#include <fstream>
#include <iostream>
#include <vector>

std::vector<keybind> loadConfig(char* filename)
{
    std::string line;
    std::vector<keybind> config;
    std::ifstream configFile;

    configFile.open(filename);

    if(configFile.is_open())
    {
        while(getline(configFile, line))
        {
            std::cout << line << std::endl;
        }

        configFile.close();
    }
    else
    {
        std::cout << "Unable to open file." << std::endl;
    }

    return config;
}

