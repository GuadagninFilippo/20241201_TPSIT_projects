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

    // calcolo del guadagno/perdita basato su rischio e durata
    if (risk == 1) // basso
    {
        if (rand() % 2 == 0)
        {
            gainLoss = duration * (0.015 * amount);
        }
        else
        {
            gainLoss = duration * (-0.01 * amount);
        }
    }

    if (risk == 2) // medio
    {
        if (rand() % 2 == 0)
        {
            gainLoss = duration * (0.025 * amount);
        }
        else
        {
            gainLoss = duration * (-0.025 * amount);
        }
    }

    if (risk == 3) // alto
    {
        if (rand() % 2 == 0)
        {
            gainLoss = duration * (0.1 * amount);
        }
        else
        {
            gainLoss = duration * (-0.1 * amount);
        }
    }

    if (risk != 1 && risk != 2 && risk != 3)
    {
        cout << "Errore: Livello di rischio non valido." << endl;
        balance += amount; // ripristina il saldo originale
        return;
    }

    balance = balance + amount + gainLoss;

    cout << "Investimento creato con successo." << endl;
    cout << "Risultato dell'investimento: " << gainLoss << " €. Saldo attuale: " << balance << " €" << endl;
}


void BankAccount::advanceTime(int months)
{
    // Avanzamento del tempo e calcolo del ritorno sugli investimenti maturati
    for (int i{0}; i < static_cast<int>(investments.size()); i++)
    {
        investments[i].advanceTime(months);
        if (investments[i].isMatured())
        {
            balance += investments[i].getReturn();
        }
    }

    // tolgo investimenti maturati
    for (int i{0}; i < static_cast<int>(investments.size());)
    {
        if (investments[i].isMatured())
        {
            investments.erase(investments.begin() + i); 
        }
        else
        {
            i++; // continua solo se l'elemento non viene rimosso
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
