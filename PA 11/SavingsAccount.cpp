#include <iostream>
#include <iomanip>
#include "Jie_Zhou_SavingsAccount.h"

// Initialize savings account with balance and interest rate
SavingsAccount::SavingsAccount(double balance, double interestRate)
    : Account(balance), interestRate(interestRate) {
}

// Calculate interest based on current balance
double SavingsAccount::calculateInterest() const {
    return getBalance() * interestRate;
}

// Output savings account balance
std::ostream& operator<<(std::ostream& os, const SavingsAccount& account) {
    os << account.getBalance();
    return os;
}

// Add amount to savings account
SavingsAccount& SavingsAccount::operator+=(double amount) {
    credit(amount);
    return *this;
}

// Subtract amount from savings account
SavingsAccount& SavingsAccount::operator-=(double amount) {
    debit(amount);
    return *this;
}

// Create new savings account with amount added
SavingsAccount SavingsAccount::operator+(double amount) const {
    SavingsAccount temp = *this;
    temp += amount;
    return temp;
}

// Create new savings account with amount subtracted
SavingsAccount SavingsAccount::operator-(double amount) const {
    SavingsAccount temp = *this;
    temp -= amount;
    return temp;
}

// Assignment operator for savings account
SavingsAccount& SavingsAccount::operator=(const SavingsAccount& other) {
    if (this != &other) {
        Account::operator=(other);
        interestRate = other.interestRate;
    }
    return *this;
}