#include "config.h"

#include "catch.hpp"

#include <fstream>
#include <string>
#include <vector>
#include <cstdio>

std::vector<keybind> testConfigFile(std::string contents)
{
    const std::string filename = "test.config~";
    std::ofstream testfile;
    std::vector<keybind> config;

    testfile.open(filename);

    if(testfile.is_open())
    {
        testfile << contents;
        testfile.close();
    }
    else
    {
        throw;
    }

    config = loadConfig(filename);
    
    std::remove(filename.c_str());

    return config;
}

TEST_CASE("Configuration file read and interpreted", "[config]")
{
    REQUIRE(testConfigFile("") == std::vector<keybind> {});
}

