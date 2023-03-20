#include<stdio.h>

typedef struct Laptop {
    char company[100];
    float screenSize;
    int onTouch;
    int price;
} Laptop;

Laptop readLaptop() {
    Laptop laptop;
    scanf("%s%f%d%d", laptop.company,
          &laptop.screenSize,
          &laptop.onTouch,
          &laptop.price);
    return laptop;
}

void printLaptop(Laptop laptop) {
    printf("%s %g %d\n", laptop.company,
           laptop.screenSize,
           laptop.price);
}


typedef struct ITStore {
    char name[100];
    char location[100];
    Laptop laptops[100];
    int count;
} ITStore;

ITStore readStore() {
    ITStore itStore;
    scanf("%s%s%d", itStore.name,
          itStore.location,
          &itStore.count);

    for (int i = 0; i < itStore.count; i++) {
        itStore.laptops[i] = readLaptop();
    }
    return itStore;
}

void printStore(ITStore itStore) {
    printf("%s %s\n", itStore.name, itStore.location);
    for (int i = 0; i < itStore.count; i++) {
        printLaptop(itStore.laptops[i]);
    }
}


void najeftina_ponuda(ITStore *stores, int n) {
    int minPrice;
    int minStoreIdx;
    int flag = 1;
    for (int i = 0; i < n; i++) { //iterirame prodavnicite vo nizata stores
        for (int j = 0; j < stores[i].count; j++) { //iterirame laptopite vo i-ta prodavnica
            if (stores[i].laptops[j].onTouch){ //dali laptopot ima touchpad
                if (flag){ //za prviot onTouch laptop
                    minPrice = stores[i].laptops[j].price;
                    minStoreIdx = i;
                    flag = 0;
                } else { //za site posle prviot onTouch laptop
                    if (stores[i].laptops[j].price < minPrice){
                        minPrice = stores[i].laptops[j].price;
                        minStoreIdx = i;
                    }
                }
            }
        }
    }

    printf("Najeftina ponuda ima prodavnicata: \n"
           "%s %s\n"
           "Najniskata cena iznesuva: %d", stores[minStoreIdx].name, stores[minStoreIdx].location, minPrice);



}

int main() {
    ITStore itStores[100];
    int n;
    scanf("%d", &n); //broj na IT prodavnici

    //vnesuvanje na prodavnicite edna po edna, zaedno so raspolozlivite laptopvi vo niv
    for (int i = 0; i < n; i++) {
        itStores[i] = readStore();
    }


    //pecatenje na site prodavnici
    for (int i = 0; i < n; i++) {
        printStore(itStores[i]);
    }



    //povik na glavnata metoda
    najeftina_ponuda(itStores, n);

    return 0;
}