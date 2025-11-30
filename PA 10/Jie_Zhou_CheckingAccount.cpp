#include "Jie_Zhou_CheckingAccount.h"
#include <iostream>

// Comment 9: This is responsible for setting the initial balance of an account and the transaction fee
CheckingAccount::CheckingAccount(double initialBalance, double fee)
    : Account(initialBalance), transactionFee(fee) {
}
// Comment 10: This is responsible for adding an amount to the current balance and deducting the transaction fee
void CheckingAccount::credit(double amount) {
    Account::credit(amount);
    if (Account::debit(transactionFee)) {
        std::cout << "$1.00 transaction fee charged." << std::endl;
    }
    else {
        std::cerr << "Transaction fee could not be charged." << std::endl;
    }
}
// Comment 11: This is responsible for withdrawing money from the account and deducting the transaction fee
bool CheckingAccount::debit(double amount) {
    if (Account::debit(amount)) {
        if (Account::debit(transactionFee)) {
            std::cout << "$1.00 transaction fee charged." << std::endl;
            return true;
        }
        else {
            std::cerr << "Transaction fee could not be charged." << std::endl;
            Account::credit(amount);
            return false;
        }
    }
    else {
        return false;
    }
}