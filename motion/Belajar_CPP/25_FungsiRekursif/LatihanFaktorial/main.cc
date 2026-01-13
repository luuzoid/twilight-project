#include <iostream>
using namespace std;

// Prototype
int faktorial(int n);

int main() {
    int angka;
    cout << "Masukkan sebuah angka: ";
    cin >> angka;

    int hasil = faktorial(angka);
    cout << endl << "Faktorial dari " << angka << " adalah " << hasil << endl;

    return 0;
}

int faktorial(int n) {
    if (n <= 1) {
        cout << n;
        return n; // Basis: faktorial dari 0 adalah 1
    } else {
        cout << n << " * ";
        return n * faktorial(n - 1); // Rekurens: n! = n * (n-1)!
    }
}