#include"enigma.h"

Enigma::Enigma():m_ready(false),m_turnRotor1(false),m_turnRotor2(false)
//
// ENIGMA CLASS CONSTRUCTOR
//
{/*empty*/}

void Enigma::selectRotor(const int& rotorNb, const string& rotorID)
//
// SELECT ROTOR SETTER
// Choose a rotor.
// INPUT
// * rotorNb is an integer in [1,3] that gives the position of the rotor inside the Enigma machine (one is the most left one).
// * rotorID is a string that identify a rotor.
//
{
    // rotor is a pointer on one of the three rotors in the Enigma machine
    Rotor *rotor;

    switch (rotorNb)
    {
        case 1:
            rotor= &m_rotor1;
            break;
        case 2:
            rotor= &m_rotor2;
            break;
        case 3:
            rotor= &m_rotor3;
            break;
        default:
            assert(((void)"There is only three rotor in this Enigma machine",false));
    }

    // Select one wheel among five
    rotor->select(rotorID);

    // Verify that the three rotor are differents    
    checkConfig();
}

void Enigma::setRotorRing(const int& rotorNb, const int& ringPosition)
//
// SET ROTOR RING SETTER
// Accessor method to set the rotor ring position.
// INPUT
// * rotorNb is an integer in [1,3] that gives the position of the rotor inside the Enigma machine (1 is the most left one).
// * ringPos is an integer in [1,26].
//
{
    // rotor is a pointer on one of the three rotors in the machine.
    Rotor *rotor;

    switch (rotorNb)
    {
        case 1:
            rotor= &m_rotor1;
            break;
        case 2:
            rotor= &m_rotor2;
            break;
        case 3:
            rotor= &m_rotor3;
            break;
        default:
            assert(((void)"There is only three rotor in this Enigma machine",false));
    }

    // Set the ring position
    rotor->setRing(ringPosition);
}

void Enigma::setRotorPosition(const int& rotorNb, const char& rotorPosition)
//
// SET ROTOR RING SETTER
// Set the position of a rotor. 
// INPUT
// * rotorNb is an integer in [1,3] that gives the position of the rotor inside the Enigma machine (1 is most left one).
// * ringPos is an integer in [1,26].
// OUTPUT
// * setRotorPosition is a boolean that is true if the turnover character is set.
//
{
    Rotor *rotor;
    bool *turnOver;
    bool temp;

    switch (rotorNb)
    {
        case 1:
            rotor= &m_rotor1;
            turnOver= &m_turnRotor1;
            break;
        case 2:
            rotor= &m_rotor2;
            turnOver= &m_turnRotor2;
            break;
        case 3:
            rotor= &m_rotor3;
            turnOver= &temp;
            break;
        default:
            assert(((void)"There is only three rotor in this Enigma machine",false));
    }

    *turnOver= rotor->setPosition(rotorPosition);
}

string Enigma::ciphering(const string& msgIn)
//
// CIPHERING METHOD
// Cipher the input message with the current settings of the machine.
// INPUT
// * msgIn is a reference to a string of characters in [65,90] matching the uppercase alphabet A - Z.
// OUTPUT
// * msgOut is a string of characters in [65,90] matching the uppercase alphabet A - Z.
//
{
    string msgOut;
    if (m_ready)
    {
        for (string::const_iterator it= msgIn.begin() ; it<msgIn.end() ; it++)
        {
            msgOut.append(1,processChar(*it));
        }
    }
    else
    {
        cout << "The Enigma machine is not ready to cipher or decipher messages, check the settings." << endl;
    }
    return msgOut;
}

void Enigma::checkConfig()
//
// CHECK CONFIG METHOD
// Setter for the attribute m_ready
//
{
    if (
        m_rotor1.ID()!=m_rotor2.ID() && 
        m_rotor1.ID()!=m_rotor3.ID() && 
        m_rotor2.ID()!=m_rotor3.ID()
        )
    {
        m_ready= true;
    }
    else
    {
        m_ready= false;
    }
}

