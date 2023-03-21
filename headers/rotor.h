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
        string m_ID;
        array<int,26> m_wiring;
        int m_ringPosition;
        char m_rotorPosition;
        char m_turnover;

    // Constructors
    public:
        Rotor(const string rotorID="I", const int ringPosition= 1, const char rotorPosition= 'A');
    // Accessors
    public:
        void select(const string);
        void setRing(const int);
        bool setPosition(const char);
        string ID() const;
        char position() const;
    // Methods
    public:
        int leftward(const int&) const;
        int rightward(const int&) const;
        char output(const int&) const;
        bool rotate();
};

class Reflector
//
// Define reflectors of Enigma machine
//
{
    // Attributes
    protected:
        string m_ID;
        array<int,26> m_wiring;
    //Constructors
    public:
        Reflector(const string reflectorID= "A");

    // Accessors
    public:
        void select(const string);
        string ID() const;

    // Methods
    public:
        int leftward(const int&) const;
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