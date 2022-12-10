#include <iostream>
#include <cstdlib>

#ifndef DEFINITIONS
#define DEFINITIONS

#define MAPROWS 20
#define MAPCOLS 20
#define MAXHP 100

#define VAMPIRE 1
#define WEREWOLF 2
#define AVATAR 3

using namespace std;

const int NumRows = MAPROWS;
const int NumCols = MAPCOLS;

int generateRandom(int min, int max) {
	return rand() % (max - min + 1) + min;
}

int generateCharacters() {
	int max = (NumRows * NumCols) / 15;
	int min = 1; // We need at least one of each
	return rand() % (max - min + 1) + min;
}

void clearScreen() {
	system("cls");
}

void printMap(char grid[NumRows][NumCols]) {
    for (int r = 0; r < NumRows; ++r) {
    	for (int c = 0; c < NumCols; ++c)
            cout << grid[r][c] << ' ';
        cout << endl;
    }
   cout << endl;
}

void menu(){
	cout << "****** Keybinds ******\n" << endl;
	cout << "Movement: W A S D" << endl;
	cout << "Pause: P" << endl;
	cout << "Quit: Q" << endl;
	cout << "\n***** Legend *****\n" << endl;
	cout << "A => Avatar" << endl;
	cout << "W => Werewolf" << endl;
	cout << "V => Vampire" << endl;
	cout << "| => Tree" << endl;
	cout << "~ => River" << endl;
	cout << ". => Earth" << endl;
	cout << "o => Magic Potion" << endl;
	cout << endl;
	system("pause");
}

void pause() {
	cout << "****** Paused Game ******\n" << endl;
	system("pause");
}

string decodeClass(int className) {
	if (className == VAMPIRE)
		return "Vampire";

	if (className == WEREWOLF)
		return "Werewolf";
}

void printClassChoice() {
	cout << "\n* Select your class:" << endl;
	cout << "1. Vampire" << endl;
	cout << "2. Werewolf\n" << endl;
}

#endif
