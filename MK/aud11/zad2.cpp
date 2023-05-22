//
// Created by Stefan Andonov on 24.4.23.
//

#include<iostream>

using namespace std;

class InsufficientAmountException {
private:
    int amount;
    int balance;
public:
    InsufficientAmountException(int amount, int balance) : amount(amount), balance(balance) {}

    void showMessage() {
        //You can't withdraw X MKD because you only have Y MKD.
        cout << "You can't withdraw " << amount << " MKD because you only have " << balance << " MKD." << endl;
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

    void withdraw(int amount) {
        if (amount > balance) {
            throw InsufficientAmountException(amount, balance);
        }
        balance -= amount;
    }

    friend ostream &operator<<(ostream &os, const DebitAccount &account) {
        os << "account owner: " << account.owner << " number: " << account.number << " balance: " << account.balance;
        return os;
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
                throw InsufficientAmountException(amount, balance);
            } else {
                balance -= (calculatedInterest + amount);
            }

        }
    }

    friend ostream &operator<<(ostream &os, const CreditAccount &account) {
        os << "credit " << static_cast<const DebitAccount &>(account) << " limit: " << account.limit;
        return os;
    }

    static void setInterestRate(float rate) {
        INTEREST_RATE = rate;
    }

};

float CreditAccount::INTEREST_RATE = 0.05; //5%

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
            } catch (InsufficientAmountException &e) {
                e.showMessage();
            }
        } else {
            ca.deposit(amount);
        }
        cout << ca;
    }
}
