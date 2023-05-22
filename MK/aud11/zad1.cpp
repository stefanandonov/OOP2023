#include<iostream>
#include<cstring>

using namespace std;

class InvalidDateException {
private:
    int d, m, y;
public:
    InvalidDateException(int d, int m, int y) : d(d), m(m), y(y) {}

    void showMessage() {
        //Invalid Date 22/14/2018
        cout << "Invalid Date " << d << "/" << m << "/" << y << endl;

    }
};

class NotSupportedCurrencyException {
private:
    char currency[4];
public:
    NotSupportedCurrencyException(char *currency) {
        strcpy(this->currency, currency);
    }

    void showMessage() {
        //XXX is not a supported currency
        cout << currency << " is not a supported currency" << endl;
    }
};

class Transaction {
protected:
    int d, m, y;
    double amount;
    static double EUR;
    static double USD;
    const static int DAYS_IN_MONTH = 31;
    const static int MONTHS_IN_YEAR = 12;
    const static int ZERO = 0;
public:
    Transaction(int d, int m, int y, double amount) {
        if (d <= ZERO || d > DAYS_IN_MONTH || m <= ZERO || m > MONTHS_IN_YEAR) {
            throw InvalidDateException(d, m, y);
        }


        this->d = d;
        this->m = m;
        this->y = y;
        this->amount = amount;
    }

    static void setEUR(double eur) {
        EUR = eur;
    }

    static void setUSD(double usd) {
        USD = usd;
    }

    virtual double voDenari() = 0;

    virtual void pecati() = 0;
};

class DenarsTransaction : public Transaction {
public:
    DenarsTransaction(int d, int m, int y, double amount) : Transaction(d, m, y, amount) {}

    double voDenari() override {
        return amount;
    }

    void pecati() override {
        //20/4/2018 1857.55 MKD
        cout << d << "/" << m << "/" << y << " " << amount << " MKD" << endl;
    }
};

class ForeignCurrencyTransaction : public Transaction {
    char currency[4];
public:
    ForeignCurrencyTransaction(int d, int m, int y, double amount, char *currency) : Transaction(d, m, y, amount) {
        if (strcmp(currency, "USD") != 0 && strcmp(currency, "EUR") != 0) {
            throw NotSupportedCurrencyException(currency);
        }

        strcpy(this->currency, currency);
    }

    double voDenari() override {
        if (strcmp(currency, "EUR") == 0) {
            return amount * EUR;
        } else {
            return amount * USD;
        }
    }

    void pecati() override {
        cout << d << "/" << m << "/" << y << " " << amount << " " << currency << endl;
    }
};

double Transaction::EUR = 61.0;
double Transaction::USD = 50.0;

class Account {
private:
    Transaction **transactions;
    int count;
    char account[15];
    double startBalance;
public:
    Account(char *account, double startBalance) : startBalance(startBalance) {
        strcpy(this->account, account);
        count = 0;
        transactions = new Transaction *[count];

    }

    Account &operator+=(Transaction *t) {
        Transaction **tmp = new Transaction *[count + 1];
        for (int i = 0; i < count; i++) {
            tmp[i] = transactions[i];
        }
        tmp[count] = t;
        ++count;
        delete[] transactions;
        transactions = tmp;
        return *this;
    }
};

int main() {

    Account s("300047024112789", 1500);

    int n, den, mesec, godina, tip;
    double iznos;
    char valuta[3];

    cin >> n;
    cout << "===VNESUVANJE NA TRANSAKCIITE I SPRAVUVANJE SO ISKLUCOCI===" << endl;
    for (int i = 0; i < n; i++) {
        cin >> tip >> den >> mesec >> godina >> iznos;
        if (tip == 2) {
            cin >> valuta;

            try {
                Transaction *t = new ForeignCurrencyTransaction(den, mesec, godina, iznos, valuta);
                s += t;
            }
            catch (InvalidDateException &e) {
                e.showMessage();
            }
            catch (NotSupportedCurrencyException &e){
                e.showMessage();
            }

            //delete t;
        } else {
            try {
                Transaction *t = new DenarsTransaction(den, mesec, godina, iznos);
                s += t;
            } catch (InvalidDateException &e) {
                e.showMessage();
            }

            //delete t;
        }

    }
    cout << "===PECHATENJE NA SITE TRANSAKCII===" << endl;
    s.pecatiTransakcii();
    cout << "===IZVESHTAJ ZA SOSTOJBATA NA SMETKATA VO DENARI===" << endl;
    s.izvestajVoDenari();


    cout << "\n===PROMENA NA KURSOT NA EVROTO I DOLAROT===\n" << endl;


    double newEUR, newUSD;
    cin >> newEUR >> newUSD;
    Transaction::setEUR(newEUR);
    Transaction::setUSD(newUSD);
    cout << "===IZVESHTAJ ZA SOSTOJBATA NA SMETKATA VO DENARI===" << endl;
    s.izvestajVoDenari();


    return 0;
}