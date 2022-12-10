#include <iostream>

// File: definitions.h
#ifndef DEFINITIONS
	#include "definitions.h"
#endif

#ifndef CHARACTER
#define CHARACTER

using namespace std;

class Character {
	int className;
	int health;
	int strength;
	int armor;
	bool avatar;

	public:
		// Constructor
		Character() {
			this->health = MAXHP;
	        this->strength = generateRandom(1, 3);
	        this->armor = generateRandom(1, 2);
	        this->avatar = false;
		}

	  	// Getters
	  	int getClassName() {
	  		return this->className;
		}

	    int getHealth() {
	        return this->health;
	    }
	
	    int getStrength() {
	        return this->strength;
	    }
	
	    int getArmor() {
	        return this->armor;
	    }
	    
	    bool getAvatar() {
	    	return this->avatar;
		}

	    // Setters
	    void setClassName(int className) {
	    	this->className = className;
		}

	    void setHealth(int health) {
	        this->health = health;
	    }
	
	    void setStrength(int strength) {
	        this->strength = strength;
	    }
	
	    void setArmor(int armor) {
	        this->armor = armor;
	    }
	    
	    void setAvatar(bool avatar) {
	    	this->avatar = true;
		}
	    
		void print() {
			cout << "\n****** Stats ******" << endl;
			if (avatar)
				cout << "This is your avatar" << endl;
	        cout << "Class: " << decodeClass(this->className) << endl;
	        cout << "Health: " << this->health << endl;
	        cout << "Strength: " << this->strength << endl;
	        cout << "Armor: " << this->armor << endl;
	        cout << endl;
		}
};

class Werewolf: public Character {
    public:
		// Constructor
	    Werewolf() {
	    	setClassName(WEREWOLF);
		}
};

class Vampire: public Character {
    public:
		// Constructor
	    Vampire() {
	    	setClassName(VAMPIRE);
		}
};

class Avatar: public Character {
    public:
		// Constructor
	    Avatar() {
	    	Character::setClassName(WEREWOLF); // Always set a default
	    	Character::setAvatar(true);
		}
		
		// Setters
		void setClassName(int className) {
			Character::setClassName(className);
		}
};

#endif
