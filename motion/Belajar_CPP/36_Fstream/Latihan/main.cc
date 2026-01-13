#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
using namespace std;

struct Mahasiswa {
    int NIM;
    char nama[50];
    char jurusan[50];
};

Mahasiswa ambilData(int posisi, fstream &myFile) {
    Mahasiswa bufferData;
    myFile.seekp((posisi-1)*sizeof(Mahasiswa));

    myFile.read(reinterpret_cast<char*>(&bufferData), sizeof(Mahasiswa));
    return bufferData;
}

void menulisData(Mahasiswa &data, fstream &myFile) {
    myFile.write(reinterpret_cast<char*>(&data), sizeof(Mahasiswa));
}

void menulisDataByPos(int posisi, Mahasiswa &bufferData, fstream &myFile) {
    myFile.seekg((posisi-1)*sizeof(Mahasiswa));

    myFile.write(reinterpret_cast<char*>(&bufferData), sizeof(Mahasiswa));
}

int main() {
    fstream myFile;
    myFile.open("data.bin", ios::trunc | ios::out | ios::in | ios::binary);
    
    Mahasiswa mahasiswa1, mahasiswa2, mahasiswa3, output;

    mahasiswa1.NIM = 123;
    strcpy(mahasiswa1.nama, "ucup");
    strcpy(mahasiswa1.jurusan, "memasak");

    mahasiswa2.NIM = 124;
    strcpy(mahasiswa2.nama, "otong");
    strcpy(mahasiswa2.jurusan, "menjahit");

    mahasiswa3.NIM = 125;
    strcpy(mahasiswa3.nama, "sandra");
    strcpy(mahasiswa3.jurusan, "mesin");
    
    menulisData(mahasiswa1, myFile);
    menulisData(mahasiswa2, myFile);
    menulisData(mahasiswa3, myFile);


    strcpy(mahasiswa2.nama, "mario");
    menulisDataByPos(2, mahasiswa2, myFile);

    int posisi = 2;
    output = ambilData(posisi, myFile);

    cout << output.NIM << endl;
    cout << output.nama << endl;
    cout << output.jurusan << endl;

    myFile.close();

    cin.get();
    return 0;
}