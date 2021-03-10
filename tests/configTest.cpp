#include "config.h"

#include "catch.hpp"

#include <fstream>
#include <string>
#include <vector>
#include <cstdio>

bool operator==(const keybind& a, const keybind& b)
{
    bool bytesMatch = (strncmp(a.hexBytes, b.hexBytes, 6) == 0);
    bool stringsMatch = (a.keystring == b.keystring);
    bool keydownMatch = (a.keydown == b.keydown);

    return bytesMatch && stringsMatch && keydownMatch;
}


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

    try
    {
        config = loadConfig(filename);
    }
    catch(...)
    {
        std::remove(filename.c_str());
        throw;
    }

    return config;
}

TEST_CASE("Configuration file read and interpreted", "[config]")
{
    CHECK(testConfigFile("") ==
            std::vector<keybind> {});

    CHECK(testConfigFile(" xxxxxx A up") ==
            std::vector<keybind> {keybind {{'x','x','x','x','x','x'}, "A", false}});

    CHECK(testConfigFile("\nxxxxxx A up") ==
            std::vector<keybind> {keybind {{'x','x','x','x','x','x'}, "A", false}});

    CHECK(testConfigFile("\txxxxxx A up") ==
            std::vector<keybind> {keybind {{'x','x','x','x','x','x'}, "A", false}});

    CHECK(testConfigFile("xxxxxx A up") ==
            std::vector<keybind> {keybind {{'x','x','x','x','x','x'}, "A", false}});

    CHECK(testConfigFile("a1b2c3 Shift_L up") ==
            std::vector<keybind> {keybind {{'a','1','b','2','c','3'}, "Shift_L", false}});

    CHECK(testConfigFile("xxxxxx A up\nxxxxxx B dn") ==
            std::vector<keybind>
            {
                keybind {{'x','x','x','x','x','x'}, "A", false},
                keybind {{'x','x','x','x','x','x'}, "B", true},
            });

    CHECK(testConfigFile("a1b2c3 Shift_L up\nd4e5f6 Control_R dn") ==
            std::vector<keybind>
            {
                keybind {{'a','1','b','2','c','3'}, "Shift_L", false},
                keybind {{'d','4','e','5','f','6'}, "Control_R", true},
            });

    CHECK_THROWS(testConfigFile("xxxxxx"));

    CHECK_THROWS(testConfigFile("xxxxxxx"));

    CHECK_THROWS(testConfigFile("xxxxxxx A"));

    CHECK_THROWS(testConfigFile("xxxxxx A"));

    CHECK_THROWS(testConfigFile("xxxxxx A B"));
}

