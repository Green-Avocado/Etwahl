#include "keypress.h"

#include <X11/Xlib.h>
#include <X11/keysym.h>
#include <X11/extensions/XTest.h>

#include <string>

void key(std::string keystring, bool keydown)
{
    Display *display;
    display = XOpenDisplay(NULL);

    unsigned int keycode;
    unsigned int keysym = XStringToKeysym(keystring.c_str());

    keycode = XKeysymToKeycode(display, keysym);
    XTestFakeKeyEvent(display, keycode, keydown, 0);
    XFlush(display);
}

