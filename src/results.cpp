#include "global.h"

// sorting results by tries
bool compareResults(const Results& a, const Results& b) {
    return a.tries < b.tries;
}

void Top5() {
    cout << "\n====================================================" << endl;
    cout << "==            TOP 5 NAJLEPSZYCH WYNIKOW           ==" << endl;
    cout << "====================================================" << endl;

    if (Leaderboard.empty()) {
        cout << "Brak zapisanych wynikow." << endl;
    } else {
        // sort results
        sort(Leaderboard.begin(), Leaderboard.end(), compareResults);

        cout << "Nr\tImie\t\tProby\tPoziom\tTryb Zakladu" << endl;
        cout << "----------------------------------------------------" << endl;
        
        // max 5 results, less if leaderboard has less than 5
        int toShow = Leaderboard.size() > 5 ? 5 : Leaderboard.size();

        for (int i = 0; i < toShow; i++) {
            cout << i + 1 << ".\t" 
                 << Leaderboard[i].name << "\t\t  " 
                 << Leaderboard[i].tries << "\t" 
                 << Leaderboard[i].level << "\t   "
                 << (Leaderboard[i].betMode ? "Tak" : "Nie") << endl;
        }
    }
    cout << "\nNacisnij ENTER, aby wrocic do menu...";
    cin.ignore();
    cin.get();
}