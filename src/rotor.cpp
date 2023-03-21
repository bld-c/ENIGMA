#include"rotor.h"

Rotor::Rotor(const string rotorID, const int ringPosition, const char rotorPosition)
//
// ROTOR CLASS CONSTRUCTOR
// Initialize the given rotor with the given configuration.
// INPUTS
// * rotorID is a string that should be "I", "II", "III", "IV" or "V".
// * ringPosition is an integer that should be in [1 ; 26].
// * rotorPosition is an character that should be in [65 ; 90] corresponding to the uppercase alphabet A - Z.
//
{
    // Select a rotor among I, II, III, IV, V
    select(rotorID);

    // Configure the rotor
    setRing(ringPosition);
    setPosition(rotorPosition);
}

void Rotor::select(string rotorID)
//
// SELECT SETTER
// Select a rotor among the five available rotors of the WWII german army Enigma machine
// INPUT
// * rotorID is a string that should be "I", "II", "III", "IV" or "V".
// REFERENCE
// * https://www.cryptomuseum.com/crypto/enigma/i/index.htm#wiring
//
{
    if(rotorID=="I") // rotor I of WWII german army Enigma machine
    {
        m_ID= "I";
        array<int, 26> rotorI= {5,11,13,6,12,7,4,17,22,26,14,20,15,23,25,8,24,21,19,16,1,9,2,18,3,10};
        m_wiring= rotorI;
        m_turnover= 'Q';
    }
    else if (rotorID=="II") // rotor II of WWII german army Enigma machine
    {
        m_ID= "II";
        array<int,26> rotorII= {1,10,4,11,19,9,18,21,24,2,12,8,23,20,13,3,17,7,26,14,16,25,6,22,15,5};
        m_wiring= rotorII;
        m_turnover= 'E';
    }
    else if (rotorID=="III") // rotor III of WWII german army Enigma machine
    {
        m_ID= "III";
        array<int,26> rotorIII= {2,4,6,8,10,12,3,16,18,20,24,22,26,14,25,5,9,23,7,1,11,13,21,19,17,15};
        m_wiring= rotorIII;
        m_turnover= 'V';
    }
    else if (rotorID=="IV") // rotor IV of WWII german army Enigma machine
    {
        m_ID= "IV";
        array<int,26> rotorIV= {5,19,15,22,16,26,10,1,25,17,21,9,18,8,24,12,14,6,20,7,11,4,3,13,23,2};
        m_wiring= rotorIV;
        m_turnover= 'J';
    }
    else if (rotorID=="V") // rotor V of WWII german army Enigma machine
    {
        m_ID= "V";
        array<int,26> rotorV= {22,26,2,18,7,9,20,25,21,16,19,4,14,8,12,24,1,23,13,10,17,15,6,5,3,11};
        m_wiring= rotorV;
        m_turnover= 'Z';
    }
    else // Invalid rotor ID
    {
        assert(((void)"Invalid rotor ID",false));
    }
}

void Rotor::setRing(const int ringPosition)
//
// SET RING SETTER
// Set rotor ring position.
// INPUT
// * ringPosition is an integer that should be in [1 ; 26].
//
{
    // Ensure a valid input
    assert(((void)"ringPosition should be between 1 and 26",(ringPosition>0 && ringPosition<27)));
    // Set ring position
    m_ringPosition= ringPosition - 1;
}

bool Rotor::setPosition(const char rotorPosition)
//
// SET POSITION SETTER
// Set the rotor position
// INPUT
// * rotorPosition is an character that should be in [65 ; 90] corresponding to the uppercase alphabet A - Z.
// OUTPUT
// * setPosition is a boolean returning true if the turnover character is set.
//
{
    // Ensure a valid input
    assert(((void)"rotorPosition should be between A and Z",(rotorPosition>64 && rotorPosition<91)));
    // Set rotor position
    m_rotorPosition= rotorPosition;
    // Return rotation flag
    return m_rotorPosition==m_turnover;
}

string Rotor::ID() const
//
// ID GETTER
//
{
    return m_ID;
}

char Rotor::position() const
//
// POSITION GETTER
//
{
    return m_rotorPosition;
}

int Rotor::leftward(const int &index) const
//
// LEFTWARD METHOD
// Giving the leftward-going signal ciphering through the rotor.
// INPUT
// * index is an integer in [1,26] giving the input powered contact number in the entrywheel basis.
// OUTPUT 
// * indexOut is an integer in [1,26]  giving the output powered contact number in the entrywheel basis.
//
{
    // Calculate input index in rotor basis
    int indexIn= (index - 1 - m_ringPosition + (m_rotorPosition - 'A'))%26;
    // Avoid negative values
    if (indexIn<0) indexIn+= 26;
    // Get output index in the rotor basis
    int indexOut= m_wiring[indexIn];
    // Convert the result in the global basis
    indexOut= (indexOut - 1 + m_ringPosition - (m_rotorPosition - 'A'))%26 + 1;
    // Avoid negative values
    if (indexOut < 1) indexOut+= 26;
    return indexOut;
}

