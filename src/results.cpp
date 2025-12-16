#include "global.h"

// sorting results by tries
bool compareResults(const Results& a, const Results& b) {
    return a.tries < b.tries;
}

void Top5() {
    vector<string> levels = { "Latwy", "Sredni", "Trudny" };
    int currentLevel = 0;

    while (true) {
        clearScreen();
        cout << greenTextYellowBG;
        cout << "\n ==================================================== " << endl; 
        cout << " |                  TOP 5 WYNIKOW                   | " << endl;
        if (levels[currentLevel] == "Latwy")
            cout << " |                  POZIOM LATWY                    | " << endl;
        else if (levels[currentLevel] == "Sredni")
            cout << " |                  POZIOM SREDNI                   | " << endl;
        else if (levels[currentLevel] == "Trudny")
            cout << " |                  POZIOM TRUDNY                   | " << endl;
        cout << " ==================================================== " << endl;

        // filter results by current level
        vector<Results> filtered;
        for (auto r : Leaderboard) {
            if (r.level == levels[currentLevel]) {
                filtered.push_back(r);
            }
        }

        if (filtered.empty()) {
            cout << " Brak zapisanych wynikow dla tego poziomu. " << endl;

        } else {
            // sort results
            sort(filtered.begin(), filtered.end(), compareResults);

            cout << " Nr      Imie      Proby      Poziom     Tryb Zakladu " << endl;
            cout << " ---------------------------------------------------- " << endl;
            
            // max 5 results, less if leaderboard has less than 5
            int toShow = filtered.size() > 5 ? 5 : filtered.size();

            for (int i = 0; i < toShow; i++) {
                cout << " " << i + 1 << ".      " 
                    << filtered[i].name << "       "
                    << filtered[i].tries << "       ";
                    if (filtered[i].tries < 10) cout << " ";
                    cout << filtered[i].level << "            ";
                    if (filtered[i].level == "Latwy") cout << " ";
                    cout << (filtered[i].betMode ? "Tak" : "Nie") << "   " << endl;
            }
        }

        cout << " ==================================================== " << endl;
        cout << endColoring;
        cout << boldGreen;
        cout << "\n[A] Poprzedni poziom   [D] Nastepny poziom   [ENTER] Powrot\n";
        cout << endColoring;
        
        // Clear input buffer and read character
        cin.ignore();
        char choice = cin.get();

        if (choice == 'a' || choice == 'A') {
            currentLevel = (currentLevel - 1 + levels.size()) % levels.size();
        }
        else if (choice == 'd' || choice == 'D') {
            currentLevel = (currentLevel + 1) % levels.size();
        }
        else if (choice == '\n') {
            break;
        }
    }
}