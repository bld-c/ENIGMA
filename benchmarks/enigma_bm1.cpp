#include<iostream>
#include "enigma.h"

int main ()
{
    Enigma machine;

    //*** Testing double stepping behaviour ***//
    cout << endl << "TESTING DOUBLE STEPPING BEHAVIOUR" << endl << endl ;

    // Select rotors and reflector
    machine.selectRotor(1,"III");
    machine.selectRotor(2,"II");
    machine.selectRotor(3,"I");

    // Set rotor positions
    machine.setRotorPosition(1,'A');
    machine.setRotorPosition(2,'D');
    machine.setRotorPosition(3,'O');
    
    // Reproducing double stepping behaviour
    string msg= "A";
    for (int i=0 ; i<5 ; i++)
    {
        machine.ciphering(msg);
        machine.getConfig(cout);
    }


    //*** Testing ciphering and deciphering ***//

    cout << endl << "TESTING CIPHERING AND DECIPHERING" << endl << endl;

    // Select rotors and reflector
    machine.selectReflector("B");
    machine.selectRotor(1,"IV");
    machine.selectRotor(2,"II");
    machine.selectRotor(3,"V");

    // Set ring positions
    machine.setRotorRing(1,14);
    machine.setRotorRing(2,7);
    machine.setRotorRing(3,24);

    // Set rotor positions
    machine.setRotorPosition(1,'O');
    machine.setRotorPosition(2,'D');
    machine.setRotorPosition(3,'U');

    // Set plugboard cables
    machine.plugCable(1,'A','Q');
    machine.plugCable(2,'B','G');
    machine.plugCable(3,'C','Z');
    machine.plugCable(4,'D','Y');
    machine.plugCable(5,'F','T');
    machine.plugCable(6,'H','K');
    machine.plugCable(7,'L','U');
    machine.plugCable(8,'M','O');
    machine.plugCable(9,'N','R');
    machine.plugCable(10,'S','X');

    // Message to cipher and its ciphering from https://www.101computing.net/enigma-machine-emulator/
    string msg1= "CECIESTUNMESSAGEVISANTAVERIFIERLEBONFONCTIONNEMENTDUCODEMODELISANTLAMACHINEDECHIFFREMENTENIGMA";
    string msgCiphered1= "KIEFLDDLYOYLPYNGMKZPFHNCTGRNEHUCCCGCJSYZNGUVURZREJEVWCBMJQLHWEXCOFCRKMSJUDRMTTSCXAGFBAVAQOOFTU";

    cout << "Plaintext message:  " << msg1 << endl;
    
    // Ciphering
    msg= machine.ciphering(msg1);
    cout << "Ciphered message:   " << msg << endl;
    cout << "Is the message correctly ciphered:   " << (msgCiphered1==msg) << endl;
    machine.getConfig(cout);

    // Reset rotor positions
    machine.setRotorPosition(1,'O');
    machine.setRotorPosition(2,'D');
    machine.setRotorPosition(3,'U');

    // Deciphering
    msg= machine.deciphering(msg);
    cout << "Deciphered message: " << msg << endl;
    cout << "Is the message correctly deciphered: " << (msg1==msg) << endl;
    return 0;
}