#include "config.h"
#include "keypress.h"
#include "RtMidi.h"

#include <chrono>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <thread>
#include <vector>

#include <climits>
#include <csignal>
#include <cstdlib>

static RtMidiIn *midiin;

static void cleanup()
{
    delete midiin;
}

static void interruptHandler(int)
{
    cleanup();
    std::cout << "Terminated normally." << std::endl;
    exit(0);
}

static void fatalErrorHandler()
{
    cleanup();
    std::cout << "Terminated due to fatal error." << std::endl;
    exit(1);
}

void midiHandler(double timeStamp, std::vector< unsigned char > *message, void*)
{
    int nBytes;
    nBytes = message->size();

    for(int i = 0; i < nBytes; i++)
    {
        std::cout << std::setw(2) << std::setfill('0') << std::hex << (int)message->at(i);
    }

    std::cout << "  " << timeStamp << std::endl;

    const char *keystring = "Shift_L";

    if((int)message->at(2) == 127)
    {
        key(keystring, true);
    }
    else
    {
        key(keystring, false);
    }
}

int main()
{
    unsigned int nPorts;
    unsigned int portNum;

    (void) signal(SIGINT, interruptHandler);

    try
    {
        midiin = new RtMidiIn();
        midiin->setCallback(midiHandler);
        nPorts = midiin->getPortCount();
    }
    catch(RtMidiError &error)
    {
        fatalErrorHandler();
    }

    std::cout << "\nThere are " << nPorts << " MIDI input sources available.\n";

    for(unsigned int i = 0; i < nPorts; i++)
    {
        try
        {
            std::cout << "  Input Port " << i + 1 << ": " << midiin->getPortName(i) << '\n';
        }
        catch(RtMidiError &error)
        {
            fatalErrorHandler();
        }
    }

    std::cin >> portNum;

    try
    {
        midiin->openPort(portNum - 1);
    }
    catch(RtMidiError &error)
    {
        fatalErrorHandler();
    }

    std::cout << "Reading MIDI from port " << portNum << "... Press Enter to quit.\n";

    std::cin.ignore(INT_MAX, '\n');
    std::cin.get();

    cleanup();
    std::cout << "Terminated normally." << std::endl;

    return 0;
}

