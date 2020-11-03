#include <iostream>
#include <algorithm>

using  namespace std;

void swap(int* a, int &var2) {
    std::swap(*a, var2);
}

int main() {

    int a, b;

    cout << "Podaj pierwsza liczbe: ";
    cin >> b;
    cout << "Podaj druga liczbe: ";
    cin >> a;
    cout << "\nPierwsza liczba: " << a << "\tDruga liczba: " << b ;
    swap(&a, b);
    cout << "\nPierwsza liczba: " << a << "\tDruga liczba: " << b;
    
    return 0;
}