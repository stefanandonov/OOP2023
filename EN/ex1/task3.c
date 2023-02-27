//
// Created by Stefan Andonov on 27.2.23.
//

#include<stdio.h>

typedef struct Politician {
    char name[20];
    char party[20];
} Politician ;

Politician readPolitician () {
    Politician p;
    scanf("%s %s", p.name, p.party);
    return p;
}

void printPolitician (Politician president) {
    printf("President: %s from party: %s\n", president.name, president.party);
}

typedef struct City {
    char name[20];
    int population;
} City;

City readCity() {
    City city;
    scanf("%s %d", city.name, &city.population);
    return city;
}

void printCity (City capital) {
    printf("Capital: %s Population: %d\n", capital.name, capital.population);
}

typedef struct Country {
    char name[20];
    Politician president;
    City capital;
    int population;
}Country;

Country readCountry () {
    Country country;
//    scanf("%s %s %s %s %d %d", country.name, country.president.name, country.president.party, country.capital.name, &country.capital.population, &country.population);
    scanf("%s", country.name);
    country.president = readPolitician();
    country.capital = readCity();
    scanf("%d", &country.population);
    return country;
}

void printCountry(Country country) {
    printf("Country: %s\n", country.name);
    printPolitician(country.president);
    printCity(country.capital);
    printf("Country population: %d\n", country.population);
}

int countrycmp (Country left, Country right) {
    if (left.capital.population > right.capital.population){
        return 1;
    } else if(left.capital.population < right.capital.population) {
        return -1;
    } else {
        return 0;
    }
}

int main () {

    int n;
    scanf("%d", &n);

    Country countries [100];

    for (int i=0;i<n;i++){
        countries[i] = readCountry();
    }

    printf("ALL COUNTRIES:\n");
    for (int i=0;i<n;i++){
        printCountry(countries[i]);
    }

    printf("PRESIDENT OF THE COUNTRY WITH LARGEST CAPITAL\n");


    Country max = countries[0];
    for (int i=1;i<n;i++){
        if (countrycmp(countries[i],max)==1){
            max = countries[i];
        }
    }
    printPolitician(max.president);


    return 0;
}