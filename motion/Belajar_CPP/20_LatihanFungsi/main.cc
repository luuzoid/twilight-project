#include <iostream>
using namespace std;

double hitung_luas(double p, double l) {
    double luas = p * l;
    return luas;
}

double hitung_keliling(double p, double l) {
    double keliling = 2 * (p + l);
    return keliling;
}

void tampil_hasil(double luas, double keliling) {
    cout << "Luas: " << luas << endl;
    cout << "Keliling: " << keliling << endl;
}

int main() {
    double panjang, lebar;
    cout << "Masukkan panjang: ";
    cin >> panjang;
    cout << "Masukkan lebar: ";
    cin >> lebar;

    tampil_hasil(hitung_luas(panjang, lebar), hitung_keliling(panjang, lebar));
}