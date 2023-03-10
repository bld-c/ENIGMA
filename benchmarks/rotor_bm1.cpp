#include<iostream>
#include"rotor.h"

int main ()
{
    Rotor rotor1("I",25,'Z');
    for (int in= 1 ; in<27 ; in++)
    {
        cout << "right input contact: " << in;
        cout << " has a matching character: " << rotor1.output(rotor1.leftward(in)) << endl;
        cout << "left input contact: " << rotor1.leftward(in);
        cout << " has a matching character: " << rotor1.output(rotor1.rightward(in)) << endl;
    }
    return 0;
}