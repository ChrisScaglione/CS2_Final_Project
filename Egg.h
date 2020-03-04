/*!
\file Egg.h

Derived from the base class for Project4. This class will contain all of the members needed for the egg. All digipets must start from a egg. All other constructors in this project are either protected or private.

*/

#include "BabyRoadrunner.h"
//#include "DigiPet.h"
#include "Personality.h"
#include <iostream>
#include <cstdlib>

using namespace std;

#ifndef Egg_H
#define Egg_H


class Egg : public DigiPet {
private:

	/*! Range from 0 to 100.*/
	size_t warmth;
	
	/*! This is where the BabyRoadrunner will be created.*/
	BabyRoadrunner* hatchling;

	/*! This function will create the BabyRoadrunner. */
	void hatch() {
		cout << "Your Egg hatched into a Roadrunner! Raise it with care!" << endl;
		hatchling = new BabyRoadrunner(0);

	}
	/*! NEW DESIGN CHOICE
	A function to evaultuate the warmth of the egg and check if it's within 50-70 or not. If it is, increase the health by 10. If it isn't then
	decrease the health by 10. Then the function should check if the health is at 100 or 0. If 100, egg hatches. If 0, egg dies and the program should quit. */
	void continue_incubation() {
		int randEvent = 0;//! A variable to determine what message gets printed given a random value.
		if (warmth >= 50 && warmth <= 70) { //! Checks if the warmth is withing the optimal range. If so, health increases by 10.
			modify_health(get_health() + 10);
			randEvent = rand() % 3; 
			switch (randEvent) {
			case 0:
				cout << "The egg almost looks like it's smiling." << endl;
				break;
			case 1:
				cout << "The egg looks extremely cozy and warm." << endl;
				break;
			default:
				cout << "The egg is radiating contentment." << endl;
			}
		}
		else {
			modify_health(get_health() - 10);
			if (warmth < 50) {
				randEvent = rand() % 4; 
				switch (randEvent) {
				case 0:
					cout << "The egg is shivering!" << endl;
					break;
				case 1:
					cout << "The egg looks cold..." << endl;
					break;
				case 2:
					cout << "The egg looks like it needs a blanket." << endl;
					break;
				default:
					cout << "The egg doesn't look so good." << endl;
					break;
				}
			}
			else {
				randEvent = rand() % 3; 
				switch (randEvent) {
				case 0:
					cout << "The egg is sweating." << endl;
					break;
				case 1:
					cout << "The egg is burning up! It's like it has a fever!" << endl;
					break;
				default:
					cout << "The egg looks too hot." << endl;
					break;
				}
			}
		}	
		if (get_health() == 100) { //! Checks if the egg is ready to hatch.
			cout << "Your egg is hatching!" << endl;
			advance_life_stage();
		}
		else if (get_health() == 0) { //! Checks if the egg is going to die.
			cout << "The egg didn't survive you. Shame on you! Egg protective services have been called." << endl; 
			cout << "GAME OVER!" << endl;
			cin.get();
			cin.get();
			exit (0);
		}
		cout << endl;
	}

	void status() {
		cout << endl;
		cout << "Warmth: " << warmth << endl;
	}
public:

	/*! Constructor. */
	Egg() {
		warmth = 50;
		Egg::hatchling = NULL;

		/*! NEW DESIGN CHOICE
		Using health as a variable set in the middle of the range to decide when the egg should hatch.
		While the egg's warmth is between 50-70, the health will increase by 10.
		While the egg's warmth is not between 50-70, the health will decrease by 10.
		At 100 warmth the egg hatches. At 0 warmth the egg dies.*/
		modify_health(50);
	}

	/*! Function should check if the user wants to cool or warm the egg. The function should call the continue_incubation.*/
	void advance_day() {
		char pick;
		do {
			std::cout << "Would you like to cool or warm the egg? C/W" << std::endl;
			cin >> pick;
			if (pick == 'C' || pick == 'c') {
				cool_egg();
				cout << "You cool the egg!" << endl;
			}
			else if (pick == 'W' || pick == 'w') {
				warm_egg();
				cout << "You warm the egg!" << endl;
			}
			else {
				cout << "Invalid choice. Please enter C or W." << endl;
				pick = 'I';
			}
		} while (pick == 'I');
		status();
		continue_incubation();
	}

	
	void warm_egg() {
		warmth = warmth + 10;

		//Assuring the value stay within range.
		if (warmth > 100) {
			warmth = 100;
		}
	}

	void cool_egg() {
		warmth = warmth - 10;

		//Assuring the value stays within the range.
		if (warmth > 100 || warmth < 0) {
			warmth = 0;
		}
	}

	/*! Getter for the warmth member.*/
	size_t get_warmth() {
		return warmth;
	}

	BabyRoadrunner* get_hatchling() {
		return hatchling;
	}





protected:
	/*! Function to call the advance life stage func from DigiPet and the hatch func.*/
	void advance_life_stage() {
		DigiPet::advance_life_stage();
		this->hatch();
	}
};
#endif