#include "global.h"

void mainGame(int betTries, bool betMode) {
    bool isBetMode = betMode;
    string whichLevel;
    int maxNum = 0;
    string levelName = "";

    do {
        clearScreen();
        cout << "--- WYBIERZ POZIOM TRUDNOSCI ---" << endl;
        cout << "1. Latwy (1-50)" << endl;
        cout << "2. Sredni (1-100)" << endl;
        cout << "3. Trudny (1-250)" << endl;
        cout << "Wybor: ";
        cin >> whichLevel;

        try {
            // setting range depending on user choice
            switch (stoi(whichLevel)) {
                case 1:
                    maxNum = 50;
                    levelName = "Latwy";
                    break;
                case 2:
                    maxNum = 100;
                    levelName = "Sredni";
                    break;
                case 3:
                    maxNum = 250;
                    levelName = "Trudny";
                    break;
                default:
                    cout << "Nieprawidłowa wartość. Sprobuj ponownie." << endl;
                    universalSleep(1000);
                    break;
            }
        }
        catch (...) {
            cout << "To nie jest prawidlowa opcja. Sprobuj ponownie." << endl;
            universalSleep(1000);
        }
    } while (maxNum == 0);
  

    // choosing random number
    int randomNum = rand() % maxNum + 1;
    string guess;
    int triesCounter = 0;
    bool guessed = false;

    clearScreen();
    cout << "\nZaczynamy! Zgadnij liczbe z zakresu 1-" << maxNum << "." << endl;

    // game loop
    while (!guessed) {
        triesCounter++;
        cout << "Proba nr " << triesCounter << ": Podaj liczbe: ";
        cin >> guess;

        try {
            if (betMode && triesCounter > betTries) {
                cout << "Nie zgadles w wyznaczonej liczbie prob!" << endl;
                cout << "Twój wynik nie zostanie zapisany." << endl;
                universalSleep(1000);
                return;
            }

            if (stoi(guess) == randomNum) {
                guessed = true;
                cout << "\nGRATULACJE! Zgadles liczbe!" << endl;

                string playerName;
                cout << "Podaj swoje imie (5znaków): ";
                cin >> playerName;

                Results newResult;
                newResult.name = playerName.substr(0, 5);   //limit username to 5 characters
                newResult.tries = triesCounter;
                newResult.level = levelName;
                newResult.betMode = isBetMode;
                Leaderboard.push_back(newResult);

                cout << "Wynik zapisany! Wracamy do menu glownego..." << endl;
                toFile(); // Zapisz wynik do pliku
            }
            else if (stoi(guess) < 1 || stoi(guess) > maxNum) {
                cout << "Liczba poza zakresem! Sprobuj ponownie." << endl;
            } 
            else if (stoi(guess) == randomNum + 1 || stoi(guess) == randomNum - 1) {
                cout << "Już blisko!" << endl;
            }
            else if (stoi(guess) < randomNum) {
                cout << tooLittle[rand() % tooLittle.size()] << endl;
            } 
            else {
                cout << tooMuch[rand() % tooMuch.size()] << endl;
            }
        }
        catch(...) {
            cout << "To nie liczba! Sprobuj ponownie." << endl;
        }
        if (betMode) {
            cout << "Pozostalo prob: " << (betTries - triesCounter) << endl;
        }
    }
}

void betGame() {
    string maxTries = "";
    do {
        clearScreen();
        cout << "--- TRYB ZAKLADU ---" << endl;
        cout << "Podaj maksymalna liczbe prob, ktora mozesz wykorzystac: ";
        cin >> maxTries;
        try {
            stoi(maxTries);
        }
        catch (...) {
            maxTries = "-1";
        }
        if (stoi(maxTries) <= 0) {
            cout << "To nie jest prawidlowa liczba. Sprobuj ponownie." << endl;
            universalSleep(1000);
        }
    } while (stoi(maxTries) <= 0);

    cout << "Masz " << maxTries << " prob na zgadniecie liczby." << endl;
    cout << "Rozpoczynamy gre!" << endl;
    universalSleep(1000);
    mainGame(stoi(maxTries), true);
}

void startGame() {
    char menu;
    
    do {
        clearScreen();
        cout << "Czy chcesz rozpocząć grę w trybie zakładu? (t/n): ";
        cin >> menu;
        switch (tolower(menu)) {
        case 't':
            betGame();
            break;
        case 'n':
            mainGame();
            break;
        default:
            cout << "Niepoprawny wybór" << endl;
            break;
        }
    } while (tolower(menu) != 't' && tolower(menu) != 'n');
}