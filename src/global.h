#include <iostream>
#include <string>
#include <vector>
#include <cstdlib> // rand() && srand() && system()
#include <ctime>   // time()
#include <algorithm> // sort()
#include <fstream>  // file operations
#include <cctype> // tolower()
#ifdef _WIN32
    #include <windows.h>    // sleep for windows
#elif __linux__ || __APPLE__
    #include <unistd.h>   // sleep for linux and macos
#endif
#ifndef GLOBAL_H
#define GLOBAL_H

using namespace std;

// global results record
struct Results {
	string name;
	int tries;
	string level;
	bool betMode;
};

//declatarion of global variables;
extern vector<Results> Leaderboard;
extern vector<string> tooMuch;
extern vector<string> tooLittle;
extern string endColoring;
extern string boldGreen;
extern string greenTextYellowBG;

bool compareResults(const Results& a, const Results& b);

// utilities
void clearScreen();
void universalSleep(int milliseconds);

// storage
void toFile();
void fromFile();
void Top5();

// game
void menu();
void mainGame(int betTries = 0, bool betMode = false);
void betGame();
void startGame();
void easterEgg();

#endif // GLOBAL_H