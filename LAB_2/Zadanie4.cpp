#include <iostream>

using namespace std;

int funkcja(int a, int b, int& mnozenie) {
    mnozenie = a * b;
    return a + b;
}


int main() {

    int a, b, mnozenie;

    cout << "Podaj a: ";
    cin >> a;
    cout << "Podaj b: ";
    cin >> b;
    cout << a << " + " << b << " = " << funkcja(a, b, mnozenie);
    cout << "\n" << a << " * " << b << " = " << mnozenie;

    return 0;
}