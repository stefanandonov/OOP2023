//
// Created by Stefan Andonov on 24.3.23.
//


#include<iostream>
#include<cstring>

using namespace std;

class Employee {
private:
    char firstName[30];
    char lastName[30];
    int salary;
public:
    Employee(char *_firstName = "", char *_lastName = "", int salary = 0) : salary(salary) {
        strcpy(firstName, _firstName);
        strcpy(lastName, _lastName);
    }

    const char *getFirstName() const {
        return firstName;
    }

    const char *getLastName() const {
        return lastName;
    }

    int getSalary() const {
        return salary;
    }

    void print() {
        cout << firstName << " " << lastName << " " << salary << endl;
    }
};

class Factory { //kompozicija na vraboteni
private:
    Employee employees[100];
    int number;
public:
    Factory(Employee *_employees, int n) {
        number = n;
        for (int i = 0; i < n; i++) {
            employees[i] = _employees[i];
        }
    }

    void printEmployees() {
        cout << "Site vraboteni:" << endl;
        for (int i = 0; i < number; i++) {
            employees[i].print();
        }
    }

    void printEmployeesWithSalaryLargerThan(int minSalary) {
        cout << "Vraboteni so plata povisoka od "<< minSalary <<" :"<<endl;
        for (int i = 0; i < number; i++) {
            if (employees[i].getSalary() >= minSalary) {
                employees[i].print();
            }
        }
    }
};

int main() {
    int n;
    cin >> n;
    Employee employees[20];
    char name[30];
    char surname[30];
    int salary;
    int minSalary;

    for (int i = 0; i < n; i++) {
        cin >> name >> surname >> salary;
        employees[i] = Employee(name, surname, salary);
    }

    cin>>minSalary;

    Factory factory(employees, n);

    factory.printEmployees();

    factory.printEmployeesWithSalaryLargerThan(minSalary);
    return 0;
}
