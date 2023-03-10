#ifndef PLUGBOARD_H
#define PLUGBOARD_H

#include<iostream>
#include<array>
#include<cassert>

using namespace std;

class Plugboard
//
// Define plugboard of Enigma machine
//
{
    // Attributes
    protected:
        array<char,26> m_plugboard;
        array<char,26> m_plugcables;

    // Constructors
    public:
        Plugboard();

    // Methods
    public:
        char ciphering(const char) const;
        void plug(int, char, char);
        void unplug(int);
};
#endif
