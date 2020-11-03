// Zadanie 1.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
using namespace std;

int main()
{
    float masa_ciała, wzrost, BMI;

    cout << "Podaj mase ciala (kg):\n";
    cin >> masa_ciała;

    cout << "\nPodaj wzrost (m):\n";
    cin >> wzrost;

    BMI = masa_ciała / (wzrost * wzrost);
    if (BMI < 16) {
        cout << "Wyglodzenie";
    }
    if (BMI >= 16 && BMI < 17) {
        cout << "Wychudzenie";
    }
    if (BMI >= 17 && BMI < 18.5) {
        cout << " Niedowaga";
    }
    if (BMI >= 18.5 && BMI < 25) {
        cout << "Wartosc prawidlowa";
    }
    if (BMI >= 25 && BMI < 30) {
        cout << "Nadwaga";
    }
    if (BMI >= 30 && BMI < 35) {
        cout << "I stopien otylosci";
    }
    if (BMI >= 35 && BMI < 40) {
        cout << "II stopien otylosci:";
    }
    if (BMI >= 40) {
        cout << "Otylosc skrajna";
    }

    return 0;
}

