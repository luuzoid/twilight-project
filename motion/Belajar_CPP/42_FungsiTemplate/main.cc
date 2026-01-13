#include <iostream>
#include <string>

using namespace std;

// void print(int data) {
//     cout << data << endl;
// }

// void print(double data) {
//     cout << data << endl;
// }

// void print(char data) {
//     cout << data << endl;
// }

template<typename T>
void print(T data) {
    cout << data << endl;
}

template<typename T>
int toInt(T data) {
    return int(data);
}

template<typename T, typename U>
T max(T a, U b) {
    return (a > b) ? a : b;
}

int main() {
    print(5);
    print(5.8);
    print('c');

    print(toInt(10.1010101));
    cout << max(10, 103.5) << endl;

    print<int>(10.15);

    cin.get();
    return 0;
}