#include<iostream>
using namespace std;


int main()
{
    int tab1[2][3], tab2[2][3], tab3[2][3];

    cout << "Uzupelnij pierwsza macierz (6 el.):";
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> tab1[i][j];
        }
    }

    cout << "\nUzupelnij druga macierz (6 el.):";
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> tab2[i][j];
        }
    }

    //WYŚWIETLANIE
    cout << "\nPIERWSZA MACIERZ\n";
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            cout << tab1[i][j];
            cout << "\t";
        }
        cout << "\n";
    }
    cout << "\n DRUGA MACIERZ\n";
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            cout << tab2[i][j];
            cout << "\t";
        }
        cout << "\n";
    }

    //DODAWANIE
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            tab3[i][j] = tab1[i][j] + tab2[i][j];
        }
    }
    cout << "\nWYNIK\n";
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            cout << tab3[i][j];
            cout << "\t";
        }
        cout << "\n";
    }
    return 0;
}

