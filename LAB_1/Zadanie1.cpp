#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 50;


int main(int argc, char* argv[]) {

    int tab[MAX], licznik = 0;
    for (int i = 1; i < argc; i++) {
        tab[i - 1] = atoi(argv[i]);
        licznik++;
    }

    cout << "Podany ciag liczb:\n";
    for (int i = 0; i < licznik; i++) {
        cout << tab[i] << " ";
    }

    sort(tab, tab + licznik);

    cout << "Posortowany ciag liczb:\n";
    for (int i = 0; i < licznik; i++) {
        cout << tab[i] << " ";
    }


    return 0;
}