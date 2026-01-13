#include <iostream>
#include "bersama.h"
#include "foo.h"
#include "bar.h"

/*

// #define FOO 5
// #define FOO
#define FOO "foo lama"
// ifdef
#ifdef FOO
    #define TEST_FOO "foo ada"
#else
    #define TEST_FOO "foo tidak ada"
#endif

// ifndef
#ifndef FOO
    #define FOO "foo baru"
#endif

*/

// pragma once

using namespace std;


int main() {
    // cout << FOO << endl;
    Mahasiswa mahasiswa1;
    mahasiswa1.NIM = 1;
    cout << mahasiswa1.NIM << endl;

    cin.get();
    return 0;
}