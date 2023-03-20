//
// Created by Stefan Andonov on 13.3.23.
//

#include<iostream>
#include<string.h>
using namespace std;

class Person {
private:
    char EMBG[14];
    char name[20];
    int age;
    char gender;
    int height;
    int weight;
public:
    //default constructor
//    Person(){
//        strcpy(name,"BEZIMENKO");
//    }

    //constructors with arguments
    Person(char * _name = "BEZIMENKO"){ //NESCAFE 2in1
        strcpy(name, _name);
    }

    Person(char * _name, int _age){
        strcpy(name, _name);
        age = _age;
    }

    Person(char * _name, int _age, char _gender){
        strcpy(name, _name);
        age = _age;
        gender = _gender;
    }

    ~Person(){
        //empty
    }


    void print() {
        cout << "This is person: " << name << " old " << age << " years."<< endl;
    }


};

int main() {
    Person p1("Stefan", 26, 'M');
    Person p2 ("Petko");

    Person p3;

    p1.print();
    p2.print();
    p3.print();
    return 0;
}