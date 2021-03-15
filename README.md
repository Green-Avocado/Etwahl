# Etwahl

Bind MIDI signals to keystrokes.

## Compile

```sh
mkdir build
cd build
cmake ..
make
```

The executable is found in `build/bin` from the repository root.

## Use

### Configuration
Create a config file named `etwahl.config` and place a new rule on each line.

The format of a keybind is:

```
[MIDI bytes] [keysym] [up/dn]
```

[MIDI bytes] is 6 characters including [0-9], [a-f], or x.
If 'x', the position is not checked against incoming MIDI signals.
Otherwise, the character must match the incoming signal.

[keysym] is a string representing the key to be pressed/released.
Keysyms are the same as those used by Xorg, without the `VK_` prefix.
A list of keysyms with prefixes can be found at https://www.cl.cam.ac.uk/~mgk25/ucs/keysymdef.h.

[up/dn] is either `up` or `dn` and refers to whether the key should be released or pressed.

#### Example configuration

The following `etwahl.config` file will hold `Shift_L` when the pedal is pressed, and release it when the pedal is released.

```
b0407f Shift_L up
b04000 Shift_L dn
```

### Run

Run the program from the command line in the same directory as the config file.

