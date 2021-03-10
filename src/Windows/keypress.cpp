#include "keypress.h"
#include <winuser.h>
#include <string>
#include <unordered_map>

static std::unordered_map<std::string, WORD> winKeyMap =
{
    {"Backspace", 0x08},
    {"Tab", 0x09},
    {"Return", 0x0D},
    {"Escape", 0x1B},
    {"Delete", 0x2E},

    {"Left", 0x25},
    {"Up", 0x26},
    {"Right", 0x27},
    {"Down", 0x28},

    {"Num_Lock", 0x90},
    {"Caps_Lock", 0x14},

    {"Shift_L", 0xA0},
    {"Shift_R", 0xA1},
    {"Control_L", 0xA2},
    {"Control_R", 0xA3},
    {"Alt_L", 0xA4},
    {"Alt_R", 0xA5},
    {"Super_L", 0x5B},
    {"Super_R", 0x5C},

    {"A", 0x41},
    {"B", 0x42},
    {"C", 0x43},
    {"D", 0x44},
    {"E", 0x45},
    {"F", 0x46},
    {"G", 0x47},
    {"H", 0x48},
    {"I", 0x49},
    {"J", 0x4A},
    {"K", 0x4B},
    {"L", 0x4C},
    {"M", 0x4D},
    {"N", 0x4E},
    {"O", 0x4F},
    {"P", 0x50},
    {"Q", 0x51},
    {"R", 0x52},
    {"S", 0x53},
    {"T", 0x54},
    {"U", 0x55},
    {"V", 0x56},
    {"W", 0x57},
    {"X", 0x58},
    {"Y", 0x59},
    {"Z", 0x5A},

    {"0", 0x30},
    {"1", 0x31},
    {"2", 0x32},
    {"3", 0x33},
    {"4", 0x34},
    {"5", 0x35},
    {"6", 0x36},
    {"7", 0x37},
    {"8", 0x38},
    {"9", 0x39},

    {"KP_0", 0x60},
    {"KP_1", 0x61},
    {"KP_2", 0x62},
    {"KP_3", 0x63},
    {"KP_4", 0x64},
    {"KP_5", 0x65},
    {"KP_6", 0x66},
    {"KP_7", 0x67},
    {"KP_8", 0x68},
    {"KP_9", 0x69},
};

void key(std::string keystring, bool keydown)
{
    INPUT input;

    input.type = INPUT_KEYBOARD;
    input.ki.wVk = winKeyMap[keystring];
    input.ki.wScan = 0;
    input.ki.time = 0;
    input.ki.dwExtraInfo = 0;

    if(keydown)
    {
        input.ki.dwFlags = 0;
    }
    else
    {
        input.ki.dwFlags = KEYEVENTF_KEYUP;
    }

    SendInput(1, &input, sizeof(INPUT));
}

