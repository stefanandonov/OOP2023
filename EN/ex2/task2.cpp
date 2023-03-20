//
// Created by Stefan Andonov on 6.3.23.
//
#include<iostream>

using namespace std;

struct Politician {
    char name[20];
    char party[20];

    void read() {
        cin >> name >> party;
    }

    void print() {
        cout << "President: " << name << " from party: " << party << endl;
    }
};

struct City {
    char name[20];
    int population;

    void read() {
        cin >> name >> population;
    }

    void print() {
        cout << "Capital: " << name << " Population: " << population << endl;
    }
};

struct Country {
    char name[20];
    Politician president;
    City capital;
    int population;

    void read() {
        cin >> name;
        president.read();
        capital.read();
        cin >> population;
    }

    void print() {
        cout << "Country: " << name << endl;
        president.print();
        capital.print();
        cout << "Country population: " << population << endl;
    }

    int compare(Country other) {
        int myPopulation = capital.population;
        int otherPopulation = other.capital.population;
        if (myPopulation > otherPopulation) {
            return 1;
        } else if (myPopulation < otherPopulation) {
            return -1;
        } else {
            return 0;
        }
    }
};

int main() {
    int n;
    cin >> n;//number of countries

    Country countries[100];

    for (int i = 0; i < n; i++) {
        countries[i].read();
    }

    printf("ALL COUNTRIES:\n");
    for (int i = 0; i < n; i++) {
        countries[i].print();
    }

    printf("PRESIDENT OF THE COUNTRY WITH LARGEST CAPITAL\n");


    Country max = countries[0];
    for (int i = 1; i < n; i++) {
        if (countries[i].compare(max) == 1) {
            max = countries[i];
        }
    }
    max.president.print();
    return 0;
}