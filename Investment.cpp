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
    { // basso
        if (rand() % 100 < 90)
        {
            multiplier = 1.15;
        }
        else
        {
            multiplier = 0.90;
        }
    }

    if (risk == 2)
    { // medio
        if (rand() % 100 < 70)
        {
            multiplier = 1.25;
        }
        else
        {
            multiplier = 0.75;
        }
    }

    if (risk == 3)
    { // alto
        if (rand() % 2 == 0)
        {
            multiplier = 2.0;
        }
        else
        {
            multiplier = 0.5;
        }
    }

    if (risk != 1 && risk != 2 && risk != 3)
    {
        cout << "Livello di rischio non valido!" << endl;
    }

    return amount * multiplier;
}

