//
// Created by Stefan Andonov on 24.4.23.
//

#include<iostream>

using namespace std;

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

    bool withdraw(int amount) {
        if (amount <= balance) {
            balance -= amount;
            return true;
        } else {
            return false;
        }
    }

    friend ostream &operator<<(ostream &os, const DebitAccount &account) {
        os << "Account Owner: " << account.owner << " Number: " << account.number << " Balance: " << account.balance;
        return os;
    }
};

class CreditAccount : public DebitAccount {
private:
    float interestRate;
    int limit;
public:
    CreditAccount(char *owner, char *number, float interestRate, int limit) : DebitAccount(owner, number),
                                                                              interestRate(interestRate),
                                                                              limit(limit) {
    }

    friend ostream &operator<<(ostream &os, const CreditAccount &account) {
        os << "Credit " << static_cast<const DebitAccount &>(account) << " limit: " << account.limit;
        return os;
    }

    bool withdraw (int amount){
       if (DebitAccount::withdraw(amount)){
           return true;
       } else {
           if (balance>0){
               amount-=balance;
               balance = 0;
           }
           int calculatedInterest = (int) (amount * interestRate);
           if (balance - calculatedInterest - amount < limit){
               return false;
           } else {
               balance-=(calculatedInterest+amount);
               return true;
           }
       }

    }


};

int main (){
//    DebitAccount da ("Stefan", "1000000000000000");
//    cout << da << endl;

    CreditAccount ca ("Stefan", "1000000000000000", 0.01, -10000);
    cout << ca << endl;

    int n;
    cin >> n;
    for (int i=0;i<n;i++){
        int amount;
        cin >> amount;
        if (amount<0){
            cout << ca.withdraw(abs(amount)) << endl;
        } else {
            ca.deposit(amount);
        }
        cout << ca;
    }
}
