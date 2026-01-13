#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include <cstring>

#include "crud.h"

void crud::checkDatabase(std::fstream &data)
{
    data.open("data.bin", std::ios::out | std::ios::in | std::ios::binary);

    // check file ada atau tidak
    if (data.is_open())
    {
        std::cout << "database ditemukan" << std::endl;
    }
    else
    {
        std::cout << "database tidak ditemukan, buat database baru" << std::endl;
        data.close();
        data.open("data.bin", std::ios::trunc | std::ios::out | std::ios::in | std::ios::binary);
    }
}

int crud::getOption()
{
    int input;

    std::system("clear");
    std::cout << "\nProgram CRUD data mahasiswa" << std::endl;
    std::cout << "=============================" << std::endl;
    std::cout << "1. Tambah data mahasiswa" << std::endl;
    std::cout << "2. Tampilkan data mahasiswa" << std::endl;
    std::cout << "3. Ubah data mahasiswa" << std::endl;
    std::cout << "4. Hapus data mahasiswa" << std::endl;
    std::cout << "5. Selesai" << std::endl;
    std::cout << "=============================" << std::endl;
    std::cout << "pilih [1-5]? : ";

    std::cin >> input;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return input;
}

void crud::writeData(std::fstream &data, int posisi, Mahasiswa &inputMahasiswa)
{
    data.seekp((posisi - 1) * sizeof(Mahasiswa), std::ios::beg);
    data.write(reinterpret_cast<char *>(&inputMahasiswa), sizeof(Mahasiswa));
}

int crud::getDataSize(std::fstream &data)
{
    int start, end;
    data.seekg(0, std::ios::beg);
    start = data.tellg();
    data.seekg(0, std::ios::end);
    end = data.tellg();
    return (end - start) / sizeof(Mahasiswa);
}

crud::Mahasiswa crud::readData(std::fstream &data, int posisi)
{
    Mahasiswa readMahasiswa;
    data.seekg((posisi - 1) * sizeof(Mahasiswa), std::ios::beg);
    data.read(reinterpret_cast<char *>(&readMahasiswa), sizeof(Mahasiswa));
    return readMahasiswa;
}

void crud::addDataMahasiswa(std::fstream &data)
{
    Mahasiswa inputMahasiswa, lastMahasiswa;
    std::string temp;

    int size = crud::getDataSize(data);
    std::cout << "ukuran data : " << size << std::endl;

    if (size == 0)
    {
        inputMahasiswa.pk = 1;
    }
    else
    {
        lastMahasiswa = crud::readData(data, size);
        std::cout << "pk = " << lastMahasiswa.pk << std::endl;
        inputMahasiswa.pk = lastMahasiswa.pk + 1;
    }

    std::cout << "Nama: ";
    std::getline(std::cin, temp);
    strcpy(inputMahasiswa.nama, temp.c_str());
    std::cout << "Jurusan: ";
    std::getline(std::cin, temp);
    strcpy(inputMahasiswa.jurusan, temp.c_str());
    std::cout << "NIM: ";
    std::getline(std::cin, temp);
    strcpy(inputMahasiswa.NIM, temp.c_str());

    crud::writeData(data, size + 1, inputMahasiswa);
}

void crud::displayDataMahasiswa(std::fstream &data)
{
    int size = crud::getDataSize(data);
    Mahasiswa showMahasiswa;
    std::cout << "no.\tpk.\tNIM.\tNama.\tJurusan." << std::endl;
    for (int i = 1; i <= size; i++)
    {
        showMahasiswa = readData(data, i);
        std::cout << i << "\t";
        std::cout << showMahasiswa.pk << "\t";
        std::cout << showMahasiswa.NIM << "\t";
        std::cout << showMahasiswa.nama << "\t";
        std::cout << showMahasiswa.jurusan << std::endl;
    }
}

void crud::updateRecord(std::fstream &data)
{
    int nomor;
    Mahasiswa updateMahasiswa;
    std::string temp;

    std::cout << "pilih no: ";
    std::cin >> nomor;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    updateMahasiswa = crud::readData(data, nomor);
    // std::cout << updateMahasiswa.nama << std::endl;
    // std::cout << updateMahasiswa.jurusan <<std::endl;

    std::cout << "\n\n pilihan data : " << std::endl;
    std::cout << "NIM : " << updateMahasiswa.NIM << std::endl;
    std::cout << "nama : " << updateMahasiswa.nama << std::endl;
    std::cout << "jurusan : " << updateMahasiswa.jurusan << std::endl;

    std::cout << "\nMerubah data: " << std::endl;
    std::cout << "NIM: ";
    std::getline(std::cin, temp);
    strcpy(updateMahasiswa.NIM, temp.c_str());
    std::cout << "nama: ";
    std::getline(std::cin, temp);
    strcpy(updateMahasiswa.nama, temp.c_str());
    std::cout << "jurusan: ";
    std::getline(std::cin, temp);
    strcpy(updateMahasiswa.jurusan, temp.c_str());

    crud::writeData(data, nomor, updateMahasiswa);
}

void crud::deleteRecord(std::fstream &data)
{
    int nomor, size, offset;
    Mahasiswa blankMahasiswa, tempMahasiswa;
    std::fstream dataSementara;

    size = crud::getDataSize(data);
    // 1. pilih nomor
    std::cout << "Hapus nomor: ";
    std::cin >> nomor;
    // 2. di posisi ini diisi dengan data kosong
    writeData(data, nomor, blankMahasiswa);
    // 3. kita cek data yang ada dari file data.bin, kalau ada data
    //    kita pindahkan ke file sementara
    dataSementara.open("temp.dat", std::ios::trunc | std::ios::out | std::ios::in | std::ios::binary);

    offset = 0;

    for (int i = 1; i <= size; i++)
    {
        tempMahasiswa = crud::readData(data, i);

        if (strcmp(tempMahasiswa.nama, "") != 0)
        {
            crud::writeData(dataSementara, i - offset, tempMahasiswa);
        }
        else
        {
            offset++;
            std::cout << "deleted item" << std::endl;
        }
    }
    // 4. kita pindahkan data dari file sementara ke data.bin
    size = crud::getDataSize(dataSementara);
    data.close();
    data.open("data.bin", std::ios::trunc | std::ios::out | std::ios::binary);
    data.close();
    data.open("data.bin", std::ios::out | std::ios::in | std::ios::binary);

    for (int i = 1; i <= size; i++)
    {
        tempMahasiswa = crud::readData(dataSementara, i);
        crud::writeData(data, i, tempMahasiswa);
    }
}

// g++ main.cc crud.cc -o main