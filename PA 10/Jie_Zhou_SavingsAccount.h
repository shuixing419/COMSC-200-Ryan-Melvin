//Comment 2: The file defines a class called SavingsAccount which inherits from Account class and includes a function to calculate the interest.
#ifndef Jie_Zhou_SAVINGSACCOUNT_H
#define Jie_Zhou_SAVINGSACCOUNT_H

#include "Jie_Zhou_Account.h"

class SavingsAccount : public Account {
public:
    SavingsAccount(double initialBalance, double rate);
    double calculateInterest() const;

private:
    double interestRate;
};

#endif#pragma once
