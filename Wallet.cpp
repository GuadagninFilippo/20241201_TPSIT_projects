#include "Wallet.h"

Wallet::Wallet() : money(100.0) {}

void Wallet::addCash(double total)
{
    if (total > 0)
    {
        money += total;
    }
}

void Wallet::spend(double total)
{
    if (total <= money)
    {
        money -= total;
    }
}

double Wallet::getCash() const
{
    return money;
}

void Wallet::addMonthlyIncome()
{
    money += 100.0;
}