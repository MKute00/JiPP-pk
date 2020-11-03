#include <iostream>
#include <algorithm>

using namespace std;

void swap(int& a, int& b) {
    std::swap(a, b);
}

int main() {
    int a, b;

    cout << "Podaj liczbe a: ";
    while (!(cin >> a)) {
        cout << "Błąd! Jeszcze raz";
        cin.clear();
        cin.ignore();
    }

    cout << "Podaj liczbe b: ";
    while (!(cin >> b)) {
        cout << "Błąd! Jeszcze raz";
        cin.clear();
        cin.ignore();
    }

    cout << "\nLiczba a:" << a << "\tLiczba b:" << b;
    swap(a, b);
    cout << "\nLiczba a:" << a << "\tLiczba b:" << b;
    
    return 0;
}