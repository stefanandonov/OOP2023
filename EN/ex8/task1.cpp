//
// Created by Stefan Andonov on 24.4.23.
//

#include<iostream>
#include<cstring>
using namespace std;

class Student {
private:
    char name[50];
    int grade;
public:
    Student(char *name = "Stefan", int grade = 5) :  grade(grade) {
        strcpy(this->name, name);
    }

    friend ostream &operator<<(ostream &os, const Student &student) {
        os << "Name: " << student.name << " Grade: " << student.grade;
        return os;
    }

    bool operator<(const Student &rhs) const {
        return grade < rhs.grade;
    }

    bool operator>(const Student &rhs) const {
        return rhs < *this;
    }

    bool operator<=(const Student &rhs) const {
        return !(rhs < *this);
    }

    bool operator>=(const Student &rhs) const {
        return !(*this < rhs);
    }

    bool operator==(const Student &rhs) const {
        return strcmp(name,rhs.name)==0;
    }

    bool operator!=(const Student &rhs) const {
        return !(rhs == *this);
    }
};

class Square {
protected:
    int a;
public:
    Square(int a) : a(a) {
//        cout << "Square constructor" << endl;
    }

    friend ostream &operator<<(ostream &os, const Square &square) {
        os << "a: " << square.a;
        return os;
    }

    virtual int area () {
        return a*a;
    }

    ~Square() {
//        cout << "Square destructor" << endl;
    }
};

class Rectange : public Square{
private:
    int b;
public:
    Rectange(int a, int b) : Square(a) {
        this->b = b;
//        cout << "Rectangle constructor" << endl;
    }

    ~Rectange() {
//        cout << "Rectangle destructor" << endl;
    }

    int area (){
        return a*b;
    }

    friend ostream &operator<<(ostream &os, const Rectange &rectange) {
        os << "a: " << rectange.a << " b: " << rectange.b;
        return os;
    }
};

int main () {
    Rectange r (4,5);
    cout << r.area() << endl;
    cout << r << endl;

    Square s = Rectange(4,5);
    cout << s << endl;
    cout << s.area() << endl;
    return 0;
}