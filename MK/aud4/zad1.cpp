//
// Created by Stefan Andonov on 24.3.23.
//


#include<iostream>
#include<cstring>

using namespace std;

class Boy {
private:
    char name[30];
    int age;
public:
    Boy(char *_name = "", int _age = 18) : age(_age) {
        strcpy(name, _name);
    }

    Boy(const Boy &other) {
        cout << "Boy copy-constructor" << endl;
        strcpy(name, other.name);
        age = other.age;
    }

    ~Boy() {
        //do nothing
    }

    const char *getName() const {
        return name;
    }

    int getAge() const {
        return age;
    }

    void setAge(int _age) {
        age = _age;
    }

    void print() {
        cout << "Momche: " << name << " " << age << endl;
    }
};

class Girl {
private:
    char name[30];
    int age;
public:
    Girl(char *_name = "", int _age = 18) : age(_age) {
        strcpy(name, _name);
    }

    Girl(const Girl &other) { // other e objektot kojsto go klonirame
        cout << "Girl copy-constructor" << endl;
        strcpy(name, other.name);
        age = other.age;
    }

    ~Girl() {
        //do nothing
    }

    const char *getName() const {
        return name;
    }

    int getAge() const {
        return age;
    }

    void setAge(int _age) {
        age = _age;
    }

    void print() {
        cout << "Devojche: " << name << " " << age << endl;
    }
};

class Date { //composition of one boy and one girl
private:
    Boy boy;
    Girl girl;
public:

    Date() {

    }
    Date(Boy & _boy, Girl & _girl) {
        boy = _boy;
        girl = _girl;
    }

    Date(const Date & other){
        boy = other.boy;
        girl = other.girl;
    }

    ~Date(){
        //do nothing
    }

    void print () {
        cout << "Sredba pomegju:" << endl;
        boy.print();
        girl.print();
    }

    bool match() {
        return boy.getAge() - girl.getAge() < 5;
    }
};

int main() {
    Boy boy("Stefan", 18);
    boy.print();

    Girl girl("Ana", 26);
    girl.print();


    Date date(boy, girl); //impliciten povik do copy-constructor
    date.print();
    cout << date.match();

//    Boy momcheKlonirano (boy); //ekspliciten nachin
//    Boy momcheKlonirano1 = boy; //copy-constructorot ekspliciten nachin
//
////    Boy necopyconstructor;
////    necopyconstructor = momche; //operator = assignment
//    momcheKlonirano.print();
//    momcheKlonirano1.print();
//
//    cout << &momche << " " << &momcheKlonirano;

    return 0;
}
