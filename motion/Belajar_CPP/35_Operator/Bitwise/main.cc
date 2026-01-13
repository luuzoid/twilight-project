#include <iostream>
#include <bitset>
#include <string>
using namespace std;

// 1 Byte = 8 bit

void printBinary(unsigned short val, string nama) {
    cout << nama << " = " << bitset<8>(val) << endl;
}

int main() {

    unsigned short a = 6;
    unsigned short b = 10;
    unsigned short c;

    cout << "& = Bitwise AND" << endl;
    c = a & b;
    printBinary(a, "a");
    printBinary(b, "b");
    printBinary(c, "c");
    cout << c << endl;

    cout << "| = Bitwise OR" << endl;
    c = a | b;
    printBinary(a, "a");
    printBinary(b, "b");
    printBinary(c, "c");
    cout << c << endl;

    cout << "^ = Bitwise XOR" << endl;
    c = a ^ b;
    printBinary(a, "a");
    printBinary(b, "b");
    printBinary(c, "c");
    cout << c << endl;

    cout << "~ = Bitwise NOT" << endl;
    c = ~a;
    printBinary(a, "a");
    printBinary(c, "c");
    cout << c << endl;

    cout << "<< = Bitwise SHL" << endl;
    c = a << 2;
    printBinary(a, "a");
    printBinary(c, "c");
    cout << c << endl;

    cout << ">> = Bitwise SHR" << endl;
    c = a >> 2;
    printBinary(a, "a");
    printBinary(c, "c");
    cout << c << endl;

    cin.get();
    return 0;
}

/*
BITWISE OPERATOR

&   AND Bitwise AND
|   OR Bitwise inclusive OR
^   XOR Bitwise exclusive OR
~   NOR
<<  SHL Shift bits left
>>  SHR Shift bits right

*/