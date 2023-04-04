#include <iostream>
#include <cstring>

using namespace std;

// your code here

class Word {
private:
    char *word;

    void copy(const Word &other) {
        this->word = new char[strlen(other.word) + 1];
        strcpy(this->word, other.word);
    }

public:
    Word(char *word = "UNDEFINED") { //2in1 constructor
        this->word = new char[strlen(word) + 1];
        strcpy(this->word, word);
    }

    Word(const Word &w) {
        copy(w);
    }

    Word &operator=(const Word &other) {
        if (this == &other) {
            return *this;
        }

        delete[] word;
        copy(other);
        return *this;
    }

    ~Word() {
        delete [] word;
    }

    char *getWord() const {
        return word;
    }
};

class Sentence {
private:
    Word *words;
    int count;
    int totalCapacity;

    void copy(const Sentence &other) {
        this->count = other.count;
        this->totalCapacity = other.totalCapacity;
        words = new Word[this->totalCapacity];
        for (int i = 0; i < this->count; i++) {
            this->words[i] = other.words[i];
        }
    }

public:

    Sentence(int totalCapacity = 10) { //2in1
        this->totalCapacity = totalCapacity;
        this->count = 0;
        this->words = new Word[this->totalCapacity];
    }

    Sentence (const Sentence & s){
        copy(s);
    }

    Sentence & operator = (const Sentence & s){
        if (this==&s){
            return *this;
        }

        delete [] words;
        copy(s);
        return *this;
    }

    ~Sentence() {
        delete [] words;
    }

    void increaseCapacity() {
        Word * tmp = new Word[this->totalCapacity+10];
        for (int i=0;i<count;i++){
            tmp[i]=words[i];
        }
        delete [] words;
        words = tmp;
        this->totalCapacity+=10;
    }

    void add(Word word) {
        if (this->count == this->totalCapacity){
            increaseCapacity();
        }

        words[count]=word; //operator = is called again
        count++;
    }

    void print() {
        for (int i=0;i<count;i++){
            cout << words[i].getWord() << " ";
        }
        cout << endl;
    }

    void swap(int i, int j) {
        Word tmp = words[i]; //copy const
        words[i] = words[j]; // operator =
        words[j] = tmp; // operator =
    }
};

int main() {
    int n;
    cin >> n;
    cin.get();
    cout << "CONSTRUCTOR" << endl;
    Sentence s; // capacity = 10;
    cout << "ADD WORD" << endl;
    for (int i = 0; i < n; ++i) {
        char w[100];
        cin.getline(w, 100);
        Word word(w);
        s.add(word);
    }
    cout << "PRINT SENTENCE" << endl;
    s.print();
    cout << "COPY" << endl;
    Sentence x = s; //copy-constructor
    cout << "SWAP" << endl;
    x.swap(n / 2, n / 3);
    x.print();
    cout << "ORIGINAL" << endl;
    s.print();
    return 0;
}
