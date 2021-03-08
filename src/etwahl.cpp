#include "keypress.h"
#include "RtMidi.h"

#include <chrono>
#include <iomanip>
#include <iostream>
#include <thread>

#include <cstdlib>
#include <csignal>

bool done;

static void finish(int ignore)
{
    done = true;
}

void midiHandler(double timeStamp, std::vector< unsigned char > *message, void *userData)
{
    int nBytes;
    nBytes = message->size();

    for(int i = 0; i < nBytes; i++)
        std::cout <<
            "Byte " << i << " = " << 
            std::setw(2) << std::setfill('0') << std::hex << (int)message->at(i) << ", ";

    std::cout << "stamp = " << timeStamp << std::endl;
}

int main()
{
    RtMidiIn *midiin = new RtMidiIn();
    std::vector<unsigned char> message;
    int portNum;
    double stamp;

    // Set MidiIn callback.
    midiin->setCallback(midiHandler);

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
    std::cout << "Reading MIDI from port " << portNum + 1 << "... quit with Ctrl-C.\n";

    // Don't ignore sysex, timing, or active sensing messages.
    midiin->ignoreTypes(false, false, false);

    // Install an interrupt handler function.
    done = false;
    (void) signal(SIGINT, finish);

    while(!done)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    // Clean up
    cleanup:
        delete midiin;

    return 0;
}

