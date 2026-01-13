#include <iostream>
// #include <array>

// #include <exception>

using namespace std;

/*
    // 2. Linking Error
    int kuadrat(int &value);


    int main() {
    // 1. Syntax Error
    // int a = 10 (;) lupa titik koma
        int a = 10;

        int c = kuadrat(a);

    // 3. Non-Error
        int panjang = 10;
        int lebar = -5; // lebar tidak masuk akal -5
        cout << panjang * lebar << endl;

    // 4. Runtime Error
        array<int, 5> d = {0, 1, 2, 3, 4};
        cout << d.at(5) << endl;


        cin.get();
        return 0;
    }


    // double kuadrat(int &value) ->tidak sama dgn prototype
    int kuadrat(int &value) {
        return value*value;
    }
*/

int pembagian(int &num, int &denum)
{
    if(denum == 0) {
        throw "Error: Pembagi nol";
    }
    return num / denum;
}

int main()
{
    // array<int, 5> a = {0,1,2,3,4};

    // try {
    //     cout << a.at(5) << endl;
    // } catch(exception &e) {
    //     cout << e.what() << endl;
    // }

    while (true)
    {
        int a, b, c;
        cout << "num/denum: ";
        cin >> a >> b;

        try
        {
            // throw "Sesuatu";
            c = pembagian(a, b);
            cout << "Hasil: " << c << endl;
        }
        catch (const char *e)
        {
            cout << e << endl;
        }
    }

    cout << "akhir dari program" << endl;
    cin.get();
    return 0;
}