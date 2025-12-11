#include "files.h"

// clear screen function dependent on OS
void clearScreen() {
    #ifdef _WIN32
        std::system("cls");     // Windows command
    #elif __linux__ || __APPLE__
        std::system("clear");   // Linux && MacOS command
    #else
        std::cout << std::string(100, '\n');    // 100 new lines as fallback
    #endif
}

// sleep function in miliseconds dependent on OS
void universalSleep(int seconds) {
    #ifdef _WIN32
        Sleep(seconds); // Windows Sleep in milliseconds
    #elif __linux__ || __APPLE__
        usleep(seconds*1000);   // Linux and MacOS sleep in seconds
    #endif
}