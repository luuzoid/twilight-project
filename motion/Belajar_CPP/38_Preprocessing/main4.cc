#include <iostream>
#include "library.h"
#include <string>

#define PI 3.14159

using namespace std;

int main() {
    // #include "library.h"

    cout << "Berhasil" << endl;
    cout << "PI: " << PI << endl;
    cout << "KUADRAT: " << KUADRAT(5) << endl;
    cout << "MAX: " << MAX(10,2) << endl;
    cout << "data string: " << data_string << endl;

    cin.get();
    return 0;
}