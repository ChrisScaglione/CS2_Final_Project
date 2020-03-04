/*!
\file BabyRoadrunner.h


\brief File that holds the declaration and definitions for the BabyRoadrunner class.

derived from the base class for Project 4.
This class will contain all of the members needed for the BabyRoadrunner.
All BabyRoadrunners must be created by teh Egg class.
derived from the base class for Project 4.
This class will contain all of the members needed for the Roadrunner.
All Roadrunners must be created by the BabyRoadrunner class.
*/

#ifndef BabyRoadrunner_H
#define BabyRoadrunner_H
#include "DigiPet.h"
#include "Roadrunner.h"
#include "Personality.h"
#include <iostream>
#include <string>

using namespace std;

class BabyRoadrunner : public DigiPet {
private:

	/*!NEW DESIGN STUFF
	Function to print all of the relevant stats of the BabyRoadrunner.*/
	void status() {
		modify_cleanliness(get_cleanliness() - 1);
		modify_happiness(get_happiness() - 1);
		modify_health(get_health() - 1);
		grow_older();

		cout << "Age: " << get_age() << endl;
		cout << "Health: " << get_health() << endl;
		cout << "Cleanliness: " << get_cleanliness() << endl;
		cout << "Happiness: " << get_happiness() << endl;
		cout << endl;
	}

	/*! Range from 0 to 100.*/
	size_t temperament;

	/*! This is where the Roadrunner should be created.*/
	Roadrunner* adult;


	/*! Default constructor.*/
	BabyRoadrunner(size_t age) {
		temperament = 50;
		modify_cleanliness(50);
		modify_happiness(50);
		while (age != get_age()) {
			grow_older();
		}
	}

	/*! Checks the age and if the baby roadrunner is 10, it turns into a adult roadrunner.*/
	void continue_childhood() {
		if (get_age() >= 10 && return_Proficiency() == 10) {
			BabyRoadrunner::advance_life_stage();
		}
		else {

		}
	}

	/*! Creates a Roadrunner.*/
	void commming_of_age() {
		adult = new Roadrunner(get_happiness(), get_health(), get_cleanliness(), get_age());
	}
protected:

	/*! Turns from BabyRoadrunner to Roadrunner.*/
	void advance_life_stage() {
		DigiPet::advance_life_stage();
		commming_of_age();
	}


public:
	

	friend class Egg;

	/*! Getter for the temperament member.*/
	size_t get_temperament() {
		return temperament;
	}

	Roadrunner* get_adult() {
		return adult;
	}

	/*! This unction first should decrease happiness, health and cleanliness by one. Then it should prompt the user
	if they want to eat, play, or bathe.*/
	void advance_day() {
		if (get_age() == 0) {
			if (return_Personality() == 'F') {
				cout << "Looks like they're Fiesty! They love to play and hate to bathe!" << endl;
				cout << "Maybe doing their preffered activity will do something special..." << endl;
				cout << endl;
			}
			else if (return_Personality() == 'R') {
				cout << "Looks like they're Reserved! The love to read and hate to play!" << endl;
				cout << "Maybe doing their preffered activity will do something special..." << endl;
				cout << endl;
			}
			else if (return_Personality() == 'L') {
				cout << "Looks like they're Lazy! They love to nap and hate to read!" << endl;
				cout << "Maybe doing their preffered activity will do something special..." << endl;
				cout << endl;
			}
			else if (return_Personality() == 'N') {
				cout << "Looks like they're Neat! The love to bathe and hate to eat!" << endl;
				cout << "Maybe doing their preffered activity will do something special..." << endl;
				cout << endl;
			}
			else if (return_Personality() == 'E') {
				cout << "Looks like they're Energetic! The love to eat and hate to nap!" << endl;
				cout << "Maybe doing their preffered activity will do something special..." << endl;
				cout << endl;
			}
		}
		string tempInput;
		//Don't need to check if values are still in range b/c already did in modify functions
		//cin.ignore(); //Only need to invoke once
		//Allowing user options of interaction
		do {
			cout << "Would you like to feed, play with, bathe your pet, let them read, or let them take a nap?" << endl;
			cin >> tempInput;
			//Option for feeding pet
			if (tempInput == "Feed" || tempInput == "feed") {
				eat();
				cout << "You give your baby roadrunner a snack." << endl;
				status();
				continue_childhood();
			}
			//Option for playing with pet
			else if (tempInput == "Play" || tempInput == "play") {
				play();
				cout << "You and your baby roadrunner play together!" << endl;
				status();
				continue_childhood();
			}
			//Option for bathing
			else if (tempInput == "Bathe" || tempInput == "bathe") {
				bathe();
				cout << "You wash your baby roadrunner!" << endl;
				status();
				continue_childhood();
			}
			//Option for reading
			else if (tempInput == "Read" || tempInput == "read") {
				read();
				cout << "Your baby roadrunner reads a book!" << endl;
				status();
				continue_childhood();
			}
			//Option for napping
			else if (tempInput == "Nap" || tempInput == "nap") {
				nap();
				cout << "Your baby roadrunner took a long nap!" << endl;
				status();
				continue_childhood();
			}
			//Option if invalid thing is entered
			else {
				cout << "Invalid choice! Enter your choice again." << endl;
				tempInput = "Invalid input";
				cin.ignore();
			}
		} while (tempInput == "Invalid input");
		}

	friend class Egg;
};
#endif 

