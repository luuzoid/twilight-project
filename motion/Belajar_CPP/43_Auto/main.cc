#include <iostream>
#include <string>

using namespace std;

template<typename T, typename U>
auto max(T a, U b) {
    return (a > b) ? a : b;
}

int main() {
    int a = 15;
    string b = "test";
    double c = 15.432;
    float d = 14.5f;
    auto e = max(c, a);

    cout << a << "tipe: " << typeid(a).name() << endl;
    cout << b << "tipe: " << typeid(b).name() << endl;
    cout << c << "tipe: " << typeid(c).name() << endl;
    cout << d << "tipe: " << typeid(d).name() << endl;

    cin.get();
    return 0;
}