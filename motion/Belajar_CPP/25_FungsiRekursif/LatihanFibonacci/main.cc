#include <iostream>
using namespace std;

int fibonacci(int n);

int main() {
    int angka;
    cout << "Masukkan sebuah angka: ";
    cin >> angka;

    int hasil = fibonacci(angka);
    cout << endl << "Fibonacci ke-" << angka << " adalah " << hasil << endl;
}

int fibonacci(int n) {
    if (n <= 0) {
        cout << n;
        return 0; // Basis: Fibonacci ke-0 adalah 0
    } else if (n == 1) {
        cout << n;
        return 1; // Basis: Fibonacci ke-1 adalah 1
    } else {
        cout << n << " + ";
        return fibonacci(n - 1) + fibonacci(n - 2); // Rekurens: F(n) = F(n-1) + F(n-2)
    }
}