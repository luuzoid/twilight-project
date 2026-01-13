#include <iostream>
#include <string>
using namespace std;

int main() {
    // char kata[5] = {'m','o','b','i','l','e'}; // cara lama
    // array char tidak bisa kita tambah, fix karena array.

    string kata("cat");
    cout << kata << endl;

    string data;
    cout << "Masukkan kata: ";
    cin >> data;
    cout << "Kata yang dimasukkan: " << data << endl;

    cin.get();
    return 0;
}