#include "Wallet.h"

Wallet::Wallet() : cash(100.0) {}

void Wallet::addCash(double amount)
{
    if (amount > 0)
    {
        cash += amount;
    }
}

void Wallet::spend(double amount)
{
    if (amount <= cash)
    {
        cash -= amount;
    }
}

double Wallet::getCash() const
{
    return cash;
}

void Wallet::addMonthlyIncome()
{
    cash += 100.0;
}
