#include <iostream>

#include "otong.h"

void fungsi2() {
    std::cout << "ini adalah fungsi biasa" << std::endl;
}

using namespace otong;
// using namespace std;

int main() {
    fungsi();
    std::cout << otong::b << std::endl;
    // otong::fungsi();
    // otong::cout(100);
    fungsi();
    cout(100);

    std::cin.get();
    return 0;
}