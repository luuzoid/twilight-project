// [ # ] -> preprocessing directive
#include <iostream> 

// macro
#define PI 3.14159265359 // -> tidak memakan memori

// akhir dari preprocessing directive

using namespace std;

double pi = 3.14159265359;
int main() {
    cout << "nilai pi double = " << pi << endl;
    cout << "nilai PI = " << PI << endl;
    cout << &pi << endl;
    // cout << &PI << endl; // -> ERROR: tidak punya address

    cin.get();
    return 0;
}