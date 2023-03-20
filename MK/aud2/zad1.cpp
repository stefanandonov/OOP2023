//
// Created by Stefan Andonov on 6.3.23.
//

#include<iostream>

using namespace std;

struct Person {
    char name [20];
    int age;

    void print (int adultAge){
        cout << "Name: " << name << " Age: " << age << (age>adultAge ? " YES" : " NO")<< endl;
    }
};

//void print (Person p) {
//    cout << "Name: " << p.name << " Age: " << p.age << endl;
//}

void read (Person &person) {
    cin >> person.name >> person.age;
}

Person read2 () {
    Person p;
    cin >> p.name >> p.age;
    return p;
}

void swap (int & a, int & b) {
    int tmp = a;
    a = b;
    b = tmp;
}
int main() {
//    Person p;
//    read(p);
//    p.print(18);

//    Person p2 = read2();
    //reference testing

    int value = 4;
    int & reff = value;

    reff++;
    cout << value << " " << reff << endl;

    int a = 5, b = 7;
    swap(a, b);
    cout << a << " " << b;

    int casted = (int) 6.5;
    int caster = int(6.5);

    return 0;
}