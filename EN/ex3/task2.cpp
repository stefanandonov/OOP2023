//
// Created by Stefan Andonov on 13.3.23.
//

#include<iostream>
#include<cmath>

using namespace std;

class Triangle {
    float a, b, c;
public:
    Triangle(float _a, float _b, float _c) {
        a = _a;
        b = _b;
        c = _c;
    }

    Triangle(float _h, float _c) {
        a = _c;
        b = _c;
        c = _h;
    }


    Triangle(float side = 1) { //2 in 1 constructor
        a = side;
        b = side;
        c = side;
    }

    void print() {
        cout << "a: " << a << " b: " << b << " c: " << c << " Perimeter: " << perimeter() << " Area: " << area()
             << endl;
    }

    float perimeter() {
        return a + b + c;
    }

    float area() {
        float s = perimeter() / 2;
        return sqrt(s * (s - a) * (s - b) * (s - c));
    }

};

int main() {
//    Triangle t;
//    t.print();
//
//    Triangle ramnostran(5);
//    ramnostran.print();
//
//    Triangle raznostran(3, 4, 5);
//    raznostran.print();
//
//    Triangle ramnokrak(7, 4);
//    ramnokrak.print();

    Triangle triangles[5];

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        float a, b, c;
        cin >> a >> b >> c;
        triangles[i] = Triangle(a, b, c);
    }

    for (int i = 0; i < n; i++) {
        triangles[i].print();
    }


    return 0;
}