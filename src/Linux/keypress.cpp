#include <X11/Xlib.h>
#include <X11/keysym.h>
#include <X11/extensions/XTest.h>

void press()
{
    Display *display;
    unsigned int keycode;
    display = XOpenDisplay(NULL);

    keycode = XKeysymToKeycode(display, XK_Pause);
    XTestFakeKeyEvent(display, keycode, True, 0);
    XFlush(display);
}

void release()
{
    Display *display;
    unsigned int keycode;
    display = XOpenDisplay(NULL);

    keycode = XKeysymToKeycode(display, XK_Pause);
    XTestFakeKeyEvent(display, keycode, False, 0);
    XFlush(display);
}

