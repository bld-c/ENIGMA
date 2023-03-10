#include<iostream>
#include"rotor.h"

int main ()
{
    Rotor rotor1("I",1,'N');
    cout << "Ciphering Hello" << endl;
    bool turnOver= rotor1.rotate();
    cout << "rotorPosition: " << rotor1.position() 
        << " turn over: " << turnOver << " ciphering: "
        << rotor1.output(rotor1.leftward(8)) << endl;
    turnOver= rotor1.rotate();
    cout << "rotorPosition: " << rotor1.position() 
        << " turn over: " << turnOver << " ciphering: "
        << rotor1.output(rotor1.leftward(5)) << endl; 
    turnOver= rotor1.rotate();
    cout << "rotorPosition: " << rotor1.position() 
        << " turn over: " << turnOver << " ciphering: "
        << rotor1.output(rotor1.leftward(12)) << endl; 
    turnOver= rotor1.rotate();
    cout << "rotorPosition: " << rotor1.position() 
        << " turn over: " << turnOver << " ciphering: "
        << rotor1.output(rotor1.leftward(12)) << endl; 
    turnOver= rotor1.rotate();
    cout << "rotorPosition: " << rotor1.position() 
        << " turn over: " << turnOver << " ciphering: "
        << rotor1.output(rotor1.leftward(15)) << endl; 
    return 0;
}