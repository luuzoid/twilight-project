#include <iostream>
using namespace std;

int main(){

	int a = 5;

	// pointer
	int *aPtr = nullptr;
	aPtr = &a;

	// int a mempunyai nilai dan address ( alamat )

	cout << " nilai dari a: " << a << endl;
	cout << " alamat dari a: " << &a << endl << endl;

	cout << " nilai dari aPtr: " << *aPtr << endl;
	cout << " alamat dari a: " << aPtr << endl;

	// dereferencing, mengambil data dari sebuah pointer
	*aPtr = 10;
	a = 20;
	cout << "mengambil nilai dari pointer aPtr : " << *aPtr << endl;


	cin.get();
	return 0;
}