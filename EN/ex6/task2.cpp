#include<iostream>
#include<cstring>

using namespace std;

/*
    YOUR CODE HERE
*/

class Flight {
private:
    char departure[50];
    char arrival[50];
    double duration;
    double price;
public:
    Flight(char *departure = "", char *arrival = "", double duration = 0, double price = 0) : duration(duration),
                                                                                              price(price) {
        strcpy(this->departure, departure);
        strcpy(this->arrival, arrival);
    }

    void printDuration() {
        cout << int(duration) << "h:" << (duration - int(duration)) * 60 << "min";
    }

    void printFlight() {
        //City of departure -> Flight duration -> City of landing: price
        cout << departure << " -> ";
        printDuration();
        cout << " -> " << arrival << ": " << price << "EUR";
    }

    char *getDepartureCity() {
        return departure;
    }

    char *getArrivalCity() {
        return arrival;
    }

    bool equal(Flight other) {
//        return this->departure == other.departure; this is so wrong even though it compiles - results with false always!!!
        return strcmp(this->departure, other.departure) == 0 && strcmp(this->arrival, other.arrival) == 0;
    }

    bool checkDeparture(char *dep) {
        return strcmp(this->departure, dep) == 0;
    }

    bool checkArrival(char *arr) {
        return strcmp(this->arrival, arr) == 0;
    }

    bool checkBoth(char *dep, char *arr) {
        return checkDeparture(dep) && checkArrival(arr);
    }


};

class Airline {
private:
    char name[50];
    Flight *flights;
    int count;
public:
    Airline(char *name = "Wizzair") {
        strcpy(this->name, name);
        count = 0;
        flights = new Flight[count];
    }

    void addFlight(Flight f) {
        for (int i = 0; i < count; i++) {
            if (flights[i].equal(f)) {
                return;
            }
        }

        Flight *tmp = new Flight[count + 1];
        for (int i = 0; i < count; i++) {
            tmp[i] = flights[i];
        }
        tmp[count] = f;
        ++count;
        delete[] flights;
        flights = tmp;
    }

    Flight *getFlights() {
        return flights;
    }

    int getN() {
        return count;
    }

    Flight getFlight(int idx) {
        return flights[idx];
    }


};


void searchFlights(Airline airline, char dep[50], char arr[50]);

//DO NOT CHANGE THE MAIN FUNCTION!
int main() {

    int testCase;
    cin >> testCase;

    if (testCase == 1) {
        cout << "====Testing class Flight constructors and additional methods====" << endl;
        Flight f1;
        char dep[50], arr[50];
        double dur, pr;
        cin >> dep >> arr >> dur >> pr;
        Flight f2(dep, arr, dur, pr);
        cout << f2.getDepartureCity() << " " << f2.getArrivalCity() << endl;
        cout << "Testing OK" << endl;
    } else if (testCase == 2) {
        cout << "====Testing class Flight methods printDuration() and printFlight()====" << endl;
        char dep[50], arr[50];
        double dur, pr;
        cin >> dep >> arr >> dur >> pr;
        Flight f2(dep, arr, dur, pr);
        f2.printFlight();
        cout << endl;
    } else if (testCase == 3) {
        cout << "====Testing class Airplane constructors and methods====" << endl;
        Airline a("Wizzair");
        char dep[50], arr[50];
        double dur, pr;
        cin >> dep >> arr >> dur >> pr;
        Flight f1(dep, arr, dur, pr);
        a.addFlight(f1);
        Flight f3 = f1;
        a.addFlight(f3);
        a.getFlights()[0].printFlight();
        cout << endl;
        cout << a.getN() << endl;
        Airline b = a;
        b.getFlights()[0].printFlight();
        cout << endl;
        cin >> dep >> arr >> dur >> pr;
        Flight f2(dep, arr, dur, pr);
        b.addFlight(f2);
        b.getFlights()[1].printFlight();
        cout << endl;
        cout << "Testing OK" << endl;
    } else if (testCase == 4) {
        cout << "====Testing global function====" << endl;
        Airline a("Wizzair");
        char dep[50], arr[50];
        double dur, pr;
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> dep >> arr >> dur >> pr;
            Flight f(dep, arr, dur, pr);
            a.addFlight(f);
        }
        cin >> dep >> arr;
        searchFlights(a, dep, arr);
        cout << endl << "Testing OK" << endl;
    }

    return 0;
}

void searchFlights(Airline airline, char dep[50], char arr[50]) {
    //check direct flights
    bool found = false;
    for (int i = 0; i < airline.getN(); i++) {
        Flight flight = airline.getFlight(i);
        if (flight.checkBoth(dep, arr)) {
            flight.printFlight();
            found = true;
        }
    }

    //search for flight connected via one hub
    if (!found) {
        for (int i = 0; i < airline.getN(); i++) {
            Flight flight = airline.getFlight(i);
            if (flight.checkDeparture(dep)){
                for (int j = 0; j < airline.getN(); j++){
                    Flight secondFlight = airline.getFlight(j);
                    if (secondFlight.checkBoth(flight.getArrivalCity(), arr)) {
                        flight.printFlight();
                        cout << " 1 stop ";
                        secondFlight.printFlight();
                        cout << endl;
                        found = true;
                    }
                }
            }
        }
    }

    //check for no connection at all
    if (!found){
        cout << "No connection between the cities" << endl;
    }
}
