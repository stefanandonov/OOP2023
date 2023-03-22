//
// Created by Stefan Andonov on 22.3.23.
//

#include<iostream>
#include<cstring>

using namespace std;

class Person {
private:
    char name [20];
    int age;
public:
    Person(char * _name, int _age){
        strcpy(name, _name);
        age = _age;
    }

    Person(){
        strcpy(name, "NONAME");
        age = 18;
    }

    //copy-constructor

    Person(const Person & other){
        strcpy(name, other.name);
        age = other.age;
    }

    void print() {
        cout << "Name: " << name << " Age: " << age << endl;
    }

};

int main (){

    Person stefan ("Stefan", 26);
    stefan.print();

    Person defaultP;//default constructor is called
    defaultP.print();

    //explicit usage of the copy constructor
    Person cloneOfStefan (stefan);
    cloneOfStefan.print();

    cout << &stefan << " "  << &cloneOfStefan;
    return 0;
}
