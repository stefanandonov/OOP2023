//
// Created by Stefan Andonov on 6.3.23.
//

#include<iostream>

using namespace std;

struct Politician {
    char name[20];
    char party[20];

    void print() {
        cout << "President: " << name << " Party: " << party << endl;
    }
};

struct City {
    char name[20];
    int population;

    void print() {
        cout << "Capital city: " << name << " Population: " << population << endl;
    }
};

struct Country {
    char name[20];
    Politician president;
    City capital;
    int population;

    void print() {
        cout << "Country: " << name << endl;
        president.print();
        capital.print();
        cout << "Population: " << population << endl;
    }

    int countrycmp (Country other){
        int pMy = capital.population;
        int pOther = other.capital.population;

        if (pMy == pOther){
            return 0;
        } else if (pMy > pOther){
            return 1;
        } else {
            return -1;
        }
    }
};

void readCity(City &city) {
    cin >> city.name >> city.population;
}

void readPolitician(Politician &politician) {
    cin >> politician.name >> politician.party;
}

void readCountry(Country &country) {
    cin >> country.name;
    readPolitician(country.president);
    readCity(country.capital);
    cin >> country.population;
}

int main() {
    int n;
    cin >> n;

    Country countries[100];
    for (int i = 0; i < n; i++) {
        readCountry(countries[i]);
    }

//    for (int i = 0; i < n; i++) {
//        countries[i].print();
//    }

    Country max = countries[0];
    for (int i=1;i<n;i++){
        if (countries[i].countrycmp(max) == 1){
            max = countries[i];
        }
    }

    max.president.print();
    return 0;
}
