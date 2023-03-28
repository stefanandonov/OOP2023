//
// Created by Stefan Andonov on 28.3.23.
//

#include<iostream>

using namespace std;

class Array {
private:
    int *numbers;
    int capacity;
    int size;

    void copy(const Array &other) {
        this->capacity = other.capacity;
        this->size = other.size;
        this->numbers = new int[this->capacity];
        for (int i = 0; i < this->size; i++) {
            this->numbers[i] = other.numbers[i];
        }
    }

public:
    Array(int capacity = 5) { //2in1
        this->capacity = capacity;
        this->size = 0;
        this->numbers = new int[capacity];
    }

    Array(const Array &a) {
        copy(a);
    }

    Array &operator=(const Array &other) {
        if (this == &other) {
            return *this;
        }

        delete[] numbers;
        copy(other);
        return *this;
    }

    ~Array() {
        delete[] numbers;
    }

    void increaseCapacity() {
        // tmp array with double capacity
        int *tmp = new int[2 * capacity];
        //2. copy all elements
        for (int i = 0; i < size; i++) {
            tmp[i] = numbers[i];
        }
        //3. free the memory for numbers
        delete[] numbers;
        //4. make numbers to point to the same stuff as tmp
        numbers = tmp;
        //5. increase the int capacity
        capacity = 2 * capacity;
    }

    void add(int number) {
        if (size == capacity) {
            increaseCapacity();
        }
        numbers[size++] = number;

    }

    void print () {
        cout << "Array with capacity: " << capacity << endl;
        cout << "Has " << size << " elements (" << size*100.0/capacity << "%)"<<endl;
        if (size == 0) {
            cout << "EMPTY" << endl;
        } else {
            for (int i=0;i<size;i++){
                cout << numbers[i] << " ";
            }
        }
        cout << endl;
    }

    void change (int a, int b){
        for (int i=0;i<size;i++){
            if (numbers[i]==a){
                numbers[i]=b;
            }
        }
    }

    void deleteAll (int number){
        int * tmp = new int [capacity];
        int tmpSize = 0;
        for (int i=0;i<size;i++){
            if (numbers[i]!=number){
                tmp[tmpSize]=numbers[i];
                tmpSize++;
            }
        }

        size = tmpSize;
        delete [] numbers;
        numbers = tmp;
    }

};

int main() {
    Array array;
    array.print();

    for (int i=1;i<=100;i++){
        array.add(i%3);
//        if (i%5==0){
//            array.print();
//        }
    }

    array.print();

    array.change(0, 5);

    array.print();

    array.deleteAll(5);

    array.print();

    return 0;
}
