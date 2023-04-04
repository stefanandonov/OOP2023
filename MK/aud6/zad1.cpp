//
// Created by Stefan Andonov on 4.4.23.
//

#include<iostream>
#include<cstring>
using namespace std;

enum Tip {
    LINUX,
    UNIX,
    WINDOWS
};

class OperativenSistem {
private:
    char *name;
    float version;
    Tip type;
    float size;

    void copy(const OperativenSistem &other) {
        this->name = new char[strlen(other.name) + 1];
        strcpy(this->name, other.name);
        this->version = other.version;
        this->type = other.type;
        this->size = other.size;
    }

public:
    OperativenSistem(char *name = "Linux", float version = 1.0, Tip tip = LINUX, float size = 10.0) {
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
        this->version = version;
        this->type = tip;
        this->size = size;
    }

    ~OperativenSistem() {
        delete[] name;
    }

    OperativenSistem(const OperativenSistem &other) {
        copy(other);
    }

    OperativenSistem &operator=(const OperativenSistem &other) {
        if (this == &other) {
            return *this;
        }

        delete[] name;
        copy(other);

        return *this;
    }

    void pecati() {
        //Ime: Ubuntu Verzija: 17.04 Tip: 1 Golemina:2.25GB
        cout << "Ime: " << name << " Verzija: " << version << " Tip: " << type << " Golemina:" << size << "GB" << endl;
    }

    bool ednakviSe(const OperativenSistem &os) {
        return strcmp(this->name, os.name) == 0 && this->size == os.size && this->type == os.type &&
               this->version == os.version;
    }

    int sporediVerzija(const OperativenSistem &os) {
        if (this->version == os.version) {
            return 0;
        } else if (this->version > os.version) {
            return 1;
        } else {
            return -1;
        }
    }

    bool istaFamilija(const OperativenSistem &sporedba) {
        return strcmp(this->name, sporedba.name) == 0 && this->type == sporedba.type;
    }
};

class Repozitorium {
private:
    char name[20];
    OperativenSistem *systems;
    int count;

    void copy(const Repozitorium &other) {
        this->count = other.count;
        strcpy(this->name, other.name);
        systems = new OperativenSistem[count];
//        strcpy(this->systems, other.systems); NOOOOO GOD NO!
        for (int i = 0; i < count; i++) {
            systems[i] = other.systems[i];
        }
    }

public:

    Repozitorium(char name[20] = "") {
        strcpy(this->name, name);
        count = 0;
        systems = new OperativenSistem[count];
    }

    Repozitorium(const Repozitorium &r) {
        copy(r);
    }

    ~Repozitorium() {
        delete[] systems;
    }

    void pecatiOperativniSistemi() {
        cout << "Repozitorium: " << name << endl;
        for (int i = 0; i < count; i++) {
            systems[i].pecati();
        }
    }

    void dodadi(const OperativenSistem &nov) {
        for (int i = 0; i < count; i++) {
            if (systems[i].istaFamilija(nov)) {
                if (systems[i].sporediVerzija(nov) == -1) {
                    systems[i] = nov;
                    return;
                }
            }
        }

        OperativenSistem *tmp = new OperativenSistem[count + 1];
        for (int i = 0; i < count; i++) {
            tmp[i] = systems[i];
        }
        tmp[count] = nov;
        ++count;
        delete[] systems;
        systems = tmp;
    }

    void izbrishi(const OperativenSistem &zaBrishenje) {
        int idx = -1;
        for (int i = 0; i < count; i++) {
            if (systems[i].ednakviSe(zaBrishenje)) {
                idx = i;
                break;
            }
        }

        if (idx != -1) {
            OperativenSistem * tmp = new OperativenSistem[count-1];
            int countTmp = 0;
            for (int i=0;i<count;i++){
                if (i!=idx){
                    tmp[countTmp] = systems[i];
                    ++countTmp;
                }
            }
            --count;
            delete [] systems;
            systems = tmp;
        }
    }
};

int main() {
    char repoName[20];
    cin >> repoName;
    Repozitorium repo;
    Repozitorium repozitorium = Repozitorium(repoName); //copy-constructor na Repozitorium
    int brojOperativniSistemi = 0;
    cin >> brojOperativniSistemi;
    char ime[20];
    float verzija;
    int tip;
    float golemina;
    for (int i = 0; i < brojOperativniSistemi; i++) {
        cin >> ime;
        cin >> verzija;
        cin >> tip;
        cin >> golemina;
        OperativenSistem os = OperativenSistem(ime, verzija, (Tip) tip, golemina);
        repozitorium.dodadi(os);
    }

    repozitorium.pecatiOperativniSistemi();
    cin >> ime;
    cin >> verzija;
    cin >> tip;
    cin >> golemina;
    OperativenSistem os = OperativenSistem(ime, verzija, (Tip) tip, golemina);
    cout << "=====Brishenje na operativen sistem=====" << endl;
    repozitorium.izbrishi(os);
    repozitorium.pecatiOperativniSistemi();
    return 0;
}