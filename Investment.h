#ifndef INVESTMENT_H
#define INVESTMENT_H

class Investment
{
private:
    double amount;
    int duration;
    int elapsedMonths; // Mesi trascorsi
    int risk;          // Livello di rischio (1 = basso, 2 = medio, 3 = alto)

public:
    Investment(double amount, int duration, int risk);

    void advanceTime(int months);

    bool isMatured() const;

    double getReturn() const;
};

#endif
