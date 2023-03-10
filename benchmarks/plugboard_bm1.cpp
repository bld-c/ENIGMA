#include<iostream>
#include"plugboard.h"

int main()
{
    Plugboard plugboard;

    plugboard.plug( 1, 'E', 'L');
    plugboard.plug( 2, 'B', 'V');
    plugboard.plug( 3, 'N', 'K');
    plugboard.plug( 4, 'H', 'Z');
    plugboard.plug( 5, 'X', 'P');
    plugboard.plug( 6, 'D', 'J');
    plugboard.plug( 7, 'G', 'O');
    plugboard.plug( 8, 'F', 'U');
    plugboard.plug( 9, 'W', 'M');
    plugboard.plug(10, 'R', 'A');
    cout << 
        plugboard.ciphering('A') <<
        plugboard.ciphering('B') <<
        plugboard.ciphering('C') <<
        plugboard.ciphering('D') <<
        plugboard.ciphering('E') <<
        plugboard.ciphering('F') <<
        plugboard.ciphering('G') <<
        plugboard.ciphering('H') <<
        plugboard.ciphering('I') <<
        plugboard.ciphering('J') <<
        plugboard.ciphering('K') <<
        plugboard.ciphering('L') <<
        plugboard.ciphering('M') <<
        plugboard.ciphering('N') <<
        plugboard.ciphering('O') <<
        plugboard.ciphering('P') <<
        plugboard.ciphering('Q') <<
        plugboard.ciphering('R') <<
        plugboard.ciphering('S') <<
        plugboard.ciphering('T') << 
        plugboard.ciphering('U') <<
        plugboard.ciphering('V') <<
        plugboard.ciphering('W') <<
        plugboard.ciphering('X') <<
        plugboard.ciphering('Y') <<
        plugboard.ciphering('Z') << endl;

    plugboard.plug(1,'C','L');
    cout << 
        plugboard.ciphering('C') <<
        plugboard.ciphering('L') << endl;

    plugboard.unplug( 1);
    plugboard.unplug( 2);
    plugboard.unplug( 3);
    plugboard.unplug( 4);
    plugboard.unplug( 5);
    plugboard.unplug( 6);
    plugboard.unplug( 7);
    plugboard.unplug( 8);
    plugboard.unplug( 9);
    plugboard.unplug(10);

    cout << 
        plugboard.ciphering('A') <<
        plugboard.ciphering('B') <<
        plugboard.ciphering('C') <<
        plugboard.ciphering('D') <<
        plugboard.ciphering('E') <<
        plugboard.ciphering('F') <<
        plugboard.ciphering('G') <<
        plugboard.ciphering('H') <<
        plugboard.ciphering('I') <<
        plugboard.ciphering('J') <<
        plugboard.ciphering('K') <<
        plugboard.ciphering('L') <<
        plugboard.ciphering('M') <<
        plugboard.ciphering('N') <<
        plugboard.ciphering('O') <<
        plugboard.ciphering('P') <<
        plugboard.ciphering('Q') <<
        plugboard.ciphering('R') <<
        plugboard.ciphering('S') <<
        plugboard.ciphering('T') << 
        plugboard.ciphering('U') <<
        plugboard.ciphering('V') <<
        plugboard.ciphering('W') <<
        plugboard.ciphering('X') <<
        plugboard.ciphering('Y') <<
        plugboard.ciphering('Z') << endl;
    
    return 0;
}