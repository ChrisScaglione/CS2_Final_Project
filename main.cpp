/**
 * @file bfine_project_4.cpp
 *
 * @brief This file contains the main function for F18 CMPS 148 P4
 *
 **/

#include <iostream>
#include <cstdlib>
#include "DigiPet.h"
#include "Egg.h"
#include "BabyRoadrunner.h"
#include "Personality.h"

using namespace std;

int main()
{
	bool isEgg = true;
	DigiPet* pet = new Egg;
	DigiPet* t = NULL;
	for (size_t i = 0; i < 40; i++) { //Increased amount of loops to 40
		cout << "Day " << (i + 1) << endl;
		cout << endl;
		pet->advance_day();

		if (pet->get_life_stage() == 1 && isEgg == true) {
			t = dynamic_cast<BabyRoadrunner*>(dynamic_cast<Egg*>(pet)->get_hatchling());
			delete pet;
			pet = t;
			t = NULL;

			isEgg = false;
		}
		else if (pet->get_life_stage() == 1 && isEgg == false) {

			t = dynamic_cast<Roadrunner*>(dynamic_cast<BabyRoadrunner*>(pet)->get_adult());

			delete pet;
			pet = t;
			t = NULL;
		}
	}
	cout << "Your pet is all grown up now. And it's time for them to venture out on their and learn things from the world." << endl;
	cout << "They will always love and depend on you, but for now it is goodbye. At least they'll be sure to visit!" << endl;
	cout << endl;

	cout << "Press the enter key to exit..." << endl;
	cin.get();

	return 0;
}
