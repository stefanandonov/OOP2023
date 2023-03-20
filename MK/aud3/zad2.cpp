//
// Created by Stefan Andonov on 15.3.23.
//

#include<iostream>

using namespace std;

enum POSITION {
    REGULAR_EMPLOYEE, //0
    MANAGER, //1
    CEO //2
};

class Employee {
private:
    char name[20];
    int salary;
    POSITION position;
public:
    Employee(char *_name = "Stefan", int _salary = 20000, POSITION _position = REGULAR_EMPLOYEE) {
        strcpy(name, _name); //nikako name = _name;!!!!!!!!1111!1!!
        salary = _salary;
        position = _position;
    }

    void print() {
        cout << "Employee: " << name << " Salary: " << salary << " Position: ";
        switch (position) {
            case REGULAR_EMPLOYEE:
                cout << "N/A" << endl;
                break;
            case MANAGER:
                cout << "Manager" << endl;
                break;
            default:
                cout << "CEO" << endl;
                break;
        }
//        cout << endl;
    }

    int compare (Employee other){
        if (salary > other.salary){
            return 1;
        } else if (salary < other.salary){
            return -1;
        } else {
            return 0;
        }
    }

    const char *getName() const {
        return name;
    }

    int getSalary() const {
        return salary;
    }

    void setSalary(int salary) {
        Employee::salary = salary;
    }

    POSITION getPosition() const {
        return position;
    }

    void setPosition(POSITION position) {
        Employee::position = position;
    }
};

int main() {
    int n;
    cin >> n;

    Employee employees[10]; //default constructor se povikuva 10 pati!

    for (int i = 0; i < n; i++) {
        char name[20];
        int salary;
        int position;
        cin >> name >> salary >> position;
        employees[i] = Employee(name, salary, POSITION(position));
    }

    for (int i=0;i<n;i++){
        employees[i].print();
    }

    Employee max = employees[0];
    for (int i=1;i<n;i++){
        if (employees[i].getSalary()>max.getSalary()){
            max = employees[i];
        }
    }

    cout << "Employee with max salary" << endl;
    max.print();



//    Employee e;
//    Employee e1 ("Petko");
//    Employee e2 ("Trajce", 21000);
//    Employee e3 ("Riste", 100000, CEO);
//
//    e.print();
//    e1.print();
//    e2.print();
//    e3.print();
    return 0;
}