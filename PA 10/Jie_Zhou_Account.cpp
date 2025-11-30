#include "Jie_Zhou_Account.h"
#include <iostream>

// Comment 4: This is responsible for setting the initial balance of an account
Account::Account(double initialBalance) {
    if (initialBalance >= 0.0) {
        balance = initialBalance;
    }
    else {
        balance = 0.0;
    }
}
// Comment 5: This is responsible for adding an amount to the current balance
void Account::credit(double amount) {
    balance += amount;
}
// Comment 6: This is responsible for withdrawing money from the account
bool Account::debit(double amount) {
    if (amount > balance) {
        return false;
    }
    else {
        balance -= amount;
        return true;
    }
}
// Comment 7: This is responsible for getting the current balance
double Account::getBalance() const {
    return balance;
}