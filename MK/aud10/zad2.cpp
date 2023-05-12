//
// Created by Stefan Andonov on 12.5.23.
//

#include<iostream>

using namespace std;

class Product {
protected:
    char name[50];
    int price;
public:
    Product(char *name, int price) : price(price) {
        strcpy(this->name, name);
    }
};

//interface
class Discountable {
public:
    virtual int getBasePrice() = 0;

    virtual int getPriceWithDiscount() = 0;

    virtual void print () = 0;
};

class FoodProduct : public Product, public Discountable {
private:
    int expirationDaysLeft;
public:
    FoodProduct(char *name, int price, int expirationDaysLeft) : Product(name, price),
                                                                 expirationDaysLeft(expirationDaysLeft) {}

    int getBasePrice() override {
        return price;
    }

    int getPriceWithDiscount() override {
        if (expirationDaysLeft <= 5) {
            return price * 0.5;
        }
        if (expirationDaysLeft <= 10) {
            return price * 0.75; //25% discount
        }
        if (expirationDaysLeft <= 30) {
            return price * 0.9; //10% discount
        }
        return price; //no discount
    }

    void print() override {
        cout << "Food product with name: " << name << " and expiration days left: " << expirationDaysLeft << " has base price: " << getBasePrice() << " and discounted price: " << getPriceWithDiscount() << endl;
    }

};

class DigitalProduct : public Product, public Discountable {
private:
    float size; //in GBs
public:
    DigitalProduct(char *name, int price, float size) : Product(name, price), size(size) {}

    int getBasePrice() override {
        return price;
    }

    int getPriceWithDiscount() override {
        if (size >= 1024) { //1 TB
            return price * 0.75; //25% popust
        }
        if (size > 512) { //0.5 TB
            return price * 0.9; //10% popust
        }
        return price;
    }

    void print() override {
        cout << "Digital product with name: " << name << " and size: " << size << "GB has base price: " << getBasePrice() << " and discounted price: " << getPriceWithDiscount() << endl;
    }
};

float savings (Discountable ** products, int n){
    float sum = 0.0;
    for (int i = 0; i < n; ++i) {
        sum+=(products[i]->getBasePrice()-products[i]->getPriceWithDiscount());
    }
    return sum;
}

int main() {
    int n;
    cin >> n;

    Discountable ** products = new Discountable * [n];

    for (int i=0;i<n;i++){
        int type; //1 food product , 2 digital product
        cin >> type;
        char name [50];
        int price, expiration;
        float size;
        if (type==1){
            cin >> name >> price >> expiration;
            products[i] = new FoodProduct(name, price, expiration);
        } else {
            cin >> name >> price >> size;
            products[i] = new DigitalProduct(name, price, size);
        }

    }

    for (int i=0;i<n;i++){
        products[i]->print();
    }

    cout << "Total savings from the above products is: " << savings(products, n);
    return 0;
}
