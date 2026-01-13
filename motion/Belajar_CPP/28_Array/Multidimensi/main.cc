#include <iostream>
using namespace std;

void printArray(int *ptrArray, int baris, int kolom) {
    int index = 0;
    for(int i = 0; i < baris; i++) {
        cout << "[ ";
        for(int j = 0; j < kolom; j++) {
            cout << *(ptrArray + index) << " ";
            index++;
        }
        cout << "]" << endl;
    }
}

int main() {
    /*
    int array[baris][kolom] = {
        {elemen11, elemen12, ..., elemen1kolom},
        {elemen21, elemen22, ..., elemen2kolom},
        ...
        {elemenbaris1, elemenbaris2, ..., elemenbariskolom}
    };
    */
    const int baris = 2;
    const int kolom = 2;
    int arrayMD[baris][kolom] = {1,2,3,4};
    // cout << arrayMD[0][0] << " " << arrayMD[0][1] << endl;
    // cout << arrayMD[1][0] << " " << arrayMD[1][1] << endl;

    printArray(*arrayMD, baris, kolom);

    cin.get();
    return 0;
}