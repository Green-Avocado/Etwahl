#include <X11/Xlib.h>
#include <X11/keysym.h>
#include <X11/extensions/XTest.h>

void key(char *key, bool keydown)
{
    Display *display;
    display = XOpenDisplay(NULL);

    unsigned int keycode;
    unsigned int keysym = XStringToKeysym(key);

    keycode = XKeysymToKeycode(display, keysym);
    XTestFakeKeyEvent(display, keycode, keydown, 0);
    XFlush(display);
}

