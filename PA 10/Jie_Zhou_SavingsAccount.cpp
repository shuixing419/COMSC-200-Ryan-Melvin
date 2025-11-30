//Comment 3: This file contains the SavingsAccount class which is a derived class of the Account class using constuctors.
#include "Jie_Zhou_SavingsAccount.h"

SavingsAccount::SavingsAccount(double initialBalance, double rate)
    : Account(initialBalance), interestRate(rate) {

}

double SavingsAccount::calculateInterest() const {
    return getBalance() * interestRate;
}