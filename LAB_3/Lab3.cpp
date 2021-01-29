#include <iostream>
#include <string>
#include <vector>
#include <time.h>
#include <fstream>

using namespace std;

class Macierz {

public:
  int wiersze, kolumny;
  double** myMatrix;

  Macierz(int vRows, int vColumns);

  Macierz(int vRows = 1);

  Macierz(string filename, string path);

  int getRows();

  int getColumns();

  void set(int n, int m, double val);

  double get(int n, int m);

  void print();

  Macierz add(Macierz m2);

  Macierz substract(Macierz m2);

  Macierz multiply(Macierz m2);

  void store(string filename, string path);
};

Macierz::Macierz(int vRows, int vColumns) {
  wiersze = vRows;
  kolumny = vColumns;
  myMatrix = new double* [wiersze] {};
  for (int i = 0; i < wiersze; i++)
    myMatrix[i] = new   double[kolumny] {};
}

Macierz::Macierz(int vRows) {
  wiersze = vRows;
  kolumny = vRows;
  myMatrix = new double* [wiersze] {};
  for (int i = 0; i < wiersze; i++)
    myMatrix[i] = new double[kolumny] {};
}

Macierz::Macierz(string filename, string path) {
  ifstream file;
  file.open(path + filename, ios::out);
  if (file.good() == false) {
    cout << endl << "File error" << endl;
    return;
  }
  else {
    file >> kolumny;
    file >> wiersze;
    myMatrix = new double* [kolumny];
    for (int i = 0; i < wiersze; i++) {
      myMatrix[i] = new double[kolumny];
      for (int j = 0; j < kolumny; j++) {
        file >> myMatrix[i][j];
      }
    }
  }
  file.close();
}


int Macierz::getRows() {
  return wiersze;
}


int Macierz::getColumns() {
  return kolumny;
}

void Macierz::set(int n, int m, double val) {
  if (n < 0 || n > wiersze - 1)
    throw "Niepoprawny numer wiersza";
  if (m < 0 || m > kolumny - 1)
    throw "Niepoprawny numer kolumny";
  myMatrix[n][m] = val;
}

double Macierz::get(int n, int m) {
  if (n < 0 || n > wiersze - 1)
    throw "Niepoprawny numer wiersza";
  if (m < 0 || m > kolumny - 1)
    throw "Niepoprawny numer kolumny";
  return myMatrix[n][m];
}

void Macierz::print() {
  for (int i = 0; i < wiersze; i++) {
    for (int j = 0; j < kolumny; j++) {
      cout << get(i, j) << " ";
    }
    cout << endl;
  }
}

Macierz Macierz::add(Macierz m2) {
  Macierz matrixToAdd(wiersze, kolumny);
  if (m2.wiersze != wiersze)
    throw "Bledna liczba wierszy.";
  if (m2.kolumny != kolumny)
    throw "Bledna liczba kolumn.";
  for (int i = 0; i < wiersze; i++) {
    for (int j = 0; j < kolumny; j++) {
      matrixToAdd.myMatrix[i][j] = m2.myMatrix[i][j] + myMatrix[i][j];
    }
  }
  return matrixToAdd;
}

Macierz Macierz::substract(Macierz m2) {
  Macierz matrixToSubstract(m2.wiersze, m2.kolumny);
  if (m2.wiersze != wiersze)
    throw "Niepoprawna liczba wierszy";
  if (m2.kolumny != kolumny)
    throw "Niepoprawna liczba kolumn";
  for (int i = 0; i < wiersze; i++) {
    for (int j = 0; j < kolumny; j++) {
      matrixToSubstract.set(i, j, (myMatrix[i][j] - m2.myMatrix[i][j]));
    }
  }
  return matrixToSubstract;
}

void Macierz::store(string filename, string path) {
  fstream file;
  file.open(path + filename, ios::out);
  if (file.good() == false) {
    cout << endl << "File error" << endl;
    return;
  }
  else {
    file << kolumny << " " << wiersze << "\n";
    for (int j = 0; j < wiersze; j++) {
      for (int i = 0; i < kolumny; i++) {
        file << myMatrix[j][i] << " ";
      }
      file << "\n";
    }
  }
  file.close();
}

Macierz Macierz::multiply(Macierz m2) {
  double temp;
  Macierz matrixToMultiply(wiersze, m2.kolumny);

  if (m2.wiersze != kolumny)
    throw "Niepoprawna liczba wierszy";
  for (int i = 0; i < wiersze; i++) {
    for (int j = 0; j < m2.kolumny; j++) {
      temp = 0;
      for (int k = 0; k < kolumny; k++) {
        temp += (myMatrix[i][k]) * (m2.myMatrix[k][j]);
      }
      matrixToMultiply.set(i, j, temp);
    }
  }
  return matrixToMultiply;
}
int main() {
  srand(time(NULL));

  Macierz m2(4, 5);

  for (int i = 0; i < m2.getRows(); i++) {
    for (int j = 0; j < m2.getColumns(); j++) {
      m2.set(i, j, rand() % 10);
    }
  }

  m2.set(1, 1, 5);
  cout << m2.get(1, 1);


  Macierz m3(4, 5);

  for (int i = 0; i < m3.getRows(); i++) {
    for (int j = 0; j < m3.getColumns(); j++) {
      m3.set(i, j, rand() % 10);
    }
  }

  Macierz m4(5, 6);

  for (int i = 0; i < m4.getRows(); i++) {
    for (int j = 0; j < m4.getColumns(); j++) {
      m4.set(i, j, rand() % 10);
    }
  }

  Macierz m5(5);

  for (int i = 0; i < m5.getRows(); i++) {
    for (int j = 0; j < m5.getColumns(); j++) {
      m5.set(i, j, rand() % 10);
    }
  }
  cout << endl << "Macierz m2: " << endl;
  m2.print();
  cout << endl << "Macierz m3: " << endl;
  m3.print();
  cout << endl << "Macierz m4: " << endl;
  m4.print();
  cout << endl << "Macierz m5: " << endl;
  m5.print();

  cout << endl << "Dodawanie macierzy: " << endl;
  Macierz matrixToAdd(4, 5);
  matrixToAdd = m2.add(m3);
  matrixToAdd.print();

  cout << endl << "Odejmowanie macierzy: " << endl;
  Macierz matrixToSubstract(4, 5);
  matrixToSubstract = m3.substract(m2);
  matrixToSubstract.print();

  cout << endl << "Mnozenie macierzy: " << endl;
  Macierz matrixToMultiply(6, 4);
  matrixToMultiply = m3.multiply(m4);
  matrixToMultiply.print();

  m5.store("matrix.txt", "../"); // Zapisanie macierzy do pliku

  cout << endl << "Macierz z pliku: " << endl;
  Macierz matrixFromFile("macierz.txt", "../");

  matrixFromFile.print();
  exit(0);
}