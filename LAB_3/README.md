Należy zaimplementować klasę reprezentującą macierz elementów double. Klasa ma mieć następujące metody:

    Dwa konstruktory:

    przyjmujący dwa argumenty typu int tworzący macierz o podanych wymiarach zainicjalizowaną zerami
    przyjmujący jeden argument typu int tworzący macierz kwadratową o podanym rozmiarze zainicjalizowaną zerami

    set(n, m, val) - metoda ustawiająca wartość elementu (n, m) na val
    get(n, m) - metoda pobierająca element (n, m)
    add(Matrix m2) - metoda przyjmująca jako argument inną macierz i zwracająca jako wynik nową macierz będącą sumą bieżącej macierzy oraz macierzy przekazanej jako argument
    subtract(Matrix m2) - metoda przyjmująca jako argument inną macierz i zwracająca jako wynik nową macierz będącą różnicą bieżącej macierzy oraz macierzy przekazanej jako argument
    multiply(Matrix m2) - metoda przyjmująca jako argument inną macierz i zwracająca jako wynik nową macierz będącą iloczynem bieżącej macierzy oraz macierzy przekazanej jako argument
    cols() - metoda zwracająca liczbę kolumn macierzy
    rows() - metoda zwracająca liczbę wierszy macierzy
    print() - metoda wyświetlająca macierz na ekranie
    store(std::string filename, std::string path) - metoda zapisująca macierz w pliku; w pliku powinny być zapisane wymiary macierzy (liczba kolumn i liczba wierszy w pierwszym wierszu pliku) oraz jej zawartość (każdy wiersz macierzy w osobnym wierszu pliku)
