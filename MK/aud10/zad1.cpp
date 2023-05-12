//
// Created by Stefan Andonov on 12.5.23.
//

#include<iostream>
using namespace std;

class Vehicle {
protected:
    int acceleration;
public:
    Vehicle(int acceleration) : acceleration(acceleration) {
        cout << "Vehicle constructor called!" << endl;
    }

    virtual void print () {
        cout << "Vehicle with acceleration: " << acceleration << endl;
    }

    virtual void accelerate() = 0;
};

class Car : virtual public Vehicle {
public:
    Car(int acceleration) : Vehicle(acceleration) {
        cout << "Car constructor called!" << endl;
    }

    void print() override {
        cout << "Car with acceleration: " << acceleration << endl;
    }

    void accelerate() override {
        acceleration+=1;
    }
};

class Jet : virtual public Vehicle {
public:
    Jet(int acceleration) : Vehicle(acceleration) {
        cout << "Jet constructor called!" << endl;
    }

    void print() override {
        cout << "Jet with acceleration: " << acceleration << endl;
    }

    void accelerate() override {
        acceleration+=10;
    }
};

class JetCar: public Jet, public Car {
public:
    JetCar(int acceleration) : Vehicle(acceleration), Jet(acceleration), Car(acceleration) {
        cout << "JetCar constructor called!" << endl;
    }

    void print() override {
        cout << "JetCar with acceleration: " << acceleration << endl;
    }

    void accelerate() override {
        acceleration+=8;
    }

};

int main () {
//    Vehicle * vehicle1 = new Car(10);
//    vehicle1->accelerate();
//    vehicle1->print();
//
//    Vehicle * vehicle2 = new Jet(100);
//    vehicle2->accelerate();
//    vehicle2->print();

//    Vehicle * jetcar =  new JetCar(120);
//    jetcar->accelerate();
//    jetcar->print();

    Vehicle ** vehicles = new Vehicle * [5];
    for (int i=0;i<5;i++){
        int type; //1= car 2=jet 3=jet car
        int acc;

        cin >> type >> acc;

        if (type==1){
            vehicles[i] = new Car(acc);
        } else if (type == 2) {
            vehicles[i] = new Jet(acc);
        } else {
            vehicles[i] = new JetCar(acc);
        }
    }

    for (int i=0;i<5;i++){
        vehicles[i]->print();
        vehicles[i]->accelerate();
        vehicles[i]->print();
    }

    return 0;
}
