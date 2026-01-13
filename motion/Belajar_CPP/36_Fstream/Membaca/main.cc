#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream myFile;
    string output, buffer;
    bool isData = false;
    int no;
    string nama;

    /*
    ios::in = (default)
    ios::ate = mulai dari akhir file
    ios::binary = menaruh hexadesimal
    */

    myFile.open("data.txt", ios::in);
    // myFile >> data;
    while(!isData) {
        getline(myFile, buffer);
        output.append("\n" + buffer);
        (buffer == "data") ? isData=true : isData=false;
    }

    cout << output << endl;

    getline(myFile, buffer);
    cout << buffer << endl;

    int jumlah_data = 0;
    while(!myFile.eof()) {
        myFile >> no;
        myFile >> nama;

        cout << no << "   " << nama << endl;
        jumlah_data++;
    }
    cout << "jumlah data = " << jumlah_data << endl;

    cin.get();
    return 0;
}