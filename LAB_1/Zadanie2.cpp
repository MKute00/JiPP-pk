#include<iostream>
#include<cstring>
using namespace std;


void Palindron(char wyraz[]) {
    int i = 0, j = strlen(wyraz) - 1;
    for (i, j; i < j; i++, j--) {

        if (wyraz[i] != wyraz[j])
            break;
    }
    if (i < j)
        cout << "Podany wyraz nie jest palindromem";
    else
        cout << "Podany wyraz jest palindromem";
}

int main(int argc, char* argv[]) {

    char* wyraz;
    wyraz = argv[1];

    Palindron(wyraz);

    return 0;

}