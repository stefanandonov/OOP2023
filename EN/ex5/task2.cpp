//
// Created by Stefan Andonov on 27.3.23.
//

#include<iostream>
#include<cstring>

using namespace std;

class Array {
private:
    int *content;
    int size;
    int capacity;

    void copy(const Array &other) {
        this->capacity = other.capacity;
        this->size = other.size;
        this->content = new int[this->capacity];
        for (int i = 0; i < this->size; i++) {
            this->content[i] = other.content[i];
        }
    }

public:
    Array(int capacity = 10) { //2in1 default and with arguments
        this->capacity = capacity;
        size = 0;
        content = new int[this->capacity];
    }

    Array(const Array &other) {
        copy(other);
    }

    Array &operator=(const Array &other) {
        if (this == &other) {
            return *this;
        }

        delete[] content;
        copy(other);
        return *this;
    }

    ~Array() {
        delete[] content;
    }

    void increaseCapacity() {
        int *tmp = new int[2 * capacity];
        for (int i = 0; i < size; i++) {
            tmp[i] = content[i];
        }
        delete[] content;
        content = tmp;
        capacity = 2 * capacity;
    }

    void add(int number) {
        if (size == capacity) {
            increaseCapacity();
        }

        content[size] = number;
        ++size;
    }

    void print() {
        cout << "Array with capacity: " << capacity << " and size of :" << size << " (Percentage of used: "
             << (size * 100.0) / capacity << "%) Elements: " << endl;
        if (size == 0) {
            cout << "EMPTY" << endl;
        } else {
            for (int i = 0; i < size; i++) {
                cout << content[i];
                if (i != size - 1) {
                    cout << ", ";
                }
            }
            cout << endl;
        }
    }

    void replaceAll(int a, int b) {
        for (int i = 0; i < size; i++) {
            if (content[i] == a) {
                content[i] = b;
            }
        }
    }

    void deleteAll(int number) {
        int j = 0;
        int * tmp = new int [capacity];
        for (int i = 0; i < size; i++) {
            if (content[i]!=number){
                tmp[j]=content[i];
                ++j;
            }
        }

        size = j+1;

        delete [] content;
        content = tmp;

    }


};

int main() {
    Array array;
    array.print();
    for (int i = 1; i <= 100; i++) {
        array.add(i%2);
    }

    array.print();

    array.deleteAll(1);

    array.print();

    return 0;
}
