#ifndef ROTOR_H
#define ROTOR_H

#include<array>
#include<cassert>
#include<string>

using namespace std;

class Rotor
//
// Define rotors of Enigma machine
//
{
    // Attributs
    protected:
        array<int,26> m_wiring;
        int m_ringPosition;
        char m_rotorPosition;
        char m_turnover;

    // Constructors
    public:
        Rotor(const string rotorID= "I", const int ringPosition= 1, const char rotorPosition= 'A');
    
    // Methods
    public:
        virtual int leftward(const int&) const;
        int rightward(const int&) const;
        char output(const int&) const;
        bool rotate();
    // Accessors
        char position() const;
};

class Reflector : private Rotor
//
// Define reflectors of Enigma machine
//
{
    //Constructors
    public:
    Reflector (const char);

    // Methods
    public:
        virtual int leftward(const int&) const;
};

class EntryWheel
//
// Define the entry wheel of Enigma machine
//
{
    // Construtors
    public:
        EntryWheel();
    // Methods
    public:
        int leftward(const char&) const;
        char rightward (const int&) const;
};
#endif