int Rotor::rightward(const int &index) const
//
// RIGHTWARD METHOD
// Giving the rightward-going signal ciphering through the rotor.
// INPUT
// * index is an integer in [1,26] giving the input powered contact number in the entrywheel basis.
// OUTPUT
// * indexOut is an integer in [1,26] giving the output powered contact number in the entrywheel basis.
//
{
    // Convert index in rotor basis
    int indexIn= (index - 1 - m_ringPosition + (m_rotorPosition - 'A'))%26 + 1;
    // Avoid negative values
    if (indexIn < 1) indexIn += 26;
    // Find output index in the rotor basis.
    int indexOut= 0;
    for ( ; indexOut<26 ; indexOut++)
    {
        if (m_wiring[indexOut]==indexIn)
        {
            indexOut+= 1;
            break;
        }
    }
    // Convert the result in the global basis
    indexOut= (indexOut - 1 + m_ringPosition - (m_rotorPosition - 'A'))%26 + 1;
    // Avoid negative values
    if (indexOut < 1) indexOut+= 26;
    return indexOut;
}

char Rotor::output(const int &index) const
//
// OUTPUT METHOD
// Giving the character matching the output index.
// INPUT
// * index is an integer in [1 ; 26].
// OUPUT
// * output is an character in [65 ; 90] matching the uppercase alphabet A - Z.
//
{
    return 'A' + ((m_rotorPosition - 'A') + index - 1)%26;
}

bool Rotor::rotate()
//
// ROTATE METHOD
// Realizing a one step rotation
// OUTPUT
// * rotate is a boolean returning true if turnover character is engaged before rotation
//
{
    m_rotorPosition = 'A' + (m_rotorPosition - 'A' + 1)%26;
    return m_rotorPosition==m_turnover;
}

Reflector::Reflector(const string reflectorID)
//
// REFLECTOR CLASS CONSTRUCTOR
// Provide the demanded reflector.
// INPUT
// * reflectorID is a string that must be A, B or C.
//
{
    select(reflectorID);
}

void Reflector::select(const string reflectorID)
//
// SELECT SETTER
// Select a reflector among the three available.
// INPUT
// * reflectorID is a string that must be A, B or C.
// REFERENCE
// * https://www.cryptomuseum.com/crypto/enigma/i/index.htm#wiring
//
{
    if (reflectorID=="A") // Reflector UKW-A
    {
        m_ID= "UKW-A";
        array<int,26> UKWA= {5,10,13,26,1,12,25,24,22,2,23,6,3,18,17,21,15,14,20,19,16,9,11,8,7,4};
        m_wiring= UKWA;
    }
    else if (reflectorID=="B") // Reflector UKW-B
    {
        m_ID= "UKW-B";
        array<int,26> UKWB= {25,18,21,8,17,19,12,4,16,24,14,7,15,11,13,9,5,2,6,26,3,23,22,10,1,20};
        m_wiring= UKWB;
    }
    else if (reflectorID=="C") // Reflector UKW-C
    {
        m_ID= "UKW-C";
        array<int,26> UKWC= {6,22,16,10,9,1,15,25,5,4,18,26,24,23,7,3,20,11,21,17,19,2,14,13,8,12};
        m_wiring= UKWC;
    }
    else // Invalid reflector ID
    {
        assert(((void)"Invalid reflector ID",false));
    }
}

string Reflector::ID() const
//
// ID GETTER
//
{
    return m_ID;
}

int Reflector::leftward(const int &index) const
//
// LEFTWARD METHOD
// Giving the signal ciphering through the reflector.
// As the reflector reflects the signal entry can only be from the left.
// INPUT
// * index is an integer in [1,26].
// OUTPUT
// * leftward is an integer in [1,26].
//
{
    return m_wiring[index - 1];
}

EntryWheel::EntryWheel()
//
// ETW CLASS CONSTRUCTOR
//
{/*empty*/}


int EntryWheel::leftward(const char &letter) const
//
// LEFTWARD METHOD
// Giving the character to integer conversion through the entrywheel.
// INPUT
// * letter is a char in [65,90] matching the uppercase alphabet A - Z.
// OUTPUT
// * leftward is an integer in [1,26].
// REFERENCE
// * https://www.cryptomuseum.com/crypto/enigma/i/index.htm#wiring
//
{
    return letter - 'A' + 1;
}

char EntryWheel::rightward(const int &index) const
//
// RIGHTWARD METHOD
// Giving the integer to character conversion through the entrywheel.
// INPUT
// * index is an integer in [1,26].
// OUTPUT
// * rightward is a character in [65,90] matching the uppervase alphabet A-Z.
// REFERENCE
// * https://www.cryptomuseum.com/crypto/enigma/i/index.htm#wiring
//
{
    return 'A' + index - 1;
}