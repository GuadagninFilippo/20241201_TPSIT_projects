#include "BankAccount.h"
#include <iostream>
using namespace std;

BankAccount::BankAccount(const string &owner)
    : owner(owner), balance(0.0) {}

void BankAccount::deposit(double amount)
{
    if (amount <= 0)
    {
        cout << "Errore: Non puoi depositare un importo negativo o nullo" << endl;
        return;
    }
    if (balance < 0)
    {
        double debitoRimanente = min(amount, -balance);
        balance += debitoRimanente;
        amount -= debitoRimanente;

        cout << "Il tuo debito è stato ridotto a " << balance << " €" << endl;
    }
    balance += amount;
    cout << "Deposito completato. Saldo attuale: " << balance << " €" << endl;
}

void BankAccount::withdraw(double amount)
{
    if (amount <= balance)
    {
        balance -= amount;
    }
    else
    {
        cout << "Saldo insufficiente per prelevare " << amount << " €" << endl;
    }
}

void BankAccount::invest(double amount, int duration, int risk)
{
    if (amount > balance)
    {
        cout << "Errore: Saldo insufficiente per investire " << amount << " €" << endl;
        return;
    }

    balance -= amount;
    double gainLoss{0.0};

    // Calcolo del guadagno/perdita basato su rischio e durata
    switch (risk)
    {
    case 1: // basso rischio
        gainLoss = duration * ((rand() % 2 == 0) ? 0.015 * amount : -0.01 * amount);
        break;
    case 2: // medio rischio
        gainLoss = duration * ((rand() % 2 == 0) ? 0.025 * amount : -0.025 * amount);
        break;
    case 3: // alto rischio
        gainLoss = duration * ((rand() % 2 == 0) ? 0.1 * amount : -0.1 * amount);
        break;
    }

    balance = balance + amount + gainLoss;

    cout << "Investimento creato con successo." << endl;
    cout << "Risultato dell'investimento: " << gainLoss << " €. Saldo attuale: " << balance << " €" << endl;
}


void BankAccount::advanceTime(int months)
{
    // avanzamento del tempo e calcolo del ritorno sugli investimenti maturati
    for (size_t i{0}; i < investments.size(); i++)
    {
        investments[i].advanceTime(months);
        if (investments[i].isMatured())
        {
            balance += investments[i].getReturn();
        }
    }

    // rimozione degli investimenti maturati
    for (size_t i{0}; i < investments.size();)
    {
        if (investments[i].isMatured())
        {
            investments.erase(investments.begin() + i); // rimuove l'investimento maturo
        }
        else
        {
            ++i; // avanza solo se l'elemento non viene tolto
        }
    }
}

double BankAccount::getBalance() const
{
    return balance;
}

void BankAccount::checkStatus() const
{
    cout << "Proprietario: " << owner << endl;
    cout << "Saldo: " << balance << " €" << endl;
    cout << "Numero di investimenti: " << investments.size() << endl;
}
