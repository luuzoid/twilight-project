#include <iostream>
#include <string>
using namespace std;

void printData(int val) {
    cout << val << endl;
}

int main() {

    /*
    int a,b,c,d;
    void fungsi(int a,int b);
    int a[5] = {1,2,3,4,5};
    INI BUKAN COMMA OPERATOR MELAINKAN SEPARATOR
    */

    // (expression1, expression2)
    int a;
    int b;
    int c;
    // b = 1;
    // c = 2;
    // a = (b+c);
    
    // a = ( b=1, c=5, (b+c) );
    a = ( b=1, printData(b), c=5, printData(c), (b+c) );

    cout << a << endl;
    // cout << b << endl;
    // cout << c << endl;

    cin.get();
    return 0;
}