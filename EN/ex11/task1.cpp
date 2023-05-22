#include<iostream>
#include<cstring>

using namespace std;

class InvalidDateException {
private:
    int d, m, y;
public:
    InvalidDateException(int d, int m, int y) : d(d), m(m), y(y) {}

    void message() {
        //Invalid Date 32/12/2018
        cout << "Invalid Date " << d << "/" << m << "/" << y << endl;
    }
};

class NotSupportedCurrencyException {
private:
    char currency [4];
public:
    explicit NotSupportedCurrencyException(char *currency) {
        strcpy(this->currency, currency);
    }

    void message() {
        //GBP is not a supported currency
        cout << currency << " is not a supported currency" << endl;
    }
};

class Transaction {
protected:
    int d, m, y;
    double amount;
    static double EUR;
    static double USD;
    const static int MONTHS_IN_YEAR = 12;
    const static int DAYS_IN_MONTH = 31;
public:
    Transaction(int d, int m, int y, double amount) {
        if (d <= 0 || d > DAYS_IN_MONTH || m <= 0 || m > MONTHS_IN_YEAR) {
            throw InvalidDateException(d, m, y);
        }

        this->d = d;
        this->m = m;
        this->y = y;
        this->amount = amount;
    }

    virtual void print() = 0;

    virtual double toDenars() = 0;

    static void setEUR (double newEUR){
        EUR = newEUR;
    }

    static void setUSD (double newUSD){
        USD = newUSD;
    }
};

double Transaction::EUR = 61; //initialize a static variable
double Transaction::USD = 50;


class DenarsTransaction : public Transaction {
private:
public:
    DenarsTransaction(int d, int m, int y, double amount) : Transaction(d, m, y, amount) {}

    void print() override {
        //12/12/2012 1000 MKD
        cout << d << "/" << m << "/" << y << " " << amount << " MKD" << endl;

    }

    double toDenars() override {
        return amount;
    }
};



class ForeignCurrencyTransaction : public Transaction {
private:
    char currency[4];
public:
    ForeignCurrencyTransaction(int d, int m, int y, double amount, char *currency) : Transaction(d, m, y, amount) {
        if (strcmp(currency, "EUR")!=0 && strcmp(currency, "USD")!=0) {
            throw NotSupportedCurrencyException(currency);
        }


        strcpy(this->currency, currency);
    }

    void print() override {
        cout << d << "/" << m << "/" << y << " " << amount << " " << currency << endl;
    }

    double toDenars() override {
        if (strcmp(currency, "EUR") == 0) {
            return amount * EUR;
        } else { //USD
            return amount * USD;
        }
    }
};

class Account {
private:
    Transaction **transactions;
    int count;
    char number[16];
    double balance;

public:
    Account(char *number, double balance) : balance(balance) {
        strcpy(this->number, number);
        count = 0;
        transactions = new Transaction *[0];
    }

    Account &operator+=(Transaction *t) {
        Transaction **tmp = new Transaction *[count + 1];
        for (int i = 0; i < count; i++) {
            tmp[i] = transactions[i];
        }
        tmp[count++] = t;
        delete[] transactions;
        transactions = tmp;
        return *this;
    }
};

int main() {

    Account s("300047024112789", 1500);

    int n, den, mesec, godina, tip;
    double iznos;
    char valuta[4];

    cin >> n;
    cout << "===TRANSACTION ADDITION AND EXCEPTION HANDLING===" << endl;
    for (int i = 0; i < n; i++) {
        cin >> tip >> den >> mesec >> godina >> iznos;
        if (tip == 2) {
            cin >> valuta;
            try {
                Transaction *t = new ForeignCurrencyTransaction(den, mesec, godina, iznos, valuta);
                s += t;
            } catch (InvalidDateException &e) {
                e.message();
            } catch (NotSupportedCurrencyException &e){
                e.message();
            }

            //delete t;
        } else {
            try {
                Transaction *t = new DenarsTransaction(den, mesec, godina, iznos);
                s += t;
            } catch (InvalidDateException &e) {
                e.message();
            }

            //delete t;
        }

    }
    cout << "===TRANSACTIONS LIST===" << endl;
    s.printTranscations();
    cout << "===TRANSACTIONS REPORT IN DENARS===" << endl;
    s.reportInDenars();


    cout << "\n===CHANGE OF THE COURSE OF THE EUR AND USD===\n" << endl;


    double newEUR, newUSD;
    cin >> newEUR >> newUSD;
    Transaction::setEUR(newEUR);
    Transaction::setUSD(newUSD);
    cout << "===TRANSACTIONS REPORT IN DENARS===" << endl;
    s.reportInDenars();


    return 0;
}