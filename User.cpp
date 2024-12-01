#include "User.h"
#include <iostream>
using namespace std;

User::User(const string &name) : name(name), account(name), wallet() {}

void User::depositToAccount(double amount)
{
    if (wallet.getCash() >= amount)
    {
        wallet.spend(amount);
        account.deposit(amount);
    }
    else
    {
        cout << "Non hai abbastanza denaro nel portafoglio" << endl;
    }
}

void User::withdrawFromAccount(double amount)
{
    if (amount <= account.getBalance())
    {
        account.withdraw(amount);
        wallet.addCash(amount);
    }
    else
    {
        cout << "Non puoi prelevare più del saldo disponibile" << endl;
    }
}

void User::investInAccount(double amount, int duration, int risk)
{
    if (risk < 1 || risk > 3)
    {
        cout << "Rischio non valido. Deve essere 1 (basso), 2 (medio) o 3 (alto)." << endl;
        return;
    }

    account.invest(amount, duration, risk);
}

void User::addMonthlyIncome()
{
    wallet.addMonthlyIncome();
}

void User::advanceTime(int months)
{
    account.advanceTime(months);
    wallet.addMonthlyIncome();
}

void User::checkStatus() const
{
    cout << endl;
    cout << "--- Stato di " << name << " ---" << endl;
    cout << "Portafoglio: " << wallet.getCash() << " €" << endl;
    account.checkStatus();
}