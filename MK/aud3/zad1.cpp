//
// Created by Stefan Andonov on 15.3.23.
//

#include<iostream>
#include<cmath>

using namespace std;

class Triangle {
private:
    int a, b, c;
public:

    Triangle() {
        a = b = c = 1;
    }

    Triangle(int _a, int _b, int _c) {
    //konstruktor so (3) argumenti
        a = _a;
        b = _b;
        c = _c;
    }

    Triangle(int side) {
        a = side;
        b = side;
        c = side;
    }

    Triangle(int h, int k) {
        c = h;
        a = k;
        b = k;
    }

    void print() {
        cout << "a: " << a << " b: " << b << " c: " << c << " Perimeter: " << perimeter() << " Area: " << area() << endl;
    }

    int perimeter () {
        return a+b+c;
    }

    float area () {
        float s = perimeter()/2.0;
        return sqrt(s*(s-a)*(s-b)*(s-c));
    }

    ~Triangle(){
        //do nothing
    }

};

int main() {

    Triangle raznostran(3, 4, 5);
    Triangle ramnostran(3);
    Triangle ramnokrak(4, 3);
    Triangle empty;


    Triangle array[10]; //10 pati se povikuva default konstruktorot.

    raznostran.print();
    ramnostran.print();
    ramnokrak.print();
    empty.print();

    for (int i = 0; i < 10; i++) {
        array[i].print();
    }
    return 0;
}