#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <locale>

using namespace std;


struct Employee {
    string name;
    int salary;
};

void createFile() {
    ofstream outFile("Work.dat", ios::out, ios::binary);

    if (outFile.is_open()) {
        outFile << "Иванов Иван Иванович; 45000\n";
        outFile << "Петров Петр Петрович; 55000\n";
        outFile << "Сидоров Сидор Сидорович; 55000\n";
        outFile << "Кузнецова Анна Александровна; 40000\n";
        outFile.close();
    }
    else {
        cerr << "Ошибка при открытии файла!" << endl;
    }
}


void findHighestSalary() {
    ifstream inFile("Work.dat", ios::in);

    vector<Employee> employees;
    string line;
    int maxSalary = -1;

    if (inFile.is_open()) {
        while (getline(inFile, line)) {
            size_t pos = line.find(';');
            string name = line.substr(0, pos);
            int salary = stoi(line.substr(pos + 2)); 

            employees.push_back({ name, salary });
            if (salary > maxSalary) {
                maxSalary = salary;
            }
        }
        inFile.close();
    }
    else {
        cerr << "Ошибка при открытии файла!" << endl;
        return;
    }

    cout << "Сотрудники с наибольшим заработком:\n";
    for (const auto& emp : employees) {
        if (emp.salary == maxSalary) {
            cout << emp.name << endl;
        }
    }
}


int main() {
   
    setlocale(LC_ALL, "rus");

    createFile();          
    findHighestSalary();    
    return 0;
}
