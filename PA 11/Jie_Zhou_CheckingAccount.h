#ifndef Jie_Zhou_CHECKINGACCOUNT_H
#define Jie_Zhou_CHECKINGACCOUNT_H

#include "Jie_Zhou_Account.h"

// Checking account with transaction fees
class CheckingAccount : public Account {
public:
    CheckingAccount(double balance = 0.0, double fee = 0.0);
    void chargeFee();

    // Operator overloads for checking account
    friend std::ostream& operator<<(std::ostream& os, const CheckingAccount& account);
    CheckingAccount& operator+=(double amount);
    CheckingAccount& operator-=(double amount);
    CheckingAccount operator+(double amount) const;
    CheckingAccount operator-(double amount) const;
    CheckingAccount& operator=(const CheckingAccount& other);

private:
    double fee;
};

#endif