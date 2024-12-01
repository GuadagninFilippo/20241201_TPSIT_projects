#ifndef USER_H
#define USER_H

#include <string>
#include "BankAccount.h"
#include "Wallet.h"

class User
{
private:
    std::string name;
    BankAccount account;
    Wallet wallet;

public:
    User(const std::string &name);

    void depositToAccount(double amount);
    void withdrawFromAccount(double amount);
    void investInAccount(double amount, int duration, int risk);
    void addMonthlyIncome();
    void advanceTime(int months);
    void checkStatus() const;

    std::string getName() const;
};

#endif
