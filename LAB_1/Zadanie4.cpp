#include<iostream>
using namespace std;


int main()
{
    long a, b;
    cout << "Podaj pierwsza liczbe: ";
    cin >> a;
    cout << "\nPodaj druga liczbe: ";
    cin >> b;
    long  suma_a = 0, suma_b = 0;

    for (int i = 1; i <= a / 2; i++) {
        if (a % i == 0) {
            suma_a += i;
        }
    }
    if (suma_a != b + 1) {
        cout << "Liczby " << a << " oraz " << b << " nie sa skojarzone";
        return 0;
    }


    for (int j = 1; j <= b / 2; j++) {
        if (b % j == 0) {
            suma_b += j;
        }
    }
    if (suma_b != a + 1) {
        cout << "Liczby " << a << " oraz " << b << " nie sa skojarzone";
        return 0;
    }

    cout << "Liczby " << a << " oraz " << b << " sa skojarzone";

    return 0;
}

