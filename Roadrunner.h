/*!
\file Roadrunner.h


\brief File that holds the declaration and definitions for the Roadrunner class.

derived from the base class for Project 4.
This class will contain all of the members needed for the BabyRoadrunner.
All BabyRoadrunners must be created by teh Egg class.
derived from the base class for Project 4.
This class will contain all of the members needed for the Roadrunner.
All Roadrunners must be created by the BabyRoadrunner class.
*/
#ifndef Roadrunner_H
#define Roadrunner_H
#include "DigiPet.h"
#include "Personality.h"
#include <iostream>
#include <string>

using namespace std;
class Roadrunner : public DigiPet {
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

	//Friend since BabyRoadrunner constructor is private
	friend class BabyRoadrunner;

	/*! The default constructor for a BabyRoadrunner. The temperament value is set to the middle of the range.*/
	Roadrunner(size_t happiness, size_t health, size_t cleanliness, size_t age) {
		modify_happiness(happiness);
		modify_health(health);
		modify_cleanliness(cleanliness);
		while (age != get_age()) {
			grow_older();
		}
	};
	void continue_adulthood() {
		grow_older();
	}
public:
	
	//Friend since BabyRoadrunner constructor is private
	friend class BabyRoadrunner;


	void advance_day() {	
			if (get_careerBool() == false) {
				switch (return_Personality()) {
					
					case 'F':
						cout << "Your pet becomes a professional runner, through hard work and determination!" << endl;
						cout << "You should be proud!" << endl;
						break;
					case 'R':
						cout << "Your pet's creative ideas made it into book form, becoming an author!" << endl;
						cout << "You should be proud!" << endl;
						break;
					case 'L':
						cout << "Your pet awakens their mind's eye and becomes an artist!" << endl;
						cout << "You should be proud!" << endl;
						break;
					case 'N':
						cout << "Your pet becomes a doctor through way too much school and hard work!" << endl;
						cout << "You should be proud!" << endl;
						break;
					case 'E':
						cout << "Your pet turns their love for food into a career! Becoming a chef!" << endl;
						cout << "You should be proud!" << endl;
						break;
				}
				set_careerBool(true);
			}
			else {

			}
			DigiPet::advance_Career();
	}
};
#endif