#include "files.h"

void toFile() {
    ofstream file("wyniki.txt"); // create and write to file
    
    if (!file) {
        cout << "Blad: Nie mozna otworzyc pliku do zapisu!" << endl;    // if unable to open file, show error
        return;
    }
    
    for (const auto& result : Leaderboard) {
        file << result.name << " " << result.tries << " " << result.level << " " << result.betMode << endl;    // write each result to file
    }
    
    file.close();
    cout << "Wyniki zostaly zapisane do pliku wyniki.txt" << endl;
}

void fromFile() {
    ifstream file("wyniki.txt");    // open and read file
    
    if (!file) {
        cout << "Plik wyniki.txt nie istnieje. Brak poprzednich zapisów" << endl;   // show message if file doesn't exist
        return;
    }
    
    Leaderboard.clear();
    
    string name;
    int tries;
    string level;
    bool betMode;
    
    while (file >> name >> tries >> level >> betMode) {   // read each result from file
        Results result;
        result.name = name;
        result.tries = tries;
        result.level = level;
        result.betMode = betMode;
        Leaderboard.push_back(result);
    }
    
    file.close();
    cout << "Wczytano " << Leaderboard.size() << " wynikow z pliku." << endl;
}