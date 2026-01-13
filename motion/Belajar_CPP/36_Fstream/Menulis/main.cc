#include <iostream>
#include <fstream> //ofstream,ifstream,fstream
using namespace std;

int main() {
    ofstream myFile;

    /*
    ios::out = operasi output (default)
    ios::app = menuliskan pada akhir baris
    ios::trunc = membuat file jika tidak ada (default)
    */

    myFile.open("data3.txt", ios::app); // append
    myFile << "\nmenuliskan baris baru pada data3";
    myFile.close();

    int a = 123876;
    myFile.open("data1.txt", ios::out);
    myFile << "tuliskan pada data1\n";
    myFile << a;
    // cout << "apa console";
    myFile.close();

    myFile.open("data2.txt", ios::trunc);
    myFile << "\ntuliskan pada data2";
    myFile.close();

    cin.get();
    return 0;
}