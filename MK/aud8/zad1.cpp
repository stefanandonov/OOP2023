//
// Created by Stefan Andonov on 25.4.23.
//

#include<iostream>

using namespace std;

class Student {
private:
    char id[7];
    int points;
public:
    Student(char *id, int points) : points(points) {
        strcpy(this->id, id);
    }

    friend ostream &operator<<(ostream &os, const Student &student) {
        os << "Id: " << student.id << " Points: " << student.points << " Grade: " << (student.points / 10 + 1);
        return os;
    }

    bool operator==(const Student &rhs) const {
        return strcmp(id, rhs.id) == 0;
    }

    bool operator!=(const Student &rhs) const {
        return !(rhs == *this);
    }

    bool operator<(const Student &rhs) const {
        return points < rhs.points;
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
};

class Square {
protected:
    int a;
public:
    Square(int a) : a(a) {
        cout << "Square constructor" << endl;
    }

    friend ostream &operator<<(ostream &os, const Square &square) {
        os << "a: " << square.a;
        return os;
    }

    int area(){
        return a*a;
    }
};

class Rectangle : public Square {
private:
    int b;
public:
    Rectangle(int a, int b) : Square(a)  {
        cout << "Rectangle constructor" << endl;
        this->b = b;
    }

    friend ostream &operator<<(ostream &os, const Rectangle &rectangle) {
        os << "a: " << rectangle.a << " b: " << rectangle.b;
        return os;
    }

    int area(){
        return a*b;
    }
};

int main() {
    Square s (4);
    cout << s << endl;
    cout << s.area() << endl;

    Rectangle r (4,5);
    cout << r << endl;
    cout << r.area() << endl;

    Square s2 = r;
    cout << s2 << endl;
    cout << s2.area() << endl;
    return 0;
}
