#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool sprawdz(pair<string, double>& a, pair<string, double>& b) 
{
  return a.second < b.second;
}

class Employee
 {
public:
  string id;
  string imie;
  string nazwisko;
  string department;
  string position;

  Employee(string id, string name, string surname, string position)
    : id(id), imie(name), nazwisko(surname), position(position)
  {}
};

class HRMS 
{
public:
  vector<Employee> wszyscy;
  map<string, string> departmentpracownika;
  map<string, double> pensja;

  void add(Employee employee, string departmentId, double salary)
   {

    employee.department = departmentId;

    wszyscy.push_back(employee);

    pensja[employee.id] = salary;

    departmentpracownika[employee.id] = departmentId;

  }

  
  void printSalaries() 
  {

    cout << "Wyplaty: " << endl;

        for (auto& it : pensja)
        {

            cout << "ID Pracownika: " << it.first << " > " << it.second  << endl;
        }
  }


  void changeSalary(string employeeId, double salary)
   {

    map<string, double>::iterator it;

    it = pensja.find(employeeId);

         if (it != pensja.end())
        {
        
             pensja[employeeId] = salary;
    }
  }


  void printDepartment(string departmentId) 
  {

    cout << "Pracownicy w departamencie " << departmentId << ": " << endl;

        for (auto& it : departmentpracownika) 
        {

            if (it.second == departmentId) 
            {
               cout << "Employee Id: " << it.first << " => " << "Department : " << it.second << endl;
            }
        }
  }


  void printSalariesSorted() 
  {

    map<string, double> kopia = pensja;
    vector<pair<string, double>> temp;

        for (auto& it : kopia) 
        {
          temp.push_back(it);
        }

    sort(temp.begin(), temp.end(), sprawdz);
    cout << "Wyplaty posortowane: " << endl;

      for (auto& it : temp) 
      {
        cout << "Employee Id: " << it.first << " => " << it.second << endl;
      }
  }
};

int main() 
{

  Employee pracownik1("A", "Adam", "Mickiewicz", "Senior Pisarz");
  Employee pracownik2("B", "Henryk", "Sienkiewicz", "Senior Pisarz");
  Employee pracownik3("C", "Juliusz", "Słowacki", "Junior Pisarz");
  Employee pracownik4("D", "Jan", "Długosz", "Junior Pisarz");
  Employee pracownik5("E", "Jan", "Brzechwa", "Pisarz");
  Employee pracownik6("F", "Gal", "Anonim", "Stażysta");
  Employee pracownik7("G", "Zbigniew", "Herbert", "CEO");
  Employee pracownik8("H", "Witold", "Gombrowicz", "HR Manager");
  Employee pracownik9("I", "Jan", "Kochanowski", "Ksiegowy");
  Employee pracownik10("J", "Ignacy", "Krasicki", "Recepcjonista");

  HRMS HR;
  
  HR.add(pracownik1, "1", 5000);

  HR.add(pracownik2, "1", 6000);

  HR.add(pracownik3, "2", 10000);

  HR.add(pracownik4, "2", 8000);

  HR.add(pracownik5, "2", 12000);

  HR.add(pracownik6, "3", 8000);

  HR.add(pracownik7, "1", 16000);

  HR.add(pracownik8, "2", 7500);

  HR.add(pracownik9, "2", 6500);

  HR.add(pracownik10, "3", 2500);

  HR.printDepartment("1");  cout << endl;

  HR.printDepartment("2");  cout << endl;

  HR.printDepartment("3");  cout << endl;

  HR.printSalaries();  cout << endl;

  HR.changeSalary("D", 7000);

  HR.changeSalary("H", 3200);

  HR.changeSalary("I", 7500);

  HR.printSalariesSorted();

  cout << endl;
}