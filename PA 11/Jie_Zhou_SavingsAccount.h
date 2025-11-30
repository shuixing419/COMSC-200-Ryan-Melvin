#ifndef JIE_ZHOU_SAVINGSACCOUNT_H
#define JIE_ZHOU_SAVINGSACCOUNT_H

#include "Jie_Zhou_Account.h"

// Savings account with interest calculation
class SavingsAccount : public Account {
public:
    SavingsAccount(double balance = 0.0, double interestRate = 0.0);
    double calculateInterest() const;

    // Operator overloads for savings account
    friend std::ostream& operator<<(std::ostream& os, const SavingsAccount& account);
    SavingsAccount& operator+=(double amount);
    SavingsAccount& operator-=(double amount);
    SavingsAccount operator+(double amount) const;
    SavingsAccount operator-(double amount) const;
    SavingsAccount& operator=(const SavingsAccount& other);

private:
    double interestRate;
};

#endif