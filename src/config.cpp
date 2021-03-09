#include "config.h"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

keybind lineToKeybind(std::string line)
{
    keybind newbind;
    std::stringstream lineStream;

    lineStream << line;

    lineStream >> newbind.hexBytes;
    lineStream >> newbind.keystring;

    if(strlen(newbind.hexBytes) != 6 || newbind.keystring.length() <= 0)
    {
        throw (std::string)"Invalid configuration file";
    }
    
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
                if(!std::all_of(line.begin(), line.end(), isspace))
                config.push_back(lineToKeybind(line));
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

