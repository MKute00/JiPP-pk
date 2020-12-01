#include <iostream>
#include <string>
#include <vector>
#include <time.h>
#include <fstream>

using namespace std;

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

int main() {
  srand(time(NULL));
  Macierz zwykla(4, 5);
  Macierz kwadrat(6);
  int testRows = zwykla.rows();
  int testColumns = zwykla.cols();
  int squareRows = kwadrat.rows();

  cout << "Konstruktor pierwszej macierzy 4x5: " << endl;
  zwykla.print();
  cout << endl;

  cout << "Konstruktor macierzy kwadratowej 6x6: " << endl;
  kwadrat.print();
  cout << endl;

  Macierz m2(4, 5);
  for (int i = 0; i < m2.rows(); i++) {
    for (int j = 0; j < m2.cols(); j++) {
      m2.set(i, j, rand() % 5);
    }
  }

  Macierz m3(4, 5);
  for (int i = 0; i < m3.rows(); i++) {
    for (int j = 0; j < m3.cols(); j++) {
      m3.set(i, j, rand() % 5);
    }
  }

  Macierz m4(5, 4);
  for (int i = 0; i < m4.rows(); i++) {
    for (int j = 0; j < m4.cols(); j++) {
      m4.set(i, j, rand() % 3);
    }
  }

  cout << "Macierz m2: " << endl;
  m2.print();
  cout << endl;
  cout << "Macierz m3: " << endl;
  m3.print();
  cout << endl;
  cout << "Macierz m4: " << endl;
  m4.print();
  cout << endl;



  cout << "Dodawanie macierzy(m2 + m3): " << endl;
  m2.add(m3);
  cout << endl;

  cout << "Odejmowanie macierzy(m2 - m3): " << endl;
  m2.substract(m3);
  cout << endl;

  cout << "Mnozenie macierzy(m2 * m4): " << endl;
  m2.multiply(m4);
  cout << endl;

  cout << "Zapis macierzy 4 do pliku" << endl;
  m4.store("macierz.txt", "../"); 

  cout <<  "Macierz z pliku: " << endl;
  Macierz matrixFromFile("macierz.txt", "../");
  matrixFromFile.print();
  cout << endl;

}