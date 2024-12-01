#ifndef BANK_ACCOUNT_H
#define BANK_ACCOUNT_H

#include <string>
#include <vector>
#include "Investment.h"

class BankAccount
{
private:
    std::string owner;
    double balance;
    std::vector<Investment> investments;

public:
    BankAccount(const std::string &owner);

    void deposit(double amount);
    void withdraw(double amount);
    void invest(double amount, int duration, int risk);
    void advanceTime(int months);
    double getBalance() const;
    void checkStatus() const;
};

#endif
