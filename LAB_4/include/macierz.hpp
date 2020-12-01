#include "../libs/libs.hpp"

class Macierz {
private:
  int wiersze, kolumny;
  vector <vector <double>> matrix;

public:
  Macierz(int row, int column) {                  /*  Konstruktor 1 : przyjmujący dwa argumenty typu int tworzący macierz o podanych wymiarach zainicjalizowaną zerami*/
    wiersze = row;
    kolumny = column;
    vector <double> temp_vector;
    for (int i = 0; i < kolumny; i++) {
      temp_vector.push_back(0);
    }
    for (int i = 0; i < wiersze; i++) {
      matrix.push_back(temp_vector);
    }
  }

  Macierz(int vRows) {                           /* Kontruktor 2 : przyjmujący jeden argument typu int tworzący macierz kwadratową o podanym rozmiarze zainicjalizowaną zerami  */
    wiersze = vRows;
    kolumny = vRows;
    vector <double> tempVector;
    for (int i = 0; i < kolumny; i++) {
      tempVector.push_back(0);
    }
    for (int i = 0; i < wiersze; i++) {
      matrix.push_back(tempVector);
    }
  }

  Macierz(string filename, string path) {     /*  Kontruktor 3 : jako argument przyjmujący ścieżkę do pliku o podanym wcześniej formacie i na jego podstawie tworzący */
    ifstream file;                            /*                                             nową macierz na podstawie przekazanego pliku                             */
    file.open(path + filename, ios::out);
    if (file.good() == false) {
      cout << "File error" << endl;
      return;
    }
    else {
      file >> Macierz::kolumny;
      file >> Macierz::wiersze;
      for (int i = 0; i < wiersze; i++) {
        vector <double> tempVector;
        double element;
        for (int j = 0; j < kolumny; j++) {
          file >> element;
          tempVector.push_back(element);
        }
        matrix.push_back(tempVector);
      }
    }
    file.close();
  }

  void add(Macierz& m2) {                   /*  Metoda dodająca do siebie dwie macierze*/
  Macierz madd(4,5);
    for (int i = 0; i < wiersze; i++) {
      for (int j = 0; j < kolumny; j++) {
        madd.set(i, j, (matrix[i][j] + m2.matrix[i][j]));
      }
    }
    madd.print();
  }

  void substract(Macierz& m2) {             /*  Metoda odejmująca do siebie dwie macierze*/
  Macierz msubstract(4,5);
    for (int i = 0; i < wiersze; i++) {
      for (int j = 0; j < kolumny; j++) {
        msubstract.set(i, j, (matrix[i][j] - m2.matrix[i][j]));
      }
    }
    msubstract.print();
  }

  void multiply(Macierz& m2) {            /*  Metoda mnożąca dwie macierze*/
  Macierz mmulti(4,4);
    double temp;
    if (kolumny == m2.wiersze) {
      for (int i = 0; i < wiersze; i++) {
        for (int j = 0; j < kolumny; j++) {
          temp = 0;
          for (int k = 0; k < kolumny; k++) {
            temp += matrix[i][k] * m2.matrix[k][j];
          }
          mmulti.set(i, j, temp);
        }
      }
      mmulti.print();
    }
    else {
      cout << "Bledna liczba kolumn lub wierszy" << endl;
      return;
    }
  }

  void store(string filename, string path) {      /*  Metoda zapisująca macierz w pliku */
    fstream file;
    file.open(path + filename, ios::out);
    if (file.good() == false) {
      cout << "File error" << endl;
      return;
    }
    else {
      file << kolumny << " " << wiersze << endl;
      for (int j = 0; j < wiersze; j++) {
        for (int i = 0; i < kolumny; i++) {
          file << matrix[j][i] << " ";
        }
        file << endl;
      }
    }
    file.close();
  }

  void set(int n, int m, double val) {      /*    Metoda ustawiająca wartość elementu (n, m) na val */
    matrix[n][m] = val;
  }

  double get(int n, int m) {                /*    Metoda pobierająca element (n, m) */
    return matrix[n][m];
  }

  int rows() {                              /*   Metoda zwracająca liczbę wierszy macierzy  */
    return wiersze;
  }

  int cols() {                              /*   Metoda zwracająca liczbę kolumn macierzy   */
    return kolumny;
  }

  void print() {                            /*  Metoda wyświetlająca macierz na ekranie    */
    for (int i = 0; i < wiersze; i++) {
        for (int j = 0; j < kolumny; j++) {
           cout << get(i, j) << " ";
        }
        cout << endl;
    }
  }
};