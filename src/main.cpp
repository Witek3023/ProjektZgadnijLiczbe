#include "global.h"

int main() {
    // init random
    srand(time(NULL));
    // read on start
    fromFile();
    // display menu to start
    void menu();
    // save results on exit
    toFile();
    return 0;
}