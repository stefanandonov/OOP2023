//
// Created by Stefan Andonov on 12.5.23.
//

#include<iostream>
#include<cmath>
using namespace std;

class RoundPeg {
protected:
    float radius;
public:
    RoundPeg(float  radius) : radius(radius) {}

    virtual float getRadius() {
        return radius;
    }
};

class SquarePeg {
protected:
    float side;
public:
    SquarePeg(float side) : side(side) {}
};

class RoundHole {
private:
    float radius;
public:
    RoundHole(float radius) : radius(radius) {}

    bool canFit (RoundPeg * peg){
        return peg->getRadius() <= this->radius;
    }
};

class SquarePegAdapter: public RoundPeg, public SquarePeg {
public:
    SquarePegAdapter(float side) : RoundPeg(side*sqrt(2)/2), SquarePeg(side) {}
};

int main () {
    RoundHole hole (15);
    RoundPeg * peg1 = new RoundPeg(15);

    RoundPeg * peg2 = new SquarePegAdapter(22);
    cout << hole.canFit(peg1) << endl;
    cout << hole.canFit(peg2);
    return 0;
}
