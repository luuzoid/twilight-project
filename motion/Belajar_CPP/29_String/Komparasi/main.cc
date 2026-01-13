#include <iostream>
#include <string>
using namespace std;

int main() {
    
    // perbandingan string
    string input;
    string nama_rahasia("ucup");

    while(true) {
        cout << "tebak nama: ";
        cin >> input;
        cout << input;
        if(input == nama_rahasia) {
            cout << " benar!" << endl;
            break;
        }

        cout << " salah!" << endl;
    }
    cout << "selesai" << endl;

    cin.get();
    return 0;
}