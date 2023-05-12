//
// Created by Stefan Andonov on 10.5.23.
//

#include<iostream>

using namespace std;

class Vehicle { //abstract class
protected:
    int a; //acceleration
public:
    Vehicle(int a) : a(a) {
        cout << "Vehicle constructor" << endl;
    }

    //polymorphism
    virtual void accelerate() = 0; //pure-virtual

    void print () {
        cout << "Acceleration: " << a << endl;
    }
};

class Car : virtual public Vehicle {
public:
    Car(int a) : Vehicle(a) {
        cout << "Car constructor" << endl;
    }

    virtual void drive () {
        cout << "Car is driving..." << endl;
    }

    void accelerate() {
        a++;
    }
};

class Jet : virtual public Vehicle {
public:
    Jet(int a) : Vehicle(a) {
        cout << "Jet constructor" << endl;
    }

    void accelerate() {
        a+=5;
    }

    virtual void fly() {
        cout << "Jet is flying" << endl;
    }
};

class JetCar : public Jet, public Car {
public:
    JetCar(int a) : Vehicle(a), Jet(a), Car(a) {
        cout << "JetCar constructor" << endl;
    }

    void drive() {
        cout << "JetCar is driving..." << endl;
    }

    void fly() override {
        cout << "JetCar is flying..." << endl;
    }

    void accelerate() override {
        a+=4;
    }

};

int main() {
    Vehicle * vehicle1 = new JetCar(10);
    Vehicle * vehicle2 = new Car(5);
    vehicle1->accelerate();
    vehicle1->print();

    vehicle2->accelerate();
    vehicle2->print();

    Car * castedCar = dynamic_cast<Car *>(vehicle2);
    castedCar->drive();

    Car * castedCar1= dynamic_cast<Car *>(vehicle1);
    castedCar1->drive();

    Vehicle * vehicle[5];
    for (int i=0;i<5;i++){
        int type;
        int acc;
        cin >> type >> acc;
        switch (type) {
            case 1:
                vehicle[i] = new Car(acc); break;
            case 2:
                vehicle[i] = new Jet(acc); break;
            default:
                vehicle[i] = new JetCar(acc); break;
        }
    }

    for (int i=0;i<5;i++){
        vehicle[i]->accelerate();
        vehicle[i]->print();
    }

    return 0;
}