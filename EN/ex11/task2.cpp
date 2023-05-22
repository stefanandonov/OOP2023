//
// Created by Stefan Andonov on 24.4.23.
//

#include<iostream>

using namespace std;

class InsufficientAmountException {
private:
    int balance;
    int amount;
public:
    InsufficientAmountException(int balance, int amount) : balance(balance), amount(amount) {}

    void message() {
        //You are trying to withdraw X MKD, but you only have Y MKD.
        cout << "You are trying to withdraw " << amount << " MKD, but you only have " << balance << " MKD" << endl;
    }
};

class DebitAccount {
protected:
    char owner[100];
    char number[17];
    int balance;
public:
    DebitAccount(char *owner, char *number) {
        strcpy(this->owner, owner);
        strcpy(this->number, number);
        this->balance = 0;
    }

    void deposit(int amount) {
        balance += amount;
    }

    virtual void withdraw(int amount) {
        if (amount > balance){
            throw InsufficientAmountException(balance, amount);
        }
        balance -= amount;
    }

    };

class CreditAccount : public DebitAccount {
private:
    static float INTEREST_RATE;
    int limit;
public:
    CreditAccount(char *owner, char *number, int limit) : DebitAccount(owner, number),
                                                                              limit(limit) {
    }

    void withdraw(int amount) {
        try {
            DebitAccount::withdraw(amount);
        } catch (InsufficientAmountException &e) {
            if (balance > 0) {
                amount -= balance;
                balance = 0;
            }
            int calculatedInterest = (int) (amount * INTEREST_RATE);
            if (balance - calculatedInterest - amount < limit) {
                throw InsufficientAmountException(balance, amount);
            } else {
                balance -= (calculatedInterest + amount);
            }
        }

    }

    };

float CreditAccount::INTEREST_RATE = 0.01; //1%

int main() {
//    DebitAccount da ("Stefan", "1000000000000000");
//    cout << da << endl;

    CreditAccount ca("Stefan", "1000000000000000", -10000);
    cout << ca << endl;

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int amount;
        cin >> amount;
        if (amount < 0) {
            try {
                ca.withdraw(abs(amount));
            }
            catch (InsufficientAmountException & e) {
                e.message();
            }

        } else {
            ca.deposit(amount);
        }
        cout << ca;
    }
}
