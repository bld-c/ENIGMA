#include<iostream>
#include "rotor.h"

int main()
{
    Rotor rotor1("I",1,'A'), rotor2("II",1,'A'), rotor3("III",1,'A');
    EntryWheel ETW;
    Reflector UKW('A');

    char letter= 'A';

    cout << "character: " << letter << " is ciphered  through the entry wheel by: " << ETW.leftward(letter) << endl
        << "which is ciphered through the rotor 1 by: " << rotor1.leftward(ETW.leftward(letter)) << endl
        << "which is ciphered through the rotor 2 by: " << rotor2.leftward(rotor1.leftward(ETW.leftward(letter))) << endl
        << "which is ciphered through the rotor 3 by: " << 
            rotor3.leftward(rotor2.leftward(rotor1.leftward(ETW.leftward(letter)))) << endl
        << "which is ciphered through the reflector by: " << 
            UKW.leftward(rotor3.leftward(rotor2.leftward(rotor1.leftward(ETW.leftward(letter))))) << endl
        << "which is ciphered through the rotor 3 by: " <<
            rotor3.rightward(UKW.leftward(rotor3.leftward(rotor2.leftward(rotor1.leftward(ETW.leftward(letter)))))) << endl
        << " which is ciphered through the rotor 2 by: " <<
            rotor2.rightward(rotor3.rightward(UKW.leftward(
                rotor3.leftward(rotor2.leftward(rotor1.leftward(ETW.leftward(letter))))))) << endl
        << " which is ciphered through the rotor 1 by: " << 
            rotor1.rightward(rotor2.rightward(rotor3.rightward(UKW.leftward(
                rotor3.leftward(rotor2.leftward(rotor1.leftward(ETW.leftward(letter)))))))) << endl
        << " which is ciphered through the entry wheel by: " <<
            ETW.rightward(rotor1.rightward(rotor2.rightward(rotor3.rightward(UKW.leftward(
                rotor3.leftward(rotor2.leftward(rotor1.leftward(ETW.leftward(letter))))))))) << endl;
    return 0;
}