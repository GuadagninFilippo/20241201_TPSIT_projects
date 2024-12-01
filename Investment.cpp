#include "Investment.h"
#include <cstdlib>
#include <iostream>
using namespace std;

Investment::Investment(double amount, int duration, int risk)
    : amount(amount), duration(duration), elapsedMonths(0), risk(risk) {}

void Investment::advanceTime(int months)
{
    elapsedMonths += months;
}

bool Investment::isMatured() const
{
    return elapsedMonths >= duration;
}

double Investment::getReturn() const
{
    double multiplier{1.0};

    if (risk == 1)
    { // Rischio basso
        multiplier = (rand() % 100 < 90) ? 1.15 : 0.90;
    }
    else if (risk == 2)
    { // Rischio medio
        multiplier = (rand() % 100 < 70) ? 1.25 : 0.75;
    }
    else if (risk == 3)
    { // Rischio alto
        multiplier = (rand() % 2 == 0) ? 2.0 : 0.5;
    }
    else
    {
        cout << "Livello di rischio non valido!" << endl;
    }

    return amount * multiplier;
}
