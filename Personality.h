/*!
\file Personality.h


\brief File that holds declaration and definitions for the Personality class.

This class will hold all the specifications for a random personality that is determined in the DigiPet parent class.*/
#ifndef Personality_H
#define Personality_H

#include <cstdlib>
#include <iostream>

using namespace std;
class Personality {
private:
	/*! An array to hold names to be used in career activities. Used to give the game more life.*/
	string nameArray[10] = { "Tim the Rhino","Bill the Dinosaur","George the Monkey","Allen the Rat","Ledasha the Cheeta","Abcde the Giraffe","Evan the Turtle","Essence the Sheep","Chipoy the bird", "Sans the Alligator" };

	/*! A boolean value that is set to true once the pet has 10 proficiency and is an adult roadrunner. Made so that I do not need
	to check the proficiency and age everytime when using the advance_Career function.*/
	bool hasCareer;

	/*! Range: [0,4] */
	size_t determinant;

	/*! Values must be F, R, L, N, E. F = Fiesty and means they prefer(get more happiness) playing and hate(looses happiness) bathing.
	R = Reserved and hates playing with prefers reading. L = Lazy and prefers napping while hates reading. N = Neat and prefers bathing and hates eating.
	E = Energetic and hates napping while prefers to eat.*/
	char personality;

	/*! Range: [0,10]
	A member that increase if a pet performs their preffered task. If the number reaches a threshold of 10 and they can develop a career. Note that if
	a pet performs their hated activity, their profeciency does not decrease.*/
	size_t profeciency;

	/*! Sets the value of personality to a different char depending on the random determined int. F = Fiesty, R = Reserved, L = Lazy, N = Neat, E = Energetic.*/
	void personalityCreator(int determinant) {
		switch (determinant) {
		case 0:
			personality = 'F';
			break;
		case 1:
			personality = 'R';
			break;
		case 2:
			personality = 'L';
			break;
		case 3:
			personality = 'N';
			break;
		case 4:
			personality = 'E';
			break;
		default:
			cout << "Error!" << endl;

		}
	}


public:

	/*! Getter for the nameArray attribute at d.*/
	string get_nameArrayAt(size_t d) {
		if (d > 9) {
			d = 9;
			return nameArray[d];
		}
		else {
			return nameArray[d];
		}
	}
	/*! Getter for the bool hasCareer member.*/
	bool get_check() {
		return hasCareer;
	}
	/*! Getter for the determinant member*/
	size_t get_determinant() {
		return determinant;
	}
	/*! Setter for the bool hasCareer member.*/
	void set_check(bool a) {
		hasCareer = a;
	}
	/*! Default Constructor to intialize member determinant, which determines which personality the pet gets, between 0 and 4*/
	Personality(){
		srand(3); // 774 = Reserved; 773 = Lazy; 772 = Energetic; 777 = Fiesty; 3 = Neat
		determinant = rand() % 5;
		personalityCreator(determinant);
		profeciency = 0;
		hasCareer = false;
	}

	/*! Getter for the personality member*/
	char get_Personality() {
		return personality;
	}


	/*!Getter for the proficiecy member.*/
	size_t get_Proficiency() {
		return profeciency;
	}

	void more_Proficient() {
		profeciency = profeciency + 1;
	}
};
#endif
