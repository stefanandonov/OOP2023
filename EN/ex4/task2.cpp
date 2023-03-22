//
// Created by Stefan Andonov on 22.3.23.
//

#include <cstring>
#include <iostream>

using namespace std;

enum GENDER {
    MALE, FEMALE
};

class Mate {
private:
    char name[20];
    int age;
    GENDER gender;

public:
    //    Mate(char *_name = "", int _age = 18, GENDER _gender = MALE) { //2in1
    //    const with args and default const
    //        strcpy(name, _name);
    //        age = _age;
    //        gender = _gender;
    //    }

    Mate(char *_name = "", int age = 18, GENDER gender = MALE)
            : age(age), gender(gender) {
        strcpy(name, _name);
    } // auto-generated from CLion

    Mate(const Mate &other) { //copy-constructor
        cout << "Copy constructor of class Mate is called here!!" << endl;
        strcpy(name, other.name);
        age = other.age;
        gender = other.gender;
    }

    void print() {
        cout << name << " " << age << " " << (gender == MALE ? "Male" : "Female") << endl;

//        switch (gender) {
//            case MALE: cout << "Male" << endl; break;
//            default: cout << "Female" << endl;
//        }
    }

    const char *getName() const {
        return name;
    }

    int getAge() const {
        return age;
    }

    GENDER getGender() const {
        return gender;
    }

    bool isSuccess (Mate & other) {
        return name[0] != other.name[0] && (abs(age - other.age) < 3);
    }
};

class Date { //composition of two mates
private:
    Mate boy;
    Mate girl;
public:
    Date(Mate _boy, Mate _girl) {
        boy = _boy;
        girl = _girl;
    }

    Date(const Date &other) { //copy-constructor
        boy = other.boy;
        girl = other.girl;
    }

    void print() {
        cout << "Date between: " << endl;
        boy.print();
        girl.print();
    }

    bool isSuccess() {
        return girl.isSuccess(boy); //implicitly call to the copy constructor of Mate
    }
};

int main() {
    Mate b("Stefan", 26, MALE);
    Mate g("Ana", 24, FEMALE);

    Mate m1; //default constructor will be called
    m1.print();


    Date date (b, g); //implicit calls of the copy constructors
    date.print();
    cout << date.isSuccess();
    return 0;
}
