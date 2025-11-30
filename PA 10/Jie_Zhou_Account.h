#ifndef Jie_Zhou_ACCOUNT_H
#define Jie_Zhou_ACCOUNT_H

class Account {
public:
    Account(double initialBalance);
    void credit(double amount);
    bool debit(double amount);
    double getBalance() const;

private:
    double balance;
};

#endif#pragma once
