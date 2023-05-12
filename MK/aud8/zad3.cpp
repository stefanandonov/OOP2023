#include <iostream>
#include <cstring>

using namespace std;
enum Status {
    NOT_WORKING, REPAIRING, WORKING
};

class Airplane {
private:
    char ID[12];
    char *companyName;

    char companyAirport[20];
    int status;
    int flightHours;
public:
    Airplane(const char *_ID = "", const char *_companyName = "", const char *_companyAirport = "",
             int _flightHours = 0, int _status = 0) {
        strcpy(ID, _ID);
        strcpy(companyAirport, _companyAirport);
        flightHours = _flightHours;
        status = _status;
        companyName = new char[strlen(_companyName) + 1];
        strcpy(companyName, _companyName);
    }

    Airplane(const Airplane &ap) {
        strcpy(ID, ap.ID);
        strcpy(companyAirport, ap.companyAirport);
        flightHours = ap.flightHours;
        status = ap.status;
        companyName = new char[strlen(companyName) + 1];
        strcpy(companyName, ap.companyName);
    }

    Airplane &operator=(const Airplane &ap) {
        if (this != &ap) {
            delete[]companyName;
            strcpy(ID, ap.ID);
            strcpy(companyAirport, ap.companyAirport);
            flightHours = ap.flightHours;
            status = ap.status;
            companyName = new char[strlen(companyName) + 1];
            strcpy(companyName, ap.companyName);
        }
        return *this;
    }

    void print() {
        cout << "ID: " << ID << " - ";
        if (status == 0) { cout << "NOT_WORKING "; }
        else if (status == 1) { cout << "REPAIRING "; }
        else
            cout << "WORKING ";
        cout << companyName << ", " << flightHours << ", " << companyAirport << endl;
    }
};

class AirportService {
private:
    char airportName[20];
    Airplane *AirplanesArray;
    int numAirplanes;
public:
    AirportService(char *_airportName = "") {
        strcpy(airportName, _airportName);
        AirplanesArray = 0;
        numAirplanes = 0;
    }

    AirportService(const AirportService &as) {
        strcpy(airportName, as.airportName);
        numAirplanes = as.numAirplanes;
        for (int i = 0; i < as.numAirplanes; i++) { AirplanesArray[i] = as.AirplanesArray[i]; }
    }

    AirportService &operator=(const AirportService &as) {
        if (this != &as) {
            delete[]AirplanesArray;
            strcpy(airportName, as.airportName);
            numAirplanes = as.numAirplanes;
            for (int i = 0; i < as.numAirplanes; i++) { AirplanesArray[i] = as.AirplanesArray[i]; }
        }
        return *this;
    }

    ~AirportService() { delete[]AirplanesArray; }

    void addAirplane(Airplane airplane) {}
};

int main() {
    int testCase;
    cin >> testCase;
    char ID[12];
    char company_name[20];
    char company_airport[20];
    int flight_hours;
    int state;
    if (testCase == 1) {
        cout << "TESTING CONSTRUCTOR FOR AIRPLANE" << endl;
        Airplane a;
        cout << "TEST FOR DEFAULT CONSTRUCTOR PASSED" << endl;
        Airplane a1("ZHN-96-TY", "FINKI-Airline", "TMF", 13);
        cout << "TEST FOR CONSTRUCTOR WITH 3 ARGUMENTS PASSED" << endl;
        Airplane a2("ZHN-96-TA", "FINKI1-Airline", "TMF", 13, 0);
        cout << "TEST FOR CONSTRUCTOR WITH 4 ARGUMENTS PASSED" << endl;
    } else if (testCase == 2) {
        cout << "TESTING COPY-CONSTRUCTOR AND OPERATOR = (ASSIGNMENT) FOR AIRPLANE" << endl;
        Airplane p("ZHN-96-TA", "FINKI-Airline", "TMF", 13, 0);
        Airplane p1(p);
        cout << "TEST FOR COPY CONSTRUCTOR PASSED" << endl;
        Airplane p2;
        p2 = p;
        cout << "TEST FOR OPERATOR = (ASSIGNMENT) PASSED" << endl;
    } else if (testCase == 3) {
        cout << "TESTING PRINT() FOR AIRPLANE" << endl;
        cin >> ID >> company_name >> company_airport >> flight_hours >> state;
        Airplane p(ID, company_name, company_airport, flight_hours, state);
        p.print();
    } else if (testCase == 4) {
        cout << "TESTING CONSTRUCTOR FOR AIRPORTSERVICE" << endl;
    }/* AirportService as("FINKI"); cout << "TEST PASSED" << endl; } else if (testCase == 5) { cout << "TESTING ADD() AND PRINT() FOR AIRPORTSERVICE" << endl; AirportService as("FINKI"); int n; cin>>n; for(int i=0; i<n; i++){ cin>>ID>>company_name>>company_airport>>flight_hours>>state; Airplane p(ID, company_name, company_airport, flight_hours, state); as.addAirplane(p); } as.print(); } else if (testCase == 6) { cout << "TESTING serviceOldestAirplane() AND PRINT() FOR AIRPORTSERVICE" << endl; AirportService as("FINKI"); int n; cin>>n; for(int i=0; i<n; i++){ cin>>ID>>company_name>>company_airport>>flight_hours>>state; Airplane p(ID, company_name, company_airport, flight_hours, state); as.addAirplane(p); } Airplane p = as.serviceOldestAirplane(); cout<<"Removed plane:"<<endl; p.print(); cout<<"-----------------"<<endl; as.print(); } else if (testCase == 7) { cout << "TESTING COPY CONSTRUCTOR AND OPERATOR = FOR AIRPORTSERVICE" << endl; AirportService as("FINKI"); Airplane a1("ZHN-96-TY", "FINKI-Airline", "TMF", 13); as.addAirplane(a1); AirportService s1 = as; //copy constructor AirportService s2; s2 = s1; //operator = s1.print(); s2.print(); }*/ return 0;
}