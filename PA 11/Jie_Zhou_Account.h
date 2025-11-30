#ifndef Jie_Zhou_ACCOUNT_H
#define Jie_Zhou_ACCOUNT_H

#include <iostream>

// Base bank account class with overloaded operators
class Account {
public:
    Account(double balance = 0.0);
    void credit(double amount);
    void debit(double amount);
    double getBalance() const;

    // Operator overloads for account operations
    friend std::ostream& operator<<(std::ostream& os, const Account& account);
    Account& operator+=(double amount);
    Account& operator-=(double amount);
    Account operator+(double amount) const;
    Account operator-(double amount) const;
    Account& operator=(const Account& other);

private:
    double balance;
};

#endif