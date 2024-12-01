#ifndef WALLET_H
#define WALLET_H

class Wallet
{
private:
    double cash;

public:
    Wallet();

    void addCash(double amount);

    void spend(double amount);

    double getCash() const;

    void addMonthlyIncome();
};

#endif
