#include <iostream>
using namespace std;

int main()
{
    int arrayNilai[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    for (int nilai : arrayNilai)
    {
        cout << "address " << &nilai << " nilainya: " << nilai << endl;
        nilai = 1; // tidak merubah array
    }

    cout << endl;
    // memanipulasi array dengan reference
    for (int &nilaiRef : arrayNilai)
    {
        nilaiRef = nilaiRef * 2;
    }
    for (int &nilaiRef : arrayNilai)
    {
        cout << "address " << &nilaiRef << " nilainya: " << nilaiRef << endl;
        nilaiRef = 1; // tidak merubah array
    }
    cin.get();
    return 0;
}