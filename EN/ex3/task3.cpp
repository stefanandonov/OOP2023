//
// Created by Stefan Andonov on 13.3.23.
//

#include<iostream>
#include<string.h>

using namespace std;

enum POSITION {
    EMPLOYEE, //=0
    MANAGER, //=1
    OWNER //2
};

class Employee {
private:
    char name[20];
    int salary;
    POSITION position;
public:

    Employee(char *_name = "Stefan", int _salary = 18000, POSITION _position = (POSITION) 0) {
        strcpy(name, _name);
        salary = _salary;
        position = _position;
    }

    void print() {
        cout << "Employee: " << name << " Salary: " << salary << " Position: ";
        switch (position) {
            case EMPLOYEE:
                cout << "N/A" << endl;
                break;
            case MANAGER:
                cout << "Manager" << endl;
                break;
            default:
                cout << "CEO & Owner" << endl;
        }
    }

    int compare(Employee other) {
        if (salary == other.salary) {
            return 0;
        } else if (salary > other.salary) {
            return 1;
        } else {
            return -1;
        }
    }
};

int main() {

    int n;
    cin >> n;

    Employee employees[10]; //default constructors is called 10 times!!!!!!!!!!q112111111

    for (int i = 0; i < n; i++) {
        char name[20];
        int salary;
        int pos;
        cin >> name >> salary >> pos;
        employees[i] = Employee(name, salary, (POSITION) pos);
    }

    for (int i = 0; i < n; i++) {
        employees[i].print();
    }

    Employee max = employees[0];
    for (int i = 1; i < n; i++) {
        if (employees[i].compare(max) == 1) {
            max = employees[i];
        }
    }

    cout << "HIGHEST PAID EMPLOYEE IN THE COMPANY" << endl;
    max.print();

//    Employee stefan ("Stefan");
//    Employee trajce ("Trajce", 22000);
//    Employee boss ("Riste", 180000, OWNER);


    return 0;
}