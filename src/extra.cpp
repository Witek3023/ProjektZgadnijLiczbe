#include "global.h"

void easterEgg() {
    for (int i = 0; i < 10; i++) {
        clearScreen();
        cout << "Przygotuj sie na niespodzianke za " << 10 - i << " sekund..." << endl;
        universalSleep(1000);
    }
    int count = 0;
    clearScreen();
    while (count <= 10) {
        cout << R"(
     .--.         /``'.
    /wwww\ .---. |* *  \
    |-=-=|/ ^ ^ `;--. *|
    \wwww/\^ ^ ^/~~~~\.'       __
     '--'  '----|    |       .'-=\
          .'``\ \~~~~/ .-""-:=-=-=|
         /   * | '--' /><><><\=-=/
         |*   /   .-""-.<><></--'
          '--'   /~*~*~*\---'
                 \*~*~*~/
                  '----'
        )";
        universalSleep(400);
        clearScreen();
        cout << "\tEaster Egg!\n";
        universalSleep(400);
        clearScreen();
        count++;
    }
}