#include <iostream>
#include "User.h"
using namespace std;

void showMenu();

int main()
{
    User user("Mario Rossi");

    bool run{true};

    while (run)
    {
        showMenu();
        
        int scelta{0};
        cin >> scelta;

        switch (scelta)
        {
        case 1:
        {
            user.addMonthlyIncome();
            cout << "Entrate mensili aggiunte" << endl;
            break;
        }
        case 2:
        {
            double amount{0.0};
            cout << "Inserisci l'importo da depositare: ";
            cin >> amount;
            user.depositToAccount(amount);
            break;
        }
        case 3:
        {
            double amount{0.0};
            cout << "Inserisci l'importo da prelevare: ";
            cin >> amount;
            user.withdrawFromAccount(amount);
            break;
        }
        case 4:
        {
            double amount{0.0};
            int duration{0};
            int risk{0};

            cout << "Inserisci l'importo da investire: ";
            cin >> amount;

            cout << "Inserisci la durata dell'investimento (in mesi): ";
            cin >> duration;

            cout << "Scegli il livello di rischio:" << endl;
            cout << "1. Basso rischio" << endl;
            cout << "2. Medio rischio" << endl;
            cout << "3. Alto rischio" << endl;
            cin >> risk;

            if (risk < 1 || risk > 3)
            {
                cout << "Scelta non valida. Riprova." << endl;
                continue;
            }

            user.investInAccount(amount, duration, risk);
            break;
        }
        case 5:
        {
            int months{0};
            cout << "Inserisci il numero di mesi da avanzare: ";
            cin >> months;
            user.advanceTime(months);
            break;
        }
        case 6:
        {
            user.checkStatus();
            break;
        }
        case 0:
            run = false;
            cout << "Chiusura del programma. Arrivederci" << endl;
            break;
        default:
            cout << "Opzione non valida. Riprova" << endl;
        }
    }

    return 0;
}

void showMenu()
{
    cout << endl;
    cout << "--- Menu ---" << endl;
    cout << "1. Aggiungere entrate mensilli" << endl;
    cout << "2. Depositare denaro sul conto" << endl;
    cout << "3. Prelevare denaro dal conto" << endl;
    cout << "4. Fare un investimento" << endl;
    cout << "5. Avanzare nel tempo" << endl;
    cout << "6. Mostrare lo stato" << endl;
    cout << "0. Uscire" << endl;
    cout << "Scegli un'opzione: ";
}