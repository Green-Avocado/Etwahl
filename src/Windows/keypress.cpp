#include "keypress.h"
#include <winuser.h>
#include <string>
#include <unordered_map>

static std::unordered_map<std::string, WORD> winKeyMap =
{
    {"Backspace", 0x08},
    {"Tab", 0x09},
    {"Return", 0x0d},
    {"Escape", 0x1b},
    {"Delete", 0x2e},
    {"Left", 0x25},
    {"Up", 0x26},
    {"Right", 0x27},
    {"Down", 0x28},
    {"Num_Lock", 0x90},
    {"Shift_L", 0x10},
    {"Control_L", 0x11},
    {"Caps_Lock", 0x14},
    {"Alt_L", 0x12},
}

void key(std::string keystring, bool keydown)
{
    INPUT inputs[1];
    ZeroMemory(inputs, sizeof(inputs));

    inputs[0].type = INPUT_KEYBOARD;
    inputs[0].ki.wVk = winKeyMap[keystring];

    if(keydown)
    {
        inputs[0].ki.dwFlags = KEYEVENTF_KEYUP;
    }

    SendInput(ARRAYSIZE(inputs), inputs, sizeof(INPUT));
}

