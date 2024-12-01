#ifndef WALLET_H
#define WALLET_H

class Wallet
{
private:
    double money;

public:
    Wallet();

    void addCash(double total);

    void spend(double total);

    double getCash() const;

    void addMonthlyIncome();
};

#endif
