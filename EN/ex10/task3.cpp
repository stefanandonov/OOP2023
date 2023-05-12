//
// Created by Stefan Andonov on 10.5.23.
//

#include<iostream>
#include<cmath>
using namespace std;

class SquarePeg {
protected:
    float a;
public:
    SquarePeg(float a) : a(a) {}

    friend class SquarePegAdapter;
};

class RoundPeg {
protected:
    float radius;
public:
    RoundPeg(float radius) : radius(radius) {}

    float getRadius() {
        return radius;
    }
};

class RoundHole {
private:
    float radius;
public:
    RoundHole(float radius) : radius(radius) {}

    bool canFit(RoundPeg *peg) {
        return peg->getRadius() <= radius;
    }
};

class SquarePegAdapter : public RoundPeg, public SquarePeg {
public:
    SquarePegAdapter(float a) : RoundPeg(a*sqrt(2)/2), SquarePeg(a) {}

    SquarePegAdapter(SquarePeg peg) : RoundPeg(peg.a*sqrt(2)/2), SquarePeg(peg.a) {}
};

int main() {
    RoundHole hole (10);
    RoundPeg * peg = new RoundPeg(10.0111);
    SquarePeg speg(14);
    RoundPeg * adapter = new SquarePegAdapter(speg);
    cout << hole.canFit(adapter);

    return 0;
}