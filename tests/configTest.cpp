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
    REQUIRE(testConfigFile("") ==
            std::vector<keybind> {});

    REQUIRE(testConfigFile("xxxxxx A") ==
            std::vector<keybind> {keybind {{'x','x','x','x','x','x'}, "A"}});

    REQUIRE(testConfigFile("a1b2c3 Shift_L") ==
            std::vector<keybind> {keybind {{'a','1','b','2','c','3'}, "Shift_L"}});

    REQUIRE(testConfigFile("xxxxxx A\nxxxxxx B") ==
            std::vector<keybind>
            {
                keybind {{'x','x','x','x','x','x'}, "A"},
                keybind {{'x','x','x','x','x','x'}, "B"},
            });

    REQUIRE(testConfigFile("a1b2c3 Shift_L\nd4e5f6 Control_R") ==
            std::vector<keybind>
            {
                keybind {{'a','1','b','2','c','3'}, "Shift_L"},
                keybind {{'d','4','e','5','f','6'}, "Control_R"},
            });
}

