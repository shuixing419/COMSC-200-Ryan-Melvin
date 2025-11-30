#include <iostream>
#include <iomanip>
#include "Jie_Zhou_CheckingAccount.h"

// Initialize checking account with balance and fee
CheckingAccount::CheckingAccount(double balance, double fee)
    : Account(balance), fee(fee) {
}

// Charge transaction fee to account
void CheckingAccount::chargeFee() {
    debit(fee);
}

// Output checking account balance
std::ostream& operator<<(std::ostream& os, const CheckingAccount& account) {
    os << account.getBalance();
    return os;
}

// Add amount to checking account
CheckingAccount& CheckingAccount::operator+=(double amount) {
    credit(amount);
    return *this;
}

// Subtract amount from checking account
CheckingAccount& CheckingAccount::operator-=(double amount) {
    debit(amount);
    return *this;
}

// Create new checking account with amount added
CheckingAccount CheckingAccount::operator+(double amount) const {
    CheckingAccount temp = *this;
    temp += amount;
    return temp;
}

// Create new checking account with amount subtracted
CheckingAccount CheckingAccount::operator-(double amount) const {
    CheckingAccount temp = *this;
    temp -= amount;
    return temp;
}

// Assignment operator for checking account
CheckingAccount& CheckingAccount::operator=(const CheckingAccount& other) {
    if (this != &other) {
        Account::operator=(other);
        fee = other.fee;
    }
    return *this;
}