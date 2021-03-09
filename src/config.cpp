#include "config.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

keybind lineToKeybind(std::string line)
{
    keybind newbind;

    std::cout << line << std::endl;
    
    return newbind;
}

std::vector<keybind> loadConfig(std::string filename)
{
    std::string line;
    std::vector<keybind> config;
    std::ifstream configFile;
    unsigned int lineNum = 0;

    configFile.open(filename);

    if(configFile.is_open())
    {
        while(getline(configFile, line))
        {
            lineNum++;

            try
            {
                lineToKeybind(line);
            }
            catch(std::string error)
            {
                std::stringstream errorStream;
                errorStream << "Invalid config on line " << lineNum << ".";
                std::cout << "Error: " << errorStream.str() << std::endl;
                throw errorStream.str();
            }
        }

        configFile.close();
    }
    else
    {
        std::stringstream errorStream;
        errorStream << "Unable to open file " << filename << ".";
        std::cout << "Error: " << errorStream.str() << std::endl;
        throw errorStream.str();
    }

    return config;
}

