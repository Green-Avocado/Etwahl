#include <X11/Xlib.h>
#include <X11/keysym.h>
#include <X11/extensions/XTest.h>

void key(char key, bool keydown)
{
    Display *display;
    unsigned int keycode;
    display = XOpenDisplay(NULL);

    //keysym = XStringToKeysym(c);
    keycode = XKeysymToKeycode(display, XK_Pause);
    XTestFakeKeyEvent(display, keycode, keydown, 0);
    XFlush(display);
}

