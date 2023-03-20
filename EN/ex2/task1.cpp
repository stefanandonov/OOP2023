//
// Created by Stefan Andonov on 6.3.23.
//

#include<iostream>

using namespace std;

struct Person {
    char name[20];
    int age;

    void print() {
        cout << "This person name is: " << name << " and he/she is " << age << " years old." << endl;
    }

//    void read() {
//        cin >> name >> age;
//    }
};

void readPerson (Person &p) {
    cin >> p.name >> p.age;
}


int main() {
//    Person p;
////    readPerson(p);
//    p.print();

    int value = 10;
    int value2 = 12;
//    int * vPtr = &value; pointers
    int * iptr;
    int & reff = value;

    reff++;
    cout << reff << " " << value << endl;

    reff = value2;
    reff++;
    cout << reff << " " << value2 << endl;


    int x = (int)6.5; //in C and SP
    x = int(6.5);
    return 0;
}
