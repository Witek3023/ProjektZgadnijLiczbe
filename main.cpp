#include <iostream>
#include <string>
#include <vector>
#include <cstdlib> // rand() && srand() && system()
#include <ctime>   // time()
#include <algorithm> // sort()
#include <fstream>  // file operations

using namespace std;

// structure for results
struct Results {
    string name;
    int tries;
    string level;
};

// global results vector
vector<Results> Leaderboard;

vector<string> tooMuch = {
    "Za duzo!",
    "Nie no tyle to nie!",
    "Trochę za dużo!",
    "Sprobuj mniejsza liczbe!",
    "Twoja liczba jest za wysoka!",
    "Liczba jest zbyt duza!"};

vector<string> tooLittle = {
    "Za malo!",
    "Sprobuj wieksza liczbe!",
    "Twoja liczba jest za niska!",
    "Liczba jest zbyt mala!"};

// simple clear screen function dependent on OS
void clearScreen() {
    #ifdef _WIN32
        std::system("cls");     // Windows command
    #elif __linux__ || __APPLE__
        std::system("clear");   // Linux && MacOS command
    #else
        std::cout << std::string(100, '\n');    // 100 new lines as fallback
    #endif
}


bool compareResults(const Results& a, const Results& b) {
    return a.tries < b.tries;
}

void toFile() {
    ofstream file("wyniki.txt"); // create and write to file
    
    if (!file) {
        cout << "Blad: Nie mozna otworzyc pliku do zapisu!" << endl;    // if unable to open file, show error
        return;
    }
    
    for (const auto& result : Leaderboard) {
        file << result.name << " " << result.tries << " " << result.level << endl;    // write each result to file
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
    
    while (file >> name >> tries >> level) {   // read each result from file
        Results result;
        result.name = name;
        result.tries = tries;
        result.level = level;
        Leaderboard.push_back(result);
    }
    
    file.close();
    cout << "Wczytano " << Leaderboard.size() << " wynikow z pliku." << endl;
}

// Funkcja wyświetlająca TOP 5
void Top5() {
    cout << "\n========================================" << endl;
    cout << "==        TOP 5 NAJLEPSZYCH WYNIKOW   ==" << endl;
    cout << "========================================" << endl;

    if (Leaderboard.empty()) {
        cout << "Brak zapisanych wynikow." << endl;
    } else {
        // sort results
        sort(Leaderboard.begin(), Leaderboard.end(), compareResults);

        cout << "Nr\tImie\t\tProby\tPoziom" << endl;
        cout << "----------------------------------------" << endl;
        
        // Wyświetlamy max 5 wyników lub mniej, jeśli lista jest krótsza
        int toShow = Leaderboard.size() > 5 ? 5 : Leaderboard.size();

        for (int i = 0; i < toShow; i++) {
            cout << i + 1 << ".\t" 
                 << Leaderboard[i].name << "\t\t" 
                 << Leaderboard[i].tries << "\t" 
                 << Leaderboard[i].level << endl;
        }
    }
    cout << "\nNacisnij ENTER, aby wrocic do menu...";
    cin.ignore();
    cin.get();
}

void startGame() {
    int whichLevel;
    int maxNum = 0;
    string levelName = "";

    cout << "\n--- WYBIERZ POZIOM TRUDNOSCI ---" << endl;
    cout << "1. Latwy (1-50)" << endl;
    cout << "2. Sredni (1-100)" << endl;
    cout << "3. Trudny (1-250)" << endl;
    cout << "Wybor: ";
    cin >> whichLevel;

    // Ustawienie zakresu w zależności od wyboru
    switch (whichLevel) {
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
            cout << "Niepraw1idlowy wybor. Ustawiono poziom Latwy (1-50)." << endl;
            maxNum = 50;
            levelName = "Latwy";
            break;
    }

    // Losowanie liczby
    int randomNum = rand() % maxNum + 1;
    string guess;
    int triesCounter = 0;
    bool guessed = false;

    cout << "\nZaczynamy! Zgadnij liczbe z zakresu 1-" << maxNum << "." << endl;

    // Pętla rozgrywki
    while (!guessed) {
        triesCounter++;
        cout << "Proba nr " << triesCounter << ": Podaj liczbe: ";
        cin >> guess;

        try {
            if (stoi(guess) == randomNum) {
                guessed = true;
                cout << "\nGRATULACJE! Zgadles liczbe!" << endl;
                
                // Pobranie imienia i zapisanie wyniku
                string playerName;
                cout << "Podaj swoje imie: ";
                cin >> playerName;

                Results newResult;
                newResult.name = playerName;
                newResult.tries = triesCounter;
                newResult.level = levelName;
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
    }
}

int main() {
    // init random
    srand(time(NULL));
    // read on start
    fromFile();
    
    int menu;

    do {
        clearScreen();
        cout << "########################################" << endl;
        cout << "#         GRA ZGADNIJ LICZBE           #" << endl;
        cout << "########################################" << endl;
        cout << "1. Rozpocznij nowa gre" << endl;
        
        // Opcja TOP 5 widoczna tylko gdy są wyniki
        if (!Leaderboard.empty()) {
            cout << "2. Sprawdz TOP 5" << endl;
        }
        cout << "0. Wyjscie" << endl;
        cout << "Twoj wybor: ";
        cin >> menu;

        switch (menu)
        {
        case 1:
            startGame();
            break;
        case 2:
            Top5();
            break;
        case 0:
            cout << "Dzieki za gre!" << endl;
            break;

        default:
            cout << "Nieprawidlowa opcja." << endl;
            break;
        }
    } while (menu != 0);

    // save results on exit
    toFile();
    return 0;
}