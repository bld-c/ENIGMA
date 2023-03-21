#include"plugboard.h"

Plugboard::Plugboard()
//
// PLUGBOARD CLASS CONSTRUCTOR
//
{
    array<char,26> temp1= {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    m_plugboard= temp1;
    array<char,26> temp2= {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    m_plugcables= temp2;
}

void Plugboard::plug(int cableID, char letter1, char letter2)
//
// PLUG METHOD
// Switch two character connecting them with a cable.
// INPUT
// * cableID is an integer in [1,13] identifying the plugcable.
// * letter1 is a character in [65,90] matching the uppercase alphabet A - Z.
// * letter2 is a character in [65,90] matching the uppercase alphabet A - Z, different from letter1.
//
{
    // Ensure that inputs are valid
    assert(((void)"cableID should be in [1,13]",(cableID>0 && cableID<14)));
    if (m_plugcables[cableID-1]!=0) unplug(cableID);
    assert(((void)"letter2 must be different from letter1.", (letter1!=letter2)));
    assert(((void)"letter1 must in the uppercase alphabet A - Z.", (letter1>64 && letter1<91)));
    assert(((void)"letter2 must in the uppercase alphabet A - Z.", (letter1>64 && letter2<91)));
    assert(((void)"letter1 is already plugged",(count(begin(m_plugcables), end(m_plugcables), letter1) == 0)));
    assert(((void)"letter2 is already plugged",(count(begin(m_plugcables), end(m_plugcables), letter2) == 0)));

    // switch letters
    m_plugcables[2*cableID-2]= letter1;
    m_plugcables[2*cableID-1]= letter2;
    m_plugboard[letter1-'A']= letter2;
    m_plugboard[letter2-'A']= letter1;
}

void Plugboard::unplug(int cableID)
//
// UNPLUG METHOD
// Unplug the identified cable.
// INPUT
// * cableID is an iteger in [1,13].
//
{
    // Ensure that cableID is valid
    assert(((void)"cableID should be in [1,13]",(cableID>0 && cableID<14)));

    m_plugboard[m_plugcables[2*cableID-2]-'A']= m_plugcables[2*cableID-2];
    m_plugboard[m_plugcables[2*cableID-1]-'A']= m_plugcables[2*cableID-1];
    m_plugcables[2*cableID-2]= 0;
    m_plugcables[2*cableID-1]= 0;
}

char Plugboard::ciphering(const char letter) const
//
// CIPHERING METHOD
// Gives the ciphering of a character through the plugboard.
// INPUT
// * letter is a character in [65,90] matching the uppercase alphabet A - Z.
// OUTPUT
// ciphering is a character in [65,90] matching the uppercase alphabet A - Z.
//
{
    return m_plugboard[letter-'A'];
}