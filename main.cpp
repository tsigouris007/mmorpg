#include <iostream>
#include <algorithm>
#include <conio.h>
#include <ctime>
#include <cstdlib>

// File: definitions.h
#ifndef DEFINITIONS_H
	#include "definitions.h"
#endif

// File: character.h
#ifndef CHARACTER_H
	#include "character.h"
#endif

using namespace std;

int main() {
	// Initialize for srand
	std::srand(std::time(NULL));

	int choice, i;
	
	// Initialize player class
	while(true) {
		printClassChoice();
		cin >> choice;
		if (choice == WEREWOLF || choice == VAMPIRE)
			break;
	}
	
	cout << "* Generating world..." << endl;
	cout << "* Generating your avatar..." << endl;
	
	Avatar avatar;
	avatar.setClassName(choice);
	
	cout << "* Generating opponents..." << endl;

	int numCharacters = generateCharacters();
	
	Vampire *vampires = new Vampire[numCharacters];
	Werewolf *werewolves = new Werewolf[numCharacters];
	for (i = 0; i < numCharacters; i++) {
		Vampire v;
		Werewolf w;

		vampires[i] = v;
		werewolves[i] = w;
	}

	cout << "* Generated " << numCharacters << " opponents." << endl;
	cout << "* Generating map." << endl;
	
	// Create and fill in the map
	// Grid inspired from https://cplusplus.com/forum/beginner/255648/#msg1120230
    char grid[NumRows][NumCols];
    fill((char*)grid, (char*)grid + NumRows * NumCols, '.');

	// Create a random position to start our character
    int row = generateRandom(0, NumRows);
	int col = generateRandom(0, NumCols);
    
    grid[row][col] = 'A';

	char input = 'x'; // Any invalid char will do
	
	system("pause"); // Pause for the dramatic effect before launching the game
    for (bool looping = true; looping; ) {
    	// Clear the screen
    	clearScreen();
    	
		// Print current map
        printMap(grid);

        int newcol = col, newrow = row;
        bool goodchar = true;
        
        input = _getch();
        // Get player choice
        switch (input) {
	        case 'a': case 'A': --newcol; break;
	        case 'd': case 'D': ++newcol; break;
	        case 's': case 'S': ++newrow; break;
	        case 'w': case 'W': --newrow; break;
	        case 'q': case 'Q': looping = false; break;
	        case 'p': case 'P': pause(); break;
	        case 'm': case 'M': avatar.print(); menu(); break;
	        default: goodchar = false;
        }

        if (goodchar && looping) {
        	// Issue boundaries
        	if (newcol >= NumCols || newcol <= -1)
				continue;
			if (newrow >= NumRows || newrow <= -1)
				continue;
			
			// Calculate next position
            // https://en.cppreference.com/w/cpp/algorithm/swap
            swap(grid[newrow][newcol], grid[row][col]);
            
            // Add new position to row / col
            row = newrow;
            col = newcol;
        }
    }
}
