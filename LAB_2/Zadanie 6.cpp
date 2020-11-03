#include <iostream>
using namespace std;

void swap(int& a, int& b) {
    a = a + b;
    b = a - b;
    a = a - b;
}

int main() {
    int a, b;

    cout << "Podaj pierwsza liczbe: ";
    cin >> a;
    cout << "Podaj druga liczbe: ";
    cin >> b;

    cout << "\nLiczba a:" << a << "\tLiczba b:" << b;
    swap(a, b);
    cout << "\nLiczba a:" << a << "\tLiczba b:" << b;

    return 0;
}