char Enigma::processChar(const char& charIn)
//
// PROCESS CHAR METHOD
// Process one character through the enigma machine.
// INPUT
// * charIn is a character in [65,90] matching the uppercase alphabet A - Z.
// OUPTUT
// * processChar is a character [65,90] matching the uppercase alphabet A - Z.
//
{
    // Rotation
    bool temp1= m_rotor3.rotate();
    bool temp2= false;
    if (m_turnRotor2 || m_turnRotor1)
    {
        temp2= m_rotor2.rotate();
    }
    if (m_turnRotor1)
    {
        m_rotor1.rotate();
    }
    m_turnRotor2= temp1;
    m_turnRotor1= temp2;

    // Character ciphering/deciphering
    /*cout << charIn << " ->PB-> " << m_plugboard.ciphering(charIn) 
         << " ->ETW-> " << m_etw.leftward(m_plugboard.ciphering(charIn))
         << " ->R3-> " << m_rotor3.leftward(m_etw.leftward(m_plugboard.ciphering(charIn)))
         << " ->R2-> " << m_rotor2.leftward(m_rotor3.leftward(m_etw.leftward(m_plugboard.ciphering(charIn))))
         << " ->R1-> " << m_rotor1.leftward(m_rotor2.leftward(m_rotor3.leftward(m_etw.leftward(m_plugboard.ciphering(charIn)))))
         << " ->UKW-> " << m_ukw.leftward(m_rotor1.leftward(m_rotor2.leftward(m_rotor3.leftward(m_etw.leftward(m_plugboard.ciphering(charIn))))))
         << " ->R1-> " << m_rotor1.rightward(m_ukw.leftward(m_rotor1.leftward(m_rotor2.leftward(m_rotor3.leftward(m_etw.leftward(m_plugboard.ciphering(charIn)))))))
         << " ->R2-> " << m_rotor2.rightward(m_rotor1.rightward(m_ukw.leftward(m_rotor1.leftward(m_rotor2.leftward(m_rotor3.leftward(m_etw.leftward(m_plugboard.ciphering(charIn))))))))
         << " ->R3-> " << m_rotor3.rightward(m_rotor2.rightward(m_rotor1.rightward(m_ukw.leftward(m_rotor1.leftward(m_rotor2.leftward(m_rotor3.leftward(m_etw.leftward(m_plugboard.ciphering(charIn)))))))))
         << " ->ETW-> " << m_etw.rightward(m_rotor3.rightward(m_rotor2.rightward(m_rotor1.rightward(m_ukw.leftward(m_rotor1.leftward(m_rotor2.leftward(m_rotor3.leftward(m_etw.leftward(m_plugboard.ciphering(charIn))))))))))
         << " ->PB-> " << m_plugboard.ciphering(m_etw.rightward(m_rotor3.rightward(m_rotor2.rightward(m_rotor1.rightward(m_ukw.leftward(m_rotor1.leftward(m_rotor2.leftward(m_rotor3.leftward(m_etw.leftward(m_plugboard.ciphering(charIn)))))))))))
        << endl ;*/
    return m_plugboard.ciphering(
        m_etw.rightward(m_rotor3.rightward(m_rotor2.rightward(m_rotor1.rightward(
        m_ukw.leftward(m_rotor1.leftward(m_rotor2.leftward(m_rotor3.leftward(
        m_etw.leftward(m_plugboard.ciphering(charIn)))))))))));
}

ostream& Enigma::getConfig(ostream& os)
//
// GET CONFIG METHOD
// print on the ouptut stream the current configuration of the enigma machine.
// IN/OUTPUT
// * os is a reference to an output stream.
//
{
    os << "*** Enigma machine settings ***" << endl;
    os << "         " << "Reflector" << " Rotor 1 " << " Rotor 2 " << " Rotor 3 " << endl;
    os << "ID       " << "  "
                    << m_ukw.ID() << "    "
                    << setw(3) << m_rotor1.ID() << "      "
                    << setw(3) << m_rotor2.ID() << "      "
                    << setw(3) << m_rotor3.ID() << endl;
    return os << "Position " << "             "
                            << setw(1) << m_rotor1.position() << "        "
                            << setw(1) << m_rotor2.position() << "        "
                            << setw(1) << m_rotor3.position() << endl;
}