#include <iostream>
#include <iomanip>
#include "Jie_Zhou_Account.h"

// Initialize account with starting balance
Account::Account(double balance) : balance(balance) {}

// Add amount to balance
void Account::credit(double amount) {
    balance += amount;
}

// Subtract amount from balance if sufficient funds
void Account::debit(double amount) {
    if (amount <= balance) {
        balance -= amount;
    }
    else {
        std::cout << "Debit amount exceeded account balance." << std::endl;
    }
}

// Return current balance
double Account::getBalance() const {
    return balance;
}

// Output account balance
std::ostream& operator<<(std::ostream& os, const Account& account) {
    os << account.balance;
    return os;
}

// Add amount to account using += operator
Account& Account::operator+=(double amount) {
    credit(amount);
    return *this;
}

// Subtract amount from account using -= operator
Account& Account::operator-=(double amount) {
    debit(amount);
    return *this;
}

// Create new account with amount added
Account Account::operator+(double amount) const {
    Account temp = *this;
    temp += amount;
    return temp;
}

// Create new account with amount subtracted
Account Account::operator-(double amount) const {
    Account temp = *this;
    temp -= amount;
    return temp;
}

// Assignment operator for account copying
Account& Account::operator=(const Account& other) {
    if (this != &other) {
        balance = other.balance;
    }
    return *this;
}