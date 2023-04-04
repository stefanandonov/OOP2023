#include<iostream>
#include<cstring>

using namespace std;

// VASIOT KOD OVDE

//NE menuvaj nisto vo main funkcijata

class Busline {
private:
    char departureCity[50];
    char arrivalCity[50];
    int departureTime;
    int arrivalTime;
    float price;
public:
    Busline(char *departureCity = "Skopje",
            char *arrivalCity = "Negotino",
            int departureTime = 1800,
            int arrivalTime = 1930,
            float price = 7) : departureTime(departureTime), arrivalTime(arrivalTime),
                               price(price) {
        strcpy(this->departureCity, departureCity);
        strcpy(this->arrivalCity, arrivalCity);
    }

    double duration() {
        int hourDep = departureTime/100;
        int minDep = departureTime%100;

        int hourAr = arrivalTime/100;
        int minAr = arrivalTime%100;

        int timeElapsedDep = hourDep * 60 + minDep;
        int timeElapsedAr = hourAr * 60 + minAr;

        int diff = timeElapsedAr - timeElapsedDep;
        return diff / 60.0;
    }

    void printBusline() {
        //Skopje -> 2.5 -> Ohrid: 15EUR
        cout << departureCity << " -> " << duration() << " -> " << arrivalCity << ": " << price << "EUR" << endl;
    }

    char *getDepartureCity() {
        return departureCity;
    }

    char *getArrivalCity() {
        return arrivalCity;
    }

    bool equal (Busline & other){
        return strcmp(this->departureCity, other.departureCity)==0 && strcmp(this->arrivalCity, other.arrivalCity)==0;
    }
};

class BusOperator {
private:
    char name [50];
    Busline * buslines;
    int count;

    void copy (const BusOperator & other){
        this->count = other.count;
        strcpy(this->name, other.name);
        buslines = new Busline[count];
        for (int i=0;i<count;i++){
            buslines[i]=other.buslines[i];
        }
    }
public:
    BusOperator(char * name = "DajoTurs - Negotino"){
        strcpy(this->name, name);
        count = 0;
        buslines = new Busline[count];
    }

    BusOperator (const BusOperator & b){
        copy(b);
    }

    BusOperator & operator = (const BusOperator & other){
        if (this==&other){
            return *this;
        }

        delete [] buslines;
        copy(other);
        return *this;
    }

    ~BusOperator(){
        delete [] buslines;
    }

    void addBusline(Busline b) {
        for (int i=0;i<count;i++){
            if (buslines[i].equal(b)){
                return ;
            }
        }

        Busline * tmp = new Busline[count+1];
        for (int i=0;i<count;i++){
            tmp[i] = buslines[i];
        }
        tmp[count]=b;
        count++;
        delete [] buslines;
        buslines = tmp;
    }

    Busline *getBus() {
        return buslines;
    }

    int getN() {
        return count;
    }
};

void searchBuslines(BusOperator b, char departureCity[], char arrivalCity[]){

}

int main() {

    int testCase;
    cin >> testCase;

    if (testCase == 1) {
        cout << "====Testing class Busline constructors and additional methods====" << endl;
        Busline f1;
        char dep[50], arr[50];
        int dt, at;
        double pr;
        cin >> dep >> arr >> dt >> at >> pr;
        Busline f2(dep, arr, dt, at, pr);
        cout << f2.getDepartureCity() << " " << f2.getArrivalCity() << endl;
        cout << "Testing OK" << endl;
    } else if (testCase == 2) {
        cout << "====Testing class Busline methods duration() and printBusline()====" << endl;
        char dep[50], arr[50];
        int dt, at;
        double pr;
        cin >> dep >> arr >> dt >> at >> pr;
        Busline f2(dep, arr, dt, at, pr);
        f2.printBusline();
        cout << endl;
    }
    else if (testCase == 3) {
        cout << "====Testing class BusOperator constructors and methods====" << endl;
        BusOperator a("Strumica Ekspres");
        char dep[50], arr[50];
        int dt, at;
        double pr;
        cin >> dep >> arr >> dt >> at >> pr;
        Busline f1(dep, arr, dt, at, pr);
        a.addBusline(f1);
        Busline f3 = f1; //copy-con
        a.addBusline(f3);
        a.getBus()[0].printBusline();
        cout << endl;
        cout << a.getN() << endl;
        BusOperator b = a;
        b.getBus()[0].printBusline();
        cout << endl;
        cin >> dep >> arr >> dt >> at >> pr;
        Busline f2(dep, arr, dt, at, pr);
        b.addBusline(f2);
        b.getBus()[1].printBusline();
        cout << endl;
        cout << "Testing OK" << endl;
    } else if (testCase == 4) {
        cout << "====Testing global function====" << endl;
        BusOperator a("Strumica Ekspres");
        char dep[50], arr[50];
        double pr;
        int at, dt, n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> dep >> arr >> dt >> at >> pr;
            Busline f(dep, arr, dt, at, pr);
            a.addBusline(f);
        }
        cin >> dep >> arr;
        searchBuslines(a, dep, arr);
        cout << endl << "Testing OK" << endl;
    }

    return 0;
}