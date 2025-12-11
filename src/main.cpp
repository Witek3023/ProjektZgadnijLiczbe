#include "global.h"

int main() {
    // init random
    srand(time(NULL));
    // read on start
    fromFile();
    
    string menu;

    do {
        clearScreen();
        cout << greenTextYellowBG;
        cout << " ######################################## " << endl;
        cout << " #         GRA ZGADNIJ LICZBE           # " << endl;
        cout << " ######################################## " << endl;
        cout << " #                                      # " << endl;
        cout << " #       [1] Rozpocznij nowa gre        # " << endl;
        
        // top 5 only when results available
        if (!Leaderboard.empty()) {
            cout << " #          [2] Sprawdz TOP 5           # " << endl;
        }
        cout << " #             [0] Wyjscie              # " << endl;
        cout << " #                                      # " << endl;
        cout << " ######################################## " << endl;
        cout << endColoring;
        cout << boldGreen;
        cout << "Twoj wybor: ";
        cin >> menu;
        cout << endColoring;

        try {
            switch (stoi(menu)) {
                case 1:
                    startGame();
                    break;
                case 2:
                    if(!Leaderboard.empty()) {
                        Top5();
                    }
                    break;
                case 0:
                    cout << "Dzieki za gre!" << endl;
                    break;
                case 3: {
                    easterEgg();
                    break;
                }
                default:
                    cout << "To nie jest prawidlowa opcja. Sprobuj ponownie." << endl;
                    universalSleep(1000);
                    break;
            }
        }
        catch (...) {
            menu = "1";     //force loop continuation
            cout << "To nie jest prawidlowa opcja. Sprobuj ponownie." << endl;
            universalSleep(1000);
        }
    } while (stoi(menu) != 0);

    // save results on exit
    toFile();
    return 0;
}