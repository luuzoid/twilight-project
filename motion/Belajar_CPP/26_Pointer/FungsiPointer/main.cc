#include <iostream>
using namespace std;

void fungsi(int *b);
void kuadrat(int *b);

int main() {
    int a = 5;
    cout << "address nilai a " << &a << endl;
    cout << "  nilai a " << a << endl;

    // fungsi(&a); // fungsi dengan input pointer
    // cout << " nilai a " << a << endl;

    kuadrat(&a);

    cout << " nilai a " << a << endl;
    
    cin.get();
    return 0;
}

void fungsi(int *b) {
    cout << "address nilai b " << b << endl;
    cout << "  nilai b " << *b << endl;
}

void kuadrat(int *b) {
    *b = (*b) * (*b);
}