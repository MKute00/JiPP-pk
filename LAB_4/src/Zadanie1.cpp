#include "../include/macierz.hpp"


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