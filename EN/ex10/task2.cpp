//
// Created by Stefan Andonov on 10.5.23.
//

#include<iostream>
#include<cstring>

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

class Discountable { //interface (class that only has pure virtual methods)
public:
    virtual int getPrice() = 0;

    virtual float getDiscountedPrice() = 0;

    virtual void print() = 0;
};

class FoodProduct : public Product, public Discountable {
private:
    int calories;
public:
    FoodProduct(char *name, int price, int calories) : Product(name, price), calories(calories) {}

    int getPrice() override {
        return price;
    }

    float getDiscountedPrice() override {
        if (calories > 500) {
            return price * 0.8; //20% discount
        }
        if (calories > 200) {
            return price * 0.85; //15% discount
        }
        if (calories > 100) {
            return price * 0.9; //10% discount
        }
        return price;
    }

    void print() override {
        cout << "Food product with name: " << name << " with " << calories << " calories. Price: " << getPrice() << " Discounted price: " << getDiscountedPrice() << endl;
    }
};

class DigitalProduct : public Product, public Discountable {
private:
    float size; // in MB
public:
    DigitalProduct(char *name, int price, float size) : Product(name, price), size(size) {

    }

    int getPrice() override {
        return price;
    }

    float getDiscountedPrice() override {
        if (size > 100 * 1024) {
            return price * 0.6; //40% discount
        }
        if (size > 10 * 1024) {
            return price * 0.8; // 20% discount
        }
        if (size > 1024) {
            return price * 0.95; //5% discount
        }
        return price;
    }

    void print() override {
        cout << "Digital product with name: " << name << " with " << size << " MBs of size. Price: " << getPrice() << " Discounted price: " << getDiscountedPrice() << endl;
    }
};

double totalDiscount(Discountable **discountableObjects, int n) {
    double sum = 0.0;
    for (int i = 0; i < n; i++) {
        sum+=(discountableObjects[i]->getPrice() - discountableObjects[i]->getDiscountedPrice());
    }
    return sum;
}

int main() {
    int n;
    cin >> n;
    Discountable ** dObjects = new Discountable * [n]; // dynamical allocation of array of points to Discountable objects

    for (int i=0;i<n;i++){
        int type; //1 == food product, 2 == digital product
        cin >> type;
        char name[50];
        int price;
        float size;
        int calories;
        if (type==1){ //food product
            cin >> name >> price >> calories;
            dObjects[i] = new FoodProduct(name, price, calories);
        } else { //digital product
            cin >> name >> price >> size;
            dObjects[i] = new DigitalProduct(name, price, size);
        }
    }

    for (int i=0;i<n;i++){
        dObjects[i]->print();
    }

    cout << "Total discount of the products is: " << totalDiscount(dObjects, n) << endl;
}