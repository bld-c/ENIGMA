#include<iostream>
#include<iomanip>
#include<string>
#include"rotor.h"
#include"plugboard.h"

class Enigma
//
// Define Enigma machine
//
{
    // Attributes
    protected:
        EntryWheel m_etw;
        Rotor m_rotor1, m_rotor2, m_rotor3;
        Reflector m_ukw;
        Plugboard m_plugboard;
        bool m_ready;
        bool m_turnRotor1, m_turnRotor2;

    // Constructor
    public:
        Enigma();

    // Accessors
    public:
        void selectRotor(const int&, const string&);
        void setRotorRing(const int&, const int&);
        void setRotorPosition (const int&, const char&);
        inline void selectReflector(const string& reflectorID) {return m_ukw.select(reflectorID);};
        inline void plugCable(int cableID,char letter1,char letter2) {return m_plugboard.plug(cableID,letter1,letter2);};
        void unplugCable(int cableID) {return m_plugboard.unplug(cableID);};
        ostream& getConfig(ostream&);

    // Methods
    public:
        string ciphering(const string&);
        inline string deciphering(const string& msg) {return ciphering(msg);};
    private:
        void checkConfig();
        char processChar(const char&);
};