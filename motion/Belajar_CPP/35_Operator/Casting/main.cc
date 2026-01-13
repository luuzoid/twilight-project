#include <iostream>
using namespace std;

// casting (dijabarkan)
// - implicit
// - explicit

int main() {

    int a = 5;
    float b = 6.67f;
    char c = 'd';

    cout << a + (int)b << endl;
    cout << (int)c << endl;
    cout << c + a << endl;
    cout << (char)(c + a) << endl;

    cin.get();
    return 0;
}