#include "global.h"

// sorting results by tries
bool compareResults(const Results& a, const Results& b) {
    return a.tries < b.tries;
}

void Top5() {
    string input;
    int times = 0;
    while (times<5) {
        clearScreen();
        cout << greenTextYellowBG;
        cout << "\n ==================================================== " << endl;
        if (times % 2 == 0) {
            cout << " |                   TOP 5 WYNIKOW                  | " << endl;
        } else {
            cout << " |                 NAJLEPSZE WYNIKI                 | " << endl;
        }
        cout << " ==================================================== " << endl;

        if (Leaderboard.empty()) {
            cout << " Brak zapisanych wynikow. " << endl;
        } else {
            // sort results
            sort(Leaderboard.begin(), Leaderboard.end(), compareResults);

            cout << " Nr      Imie      Proby      Poziom     Tryb Zakladu " << endl;
            cout << " ---------------------------------------------------- " << endl;
            
            // max 5 results, less if leaderboard has less than 5
            int toShow = Leaderboard.size() > 5 ? 5 : Leaderboard.size();

            for (int i = 0; i < toShow; i++) {
                cout << " " << i + 1 << ".      " 
                    << Leaderboard[i].name << "       " 
                    << Leaderboard[i].tries << "        " 
                    << Leaderboard[i].level << "             "
                    << (Leaderboard[i].betMode ? "Tak" : "Nie") << "   " << endl;
            }
        }
        cout << " ==================================================== " << endl;
        cout << endColoring;
        cout << boldGreen;
        cout << "\nNacisnij ENTER, aby wrocic do menu...";
        cout << endColoring;
        
        times++;
        universalSleep(500);
    }
    cin.ignore();
    cin.get();
}