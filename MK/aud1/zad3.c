//
// Created by Stefan Andonov on 27.2.23.
//

#include<stdio.h>

typedef struct Politician {
    char name [20];
    char party [20];
} Politician;

typedef struct City {
    char name [20];
    int population;
} City;

typedef struct Country {
    char name [20];
    Politician president;
    City capital;
    int population;
} Country;

Politician readPolitician () {
    Politician p;
    scanf("%s %s", p.name, p.party);
    return p;
}

void printPolitician (Politician p) {
    printf("President: %s Party: %s\n", p.name, p.party);
}

City readCity () {
    City c;
    scanf("%s %d", c.name, &c.population);
    return c;
}

void printCity (City c) {
    printf("Capital city: %s Population: %d\n", c.name, c.population);
}

Country readCountry() {
    Country c;
    scanf("%s", c.name);
    c.president = readPolitician();
    c.capital = readCity();
    scanf("%d", &c.population);
    return c;
}

void printCountry (Country c){
    printf("Country: %s\n", c.name);
    printPolitician(c.president);
    printCity(c.capital);
    printf("Population: %d", c.population);
}

int main () {

    Country country = readCountry();
    printCountry(country);

    return 0;
}
