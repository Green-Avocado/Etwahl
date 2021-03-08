#include "RtMidi.h"

#include <chrono>
#include <thread>
#include <iostream>
#include <cstdlib>
#include <signal.h>

bool done;
static void finish(int ignore){ done = true; }

int main()
{
    RtMidiIn *midiin = new RtMidiIn();
    std::vector<unsigned char> message;
    int portNum;
    int nBytes;
    double stamp;

    // Check inputs.
    unsigned int nPorts = midiin->getPortCount();
    std::cout << "\nThere are " << nPorts << " MIDI input sources available.\n";
    std::string portName;

    for (int i=0; i < nPorts; i++) {
        try {
            portName = midiin->getPortName(i);
        }
        catch ( RtMidiError &error ) {
            error.printMessage();
            goto cleanup;
        }
        std::cout << "  Input Port #" << i+1 << ": " << portName << '\n';
    }

    // Get port number.
    std::cin >> portNum;
    portNum--;

    midiin->openPort(portNum);

    // Don't ignore sysex, timing, or active sensing messages.
    midiin->ignoreTypes(false, false, false);

    // Install an interrupt handler function.
    done = false;
    (void) signal(SIGINT, finish);

    // Periodically check input queue.
    std::cout << "Reading MIDI from port " << portNum + 1 << "... quit with Ctrl-C.\n";

    while(!done) {
        stamp = midiin->getMessage(&message);
        nBytes = message.size();

        for(int i = 0; i < nBytes; i++)
            std::cout << "Byte " << i << " = " << (int)message[i] << ", ";

        if(nBytes > 0)
            std::cout << "stamp = " << stamp << std::endl;

        // Sleep for 10 milliseconds ... platform-dependent.
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }

    // Clean up
    cleanup:
        delete midiin;

    return 0;
}

