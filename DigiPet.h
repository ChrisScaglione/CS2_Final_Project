/*!
\file DigiPet.h

the base class for Project 4. This class will contain all of the members needed for the general digital pet.
However, an instance of a DigiPet cannot be created on its own. You can only create a DigiPet via Egg,
BabyRoadrunner, or Roadrunner.
*/

#ifndef DigiPet_H
#define DigiPet_H
#include <iostream>
#include "Personality.h"
#include <string>
class DigiPet {
private:
	/*!Range: [0,100]*/
	size_t happiness;

	/*!Range: [0,100]*/
	size_t health;

	/*!Range: [0,100]*/
	size_t cleanliness;

	/*!Range: All positive values. (0,inf)*/
	size_t age;

	/*!Range: [0,1]*/
	size_t life_stage;

	/*!Holds and creates the personality and functionality of the egg. Should transfer all data to BabyRoadrunner.*/
	Personality* digiPersonality;

public:
	/*!Pure virtual function to be redefined in each class.*/
	virtual void advance_day() = 0;

	/*! Getter for the life_stage member.*/
	size_t get_life_stage() {
		return life_stage;
	}

protected:

	size_t return_Proficiency() {
		return digiPersonality->get_Proficiency();
	}
	/*! NEW DESIGN STUFF
	A function that will attempt to advance the career of an adult roadrunner. Different personalities will allow pets to pursue different careers.
	Fiesty become professional runners. Reserved become authors. Lazy become artists. Neat become doctors. Energetic become chefs.
	To advance their career the pet must have maxed out proficiency (at 10) and be an adult roadrunner. Then they can advance their career.*/
	virtual void advance_Career() {
		//cout << "You made it to advance Career!" << endl;
		//cout << "Proficiency: " << digiPersonality->get_Proficiency() << endl;
		//cout << "Personality: " << digiPersonality->get_Personality() << endl;

		/*! The amount of starting money that the player starts with in the Fiesty menu within advance career.*/
		int bettingMoney = 20; 

		/*! The int that holds the randomly generated winner of the race in the Fiesty menu within advance career. */
		int winningRunner;

		/*! The int the holds the amount of money bet in the Fiesty menu within advance career.*/
		int amountBet;

		/*! The int that holds the player's choice of who to bet on in the Fiesty menu within advance career.*/
		int betChoice;

		/*! String that holds a name pulled from the nameArray attribute from Personality to be used in the Fiesty menu within advance career.*/
		string name1;

		/*! String that holds a name pulled from the nameArray attribute from Personality to be used in the Fiesty menu within advance career.*/
		string name2;

		/*! String that holds a name pulled from the nameArray attribute from Personality to be used in the Fiesty menu within advance career.*/
		string name3;

		/*! Chat the holds the menu choices for the Energetic menu within advance career.*/
		char chefChoice;

		/*! Char that holds the menu choice for the Reserved menu within advance career.*/
		char bookChoice; 

		/*! Char that holds the menu choice for the Neat menu within advance career.*/
		char docChoice; 

		/*! Char that holds the menu choice for the Neat menu within advance career.*/
		char artChoice;

		/*! String that holds the first color entered by the player in the Lazy menu within advance career.*/
		string color1;


		/*! String array that will hold all chosen strings by the player in the Reserved menu within advance career.*/
		string bookArray[5] = {};


switch (digiPersonality->get_Personality()) {
		default:
					cout << "What is happening" << endl;
					break;
		/*! NEW DESIGN STUFF
		Switch case for the Fiesty case. This is where the pet become a professional runner. Then the player can bet on who will win in the races that the
		pet is participating in. They can bet even if they loose all their money, the player will then be in debt but can still play.*/
		case 'F':
					cout << "Your pet is preparing for their upcoming race!" << endl;
					//Generating names from name array
					name1 = digiPersonality->get_nameArrayAt(rand() % 10);
					name2 = digiPersonality->get_nameArrayAt(rand() % 10);
					name3 = digiPersonality->get_nameArrayAt(rand() % 10);

					//Ensuring different names are printed
					while (name1 == name2 || name2 == name3) {
						name2 = digiPersonality->get_nameArrayAt(rand() % 10);
					}
					while (name3 == name1 || name3 == name2) {
						name3 = digiPersonality->get_nameArrayAt(rand() % 10);
					}
					//Printing Prompts
					cout << "They're racing against Number two: " << name1 << ", Number three: " << name2 << " and Number four: " << name3 << endl;
					//Checking if balance is in the red or not.
						if (bettingMoney < 0) {
							cout << "You have no money! You're gonna go in debt for this bet!" << endl;
							cout << "Current debt: " << bettingMoney << endl;
							}
						else {
							cout << "You have " << bettingMoney << " dollars left to bet." << endl;
						}
					cout << "Who do you want to bet on?" << endl;
					cout << "Number one(1): your pet, Number two(2), Number three(3), or Number four(4)?" << endl;
					cin >> betChoice;
					winningRunner = (rand() % 4) + 1;
					cout << "How much do you want to bet?" << endl;
					cin >> amountBet;
					//Checking winner
					if (betChoice == winningRunner) {
						amountBet = amountBet * 2;
						bettingMoney = bettingMoney + amountBet;
						cout << "You bet correctly! You won!" << endl;
					}
					else {
						bettingMoney = bettingMoney - amountBet;
						cout << "Better luck next time, you lost!" << endl;
					}
					cout << endl;
					break;
		/*! NEW DESIGN STUFF
		Switch case for the Reserved case. This allows the player to help their pet write a book. The player helps the pet determine a genre, a beggining and end 
		to a story. Each day the player gives their pet a new idea.*/
		case 'R':
				/*!First set of choices*/
				do {
					cout << "Your pet is looking for ideas for their next book. They look to you for some inspiration, what do you say?" << endl;
					cout << "a) Write a fantasy book about magical roadrunners!" << endl;
					cout << "b) Write a Sci-fi book about roadrunners in space!" << endl;
					cout << "c) Write a romance story about two roadrunners from fueding families!" << endl;
					cin >> bookChoice;
				} while (bookChoice != 'a' && bookChoice != 'b' && bookChoice != 'c' && cout << "Invalid input" << endl);
				switch (bookChoice) {
				case 'a':
					/*! Second set of choices.*/
					do {
						bookArray[0] = "Your pet is going to write a fantasy book about magical roadrunners!";
						cout << "Your pet looks to you for more inspiration! How should the book start?" << endl;
						cout << "a) Roadrunners fighting a dragon!" << endl;
						cout << "b) A prince becoming a king!" << endl;
						cout << "c) Sneaky roadrunners planning a coup!" << endl;
						cin >> bookChoice;
					} while (bookChoice != 'a' && bookChoice != 'b' && bookChoice != 'c' && cout << "Invalid input" << endl);
					switch (bookChoice) {
					case 'a':
						bookArray[1] = "Roadrunners fighting a dragon!";
						do {
							cout << "How should the book end?" << endl;
							cout << "a) They befriend the dragon!" << endl;
							cout << "b) They slay the dragon!" << endl;
							cout << "c) They are defeated by the dragon!" << endl;
							cin >> bookChoice;
						} while (bookChoice != 'a' && bookChoice != 'b' && bookChoice != 'c' && cout << "Invalid input" << endl);
						switch (bookChoice) {
						case 'a':
							bookArray[2] = "They befriend the dragon!";
							cout << bookArray[0] << " " << bookArray[1] << " " << bookArray[2] << endl;
							break;
						case 'b':
							bookArray[2] = "They slay the dragon!";
							cout << bookArray[0] << " " << bookArray[1] << " " << bookArray[2] << endl;
							break;
						case 'c':
							bookArray[2] = "The are defeated by the dragon!";
							cout << bookArray[0] << " " << bookArray[1] << " " << bookArray[2] << endl;
							break;
						}
						break;
					case 'b':
						bookArray[1] = "A prince becoming a king!";
						do {
							cout << "How should it end?" << endl;
							cout << "a) They rule peacefully!" << endl;
							cout << "b) They rule tyranically!" << endl;
							cout << "c) They rule terribly!" << endl;
							cin >> bookChoice;
						} while (bookChoice != 'a' && bookChoice != 'b' && bookChoice != 'c' && cout << "Invalid input" << endl);
						switch (bookChoice) {
						case 'a':
							bookArray[2] = "They rule peacefully!";
							cout << bookArray[0] << " " << bookArray[1] << " " << bookArray[2] << endl;
							break;
						case 'b':
							bookArray[2] = "They rule tyranically!";
							cout << bookArray[0] << " " << bookArray[1] << " " << bookArray[2] << endl;
							break;
						case 'c':
							bookArray[2] = "They rule terribly!";
							cout << bookArray[0] << " " << bookArray[1] << " " << bookArray[2] << endl;
							break;
						}
						break;
					case 'c':
						bookArray[1] = "Sneaky roadrunners planning a coup!";
						do {
							cout << "How should it end?" << endl;
							cout << "a) They conquer the kingdom!" << endl;
							cout << "b) They fail spectacularly!" << endl;
							cout << "c) They conquer and rule with an iron fist!" << endl;
							cin >> bookChoice;
						} while (bookChoice != 'a' && bookChoice != 'b' && bookChoice != 'c' && cout << "Invalid input" << endl);
						switch (bookChoice) {
						case 'a':
							bookArray[2] = "They conquer the kingdom!";
							cout << bookArray[0] << " " << bookArray[1] << " " << bookArray[2] << endl;
							break;
						case 'b':
							bookArray[2] = "They fail spectacularly!";
							cout << bookArray[0] << " " << bookArray[1] << " " << bookArray[2] << endl;
							break;
						case 'c':
							bookArray[2] = "They conquer and rule with an iron fist!";
							cout << bookArray[0] << " " << bookArray[1] << " " << bookArray[2] << endl;
							break;
						}
						break;
					}
					break;
				case 'b':
					/*! Second set of choices.*/
					do {
						bookArray[0] = "Your pet is going to write a Sci-fi book about roadrunners in space!";
						cout << "Your pet looks to you for more inspiration! How should the book start?" << endl;
						cout << "a) A band of space pirates!" << endl;
						cout << "b) Anti-tech roadrunners that isolate themselves!" << endl;
						cout << "c) Space refugees!" << endl;
						cin >> bookChoice;
					} while (bookChoice != 'a' && bookChoice != 'b' && bookChoice != 'c' && cout << "Invalid input" << endl);
					switch (bookChoice) {
						/*!Third set of choices.*/
					case 'a':
						bookArray[1] = "A band of space pirates!";
						do {
						cout << "How should the book end?" << endl;
						cout << "a) They conquer the world!" << endl;
						cout << "b) They meet a tragic end!" << endl;
						cout << "c) They save the world from an otherworldy demon!" << endl;
						cin >> bookChoice;
						} while (bookChoice != 'a' && bookChoice != 'b' && bookChoice != 'c' && cout << "Invalid input" << endl);
						switch (bookChoice) {
						case 'a':
							bookArray[2] = "They conquer the world!";
							cout << bookArray[0] << " " << bookArray[1] << " " << bookArray[2] << endl;
							break;
						case 'b':
							bookArray[2] = "They meet a tragic end!";
							cout << bookArray[0] << " " << bookArray[1] << " " << bookArray[2] << endl;
							break;
						case 'c':
							bookArray[2] = "They save the world from an otherworldy demon!";
							cout << bookArray[0] << " " << bookArray[1] << " " << bookArray[2] << endl;
							break;
						}
						break;
					case 'b':
						
						bookArray[1] = "Anti-tech roadrunners that isolate themselves!";
						do {
						cout << "How should the book end?" << endl;
						cout << "a) They just live peacefully." << endl;
						cout << "b) They fight back against the tyranny of tech!" << endl;
						cout << "c) They fail in resistance and are overpowered!" << endl;
						cin >> bookChoice;
						} while (bookChoice != 'a' && bookChoice != 'b' && bookChoice != 'c' && cout << "Invalid input" << endl);
						switch (bookChoice) {
						case 'a':
							bookArray[2] = "They just live peacefully.";
							cout << bookArray[0] << " " << bookArray[1] << " " << bookArray[2] << endl;
							break;
						case 'b':
							bookArray[2] = "They fight back against the tyranny of tech!";
							cout << bookArray[0] << " " << bookArray[1] << " " << bookArray[2] << endl;
							break;
						case 'c':
							bookArray[2] = "They fail in resistance and are overpowered!";
							cout << bookArray[0] << " " << bookArray[1] << " " << bookArray[2] << endl;
							break;
						}
						break;
					case 'c':
						bookArray[1] = "Space refugees!";
						do {
							cout << "How should the book end?" << endl;
							cout << "a) They take back their homeworld!" << endl;
							cout << "b) They rebuild their home in a new place!" << endl;
							cout << "c) The conquerers come for their new home!" << endl;
							cin >> bookChoice;
						} while (bookChoice != 'a' && bookChoice != 'b' && bookChoice != 'c' && cout << "Invalid input" << endl);
						switch (bookChoice) {
						case 'a':
							bookArray[2] = "They take back their homeworld!";
							cout << bookArray[0] << " " << bookArray[1] << " " << bookArray[2] << endl;
							break;
						case 'b':
							bookArray[2] = "They rebuild their home in a new place!";
							cout << bookArray[0] << " " << bookArray[1] << " " << bookArray[2] << endl;
							break;
						case 'c':
							bookArray[2] = "The conquerers come for their new home!";
							cout << bookArray[0] << " " << bookArray[1] << " " << bookArray[2] << endl;
							break;
						}
						break;
					}
					break;
				case 'c':
					/*! Second set of choices.*/
					do {
						bookArray[0] = "Your pet is going to Write a romance story about two roadrunners from fueding families!";
						cout << "Your pet looks to you for more inspiration! How should the book start?" << endl;
						cout << "a) The two lovers first meet!" << endl;
						cout << "b) A heated discussion about the war between the families!" << endl;
						cout << "c) A dastardly scheme to attack the other family!" << endl;
						cin >> bookChoice;
					} while (bookChoice != 'a' && bookChoice != 'b' && bookChoice != 'c' && cout << "Invalid input" << endl);
						switch (bookChoice) {
						case 'a':
							bookArray[1] = "The two lovers first meet!";
							do {
								cout << "How should the story end?" << endl;
								cout << "a) The lovers meet and stop the fued!" << endl;
								cout << "b) The lovers meet and form a third party in the fued!" << endl;
								cout << "c) The lovers meet and fight eachother for their families!" << endl;
								cin >> bookChoice;
							} while (bookChoice != 'a' && bookChoice != 'b' && bookChoice != 'c' && cout << "Invalid input" << endl);
							switch (bookChoice) {
							case 'a':
								bookArray[2] = "The lovers meet and stop the fued!";
								cout << bookArray[0] << " " << bookArray[1] << " " << bookArray[2] << endl;
								break;
							case 'b':
								bookArray[2] = "The lovers meet and form a third party in the fued!";
								cout << bookArray[0] << " " << bookArray[1] << " " << bookArray[2] << endl;
								break;
							case 'c':
								bookArray[2] = "The lovers meet and fight eachother for their families!";
								cout << bookArray[0] << " " << bookArray[1] << " " << bookArray[2] << endl;
								break;
							}
							break;
						case 'b':
							bookArray[1] = "A heated discussion about the war between the families!";
							do {
								cout << "How should the story end?" << endl;
								cout << "a) The war heats up and the lovers are caught in the crossfire!" << endl;
								cout << "b) The families end the war!" << endl;
								cout << "c) Everyone the families dies in a tragic turn of events!" << endl;
								cin >> bookChoice;
							} while (bookChoice != 'a' && bookChoice != 'b' && bookChoice != 'c' && cout << "Invalid input" << endl);
							switch (bookChoice) {
							case 'a':
								bookArray[2] = "The war heats up and the lovers are caught in the crossfire!";
								cout << bookArray[0] << " " << bookArray[1] << " " << bookArray[2] << endl;
								break;
							case 'b':
								bookArray[2] = "The families end the war!";
								cout << bookArray[0] << " " << bookArray[1] << " " << bookArray[2] << endl;
								break;
							case 'c':
								bookArray[2] = "Everyone the families dies in a tragic turn of events!";
								cout << bookArray[0] << " " << bookArray[1] << " " << bookArray[2] << endl;
								break;
							}
							break;
						case 'c':
							bookArray[1] = "A dastardly scheme to attack the other family!";
							do {
								cout << "How should the story end?" << endl;
								cout << "a) The scheme succeedes and the two lovers die!" << endl;
								cout << "b) The scheme fails and the two lovers escape!" << endl;
								cout << "c) The scheme succeedes, but the two lovers are able to escape!" << endl;
								cin >> bookChoice;
							} while (bookChoice != 'a' && bookChoice != 'b' && bookChoice != 'c' && cout << "Invalid input" << endl);
							switch (bookChoice) {
							case 'a':
								bookArray[2] = "The scheme succeedes and the two lovers die!";
								cout << bookArray[0] << " " << bookArray[1] << " " << bookArray[2] << endl;
								break;
							case 'b':
								bookArray[2] = "The scheme fails and the two lovers escape!";
								cout << bookArray[0] << " " << bookArray[1] << " " << bookArray[2] << endl;
								break;
							case 'c':
								bookArray[2] = "The scheme succeedes, but the two lovers are able to escape!";
								cout << bookArray[0] << " " <<  bookArray[1] << " " << bookArray[2] << endl;
								break;
							}
							break;
							}
					break;
				
				}
				cout << endl;
				break;
		/*! NEW DESIGN STUFF
		Switch case for the Lazy case. This will allow the player's pet to paint and create different pieces of art using different colors and art styles.*/
		case 'L':
			do {
				cout << "Your pet prepares to create some art, and would be open to ideas." << endl;
				cout << "What art style should they use?" << endl;
				cout << "a) Pop art." << endl;
				cout << "b) Comtemporary art." << endl;
				cout << "c) Abstract art." << endl;
				cout << "d) Hyperrealism." << endl;
				cin >> artChoice;
				cout << "What color should they use?" << endl;
				cin >> color1;
			} while (artChoice != 'a' && artChoice != 'b' && artChoice != 'c' && artChoice != 'd' && cout << "Invalid input" << endl);
				switch (artChoice) {
					case 'a':
						cout << "They make a pop art art piece with a nice shade of " << color1 << "!" << endl;
						break;
					case 'b':
						cout << "They make a comtemporary art art piece using " << color1 << "." << endl;
						cout << "It looks quite nice." << endl;
						break;
					case 'c':
						cout << "They make an abstract art piece! You can see the color " << color1 << " but you don't understand much else." << endl;
						cout << "You still give your approval!" << endl;
						break;
					case 'd':
						cout << "They make a hyperrealistic art piece! It's hard to tell that it's not a photo!" << endl;
						break;
					}
				cout << endl;
				break;
		/*! NEW DESIGN STUFF
		This is the switch case for Neat that puts the makes the pet become a Doctor. The pet can then interact with events within the hospital every day.*/
		case 'N':
				/*! First set of choices for the Neat personality career as a Doctor.*/
				do {
					cout << endl;
					cout << "Your pet starts their day at the local hospital, what should they do first?" << endl;
					cout << "a) Greet their patient." << endl;
					cout << "b) Surprise their patient with some morning treats." << endl;
					cout << "c) Get some paperwork out of the way." << endl;
					cin >> docChoice;
				} while (docChoice != 'a' && docChoice != 'b' && docChoice != 'c' && cout << "Invalid input" << endl);
				switch (docChoice) {
					/*! Choice 'a' from the first set.*/
				case 'a':
					do {
						cout << "You greet your patient and bring a smile to their face." << endl;
						cout << "What should they do next?" << endl;
						cout << "a) Spend some time talking with the patient." << endl;
						cout << "b) Get some paperwork done." << endl;
						cout << "c) Assist some coworkers with their work." << endl;
						cin >> docChoice;
					} while (docChoice != 'a' && docChoice != 'b' && docChoice != 'c' && cout << "Invalid input" << endl);
					//Second Choice
					switch (docChoice) {
						/*! Choice 'a' from second set.*/
					case 'a':
						do {
							cout << "You sit down and talk with their patient. They talk about themselves and get some worries off their chest." << endl;
							cout << "It made them much happier!" << endl;
							cout << "What should they do next?" << endl;
							cout << "a) Spend the rest of the day caring for the patient." << endl;
							cout << "b) Do some paperwork." << endl;
							cout << "c) Head home early." << endl;
							cin >> docChoice;
						} while (docChoice != 'a' && docChoice != 'b' && docChoice != 'c' && cout << "Invalid input" << endl);
						switch (docChoice) {
							/*! Choice 'a' from third set.*/
						case 'a':
							cout << "You spend of the rest of the day caring for the patient. You feel as though you have gotten closer." << endl;
							cout << "After work, you head home and enjoy the rest of your day." << endl;
							break;
							/*! Choice 'b' from third set.*/
						case 'b':
							cout << "You finish up some paperwork and head home after." << endl;
							cout << "After work, you head home and enjoy the rest of your day." << endl;
							break;
							/*! Choice 'c' from third set.*/
						case 'c':
							cout << "You treat yourself and head home early. Not sure your boss loved that." << endl;
							cout << "After work, you head home and enjoy the rest of your day." << endl;
							break;
						}
						
						break;
						/*! Choice 'b' from second set.*/
					case 'b':
						do {
						cout << "You sit down and get some paperwork done!" << endl;
						cout << "What should they do next?" << endl;
						cout << "a) Spend the rest of your day talking with your patient." << endl;
						cout << "b) Get more paperwork done." << endl;
						cout << "c) Assist your coworkers in their work." << endl;
						cout << endl;
						cin >> docChoice;
						} while (docChoice != 'a' && docChoice != 'b' && docChoice != 'c' && cout << "Invalid input" << endl);
						switch (docChoice) {
							/*! Choice 'a' from third set.*/
						case 'a':
							cout << "You spend of the rest of the day caring for the patient. You feel as though you have gotten closer." << endl;
							cout << "After work, you head home and enjoy the rest of your day." << endl;
							break;
							/*! Choice 'b' from third set.*/
						case 'b':
							cout << "You finish up some paperwork and head home after." << endl;
							cout << "After work, you head home and enjoy the rest of your day." << endl;
							break;
							/*! Choice 'c' from third set.*/
						case 'c':
							cout << "You finish the day by helping your coworkers out. They appreciate it." << endl;
							cout << "After work, you head home and enjoy the rest of your day." << endl;
							break;
						}
						break;
						/*! Choice 'c' from second set.*/
					case 'c':
						do {
						cout << "You help some coworkers out with their work. They're grateful!" << endl;
						cout << "What should they do next?" << endl;
						cout << "a) Spend some time talking with the patient." << endl;
						cout << "b) Get some paperwork done." << endl;
						cout << "c) Head home early." << endl;
						cin >> docChoice;
					} while (docChoice != 'a' && docChoice != 'b' && docChoice != 'c' && cout << "Invalid input" << endl);
					switch (docChoice) {
						case 'a':
							cout << "You spend of the rest of the day caring for the patient. You feel as though you have gotten closer." << endl;
							cout << "After work, you head home and enjoy the rest of your day." << endl;
							break;
						case 'b':
							cout << "You finish up some paperwork and head home after." << endl;
							cout << "After work, you head home and enjoy the rest of your day." << endl;
							break;
						case 'c':
							cout << "You treat yourself and head home early. Not sure your boss loved that." << endl;
							cout << "After work, you head home and enjoy the rest of your day." << endl;
							break;
							}
						break;
					}
					break;
				case 'b':
					/*! Choice 'b' from the first set.*/
					do {
						cout << "You surprise your patient with some pudding! They smile as wide as they can and clearly enjoy the gesture. And the sweets." << endl;
						cout << "What should they do next?" << endl;
						cout << "a) Spend some time talking with the patient." << endl;
						cout << "b) Get some paperwork done." << endl;
						cout << "c) Assist some coworkers with their work." << endl;
						cin >> docChoice;
					} while (docChoice != 'a' && docChoice != 'b' && docChoice != 'c' && cout << "Invalid input" << endl);

					switch (docChoice) {
						/*! Choice 'a' from the second set.*/
					case 'a':
						do {
							cout << "You spend some time talking with your patient." << endl;
							cout << "What should they do next?" << endl;
							cout << "a) Spend the rest of the day talking with your patient." << endl;
							cout << "b) Get some paperwork done." << endl;
							cout << "c) Assist some coworkers with their work." << endl;
							cin >> docChoice;
						} while (docChoice != 'a' && docChoice != 'b' && docChoice != 'c' && cout << "Invalid input" << endl);
						switch (docChoice) {
							/*! Choice 'a' from the third set.*/
						case 'a':
							cout << "You spend of the rest of the day caring for the patient. You feel as though you have gotten closer." << endl;
							cout << "After work, you head home and enjoy the rest of your day." << endl;
							break;
							/*! Choice 'b' from the third set.*/
						case 'b':
							cout << "You finish up some paperwork and head home after." << endl;
							cout << "After work, you head home and enjoy the rest of your day." << endl;
							break;
							/*! Choice 'c' from the third set.*/
						case 'c':
							cout << "You finish the day by helping your coworkers out. They appreciate it." << endl;
							cout << "After work, you head home and enjoy the rest of your day." << endl;
							break;
						}
						break;
						/*! Choice 'b' from the second set.*/
					case 'b':
						do {
							cout << "You sit down and get some paperwork done!" << endl;
							cout << "What should they do next?" << endl;
							cout << "a) Spend the rest of the day talking with your patient." << endl;
							cout << "b) Get more paperwork done." << endl;
							cout << "c) Assist your coworkers in their work." << endl;
							cout << endl;
							cin >> docChoice;
						} while (docChoice != 'a' && docChoice != 'b' && docChoice != 'c' && cout << "Invalid input" << endl);
						switch (docChoice) {
							/*! Choice 'a' from the third set.*/
						case 'a':
							cout << "You spend of the rest of the day caring for the patient. You feel as though you have gotten closer." << endl;
							cout << "After work, you head home and enjoy the rest of your day." << endl;
							break;
							/*! Choice 'b' from the third set.*/
						case 'b':
							cout << "You finish up some paperwork and head home after." << endl;
							cout << "After work, you head home and enjoy the rest of your day." << endl;
							break;
							/*! Choice 'c' from the third set.*/
						case 'c':
							cout << "You finish the day by helping your coworkers out. They appreciate it." << endl;
							cout << "After work, you head home and enjoy the rest of your day." << endl;
							break;
						}					
						break;
						/*! Choice 'c' from the second set.*/
					case 'c':
						do {
							cout << "You help some coworkers out with their work. They're grateful!" << endl;
							cout << "What should they do next?" << endl;
							cout << "a) Spend the rest of the day talking with your patient." << endl;
							cout << "b) Get some paperwork done." << endl;
							cout << "c) Go home early." << endl;
							cin >> docChoice;
						} while (docChoice != 'a' && docChoice != 'b' && docChoice != 'c' && cout << "Invalid input" << endl);
						switch (docChoice) {
							/*! Choice 'a' from the third set.*/
						case 'a':
							cout << "You spend of the rest of the day caring for the patient. You feel as though you have gotten closer." << endl;
							cout << "After work, you head home and enjoy the rest of your day." << endl;
							break;
							/*! Choice 'b' from the third set.*/
						case 'b':
							cout << "You finish up some paperwork and head home after." << endl;
							cout << "After work, you head home and enjoy the rest of your day." << endl;
							break;
							/*! Choice 'c' from the third set.*/
						case 'c':
							cout << "You treat yourself and head home early. Not sure your boss loved that." << endl;
							cout << "After work, you head home and enjoy the rest of your day." << endl;
							break;
						}
						break;
					}
					
					break;
				case 'c':
					/*! Choice 'c' from the first set.*/
					do {
						cout << "You set up in your office and get a mountain of paperwork done!" << endl;
						cout << "What should they do next?" << endl;
						cout << "a) Greet your patient." << endl;
						cout << "b) Get some more paperwork done." << endl;
						cout << "c) Assist some coworkers with their work." << endl;
						cin >> docChoice;
					} while (docChoice != 'a' && docChoice != 'b' && docChoice != 'c' && cout << "Invalid input" << endl);
					switch (docChoice) {
						/*! Choice 'a' from the second set.*/
					case 'a':
						do {
						cout << "You greet your patient and bring a smile to their face." << endl;
						cout << "What should they do next?" << endl;
						cout << "a) Spend the rest of the day talking with your patient." << endl;
						cout << "b) Get some paperwork done." << endl;
						cout << "c) Assist some coworkers with their work." << endl;
						cin >> docChoice;
					} while (docChoice != 'a' && docChoice != 'b' && docChoice != 'c' && cout << "Invalid input" << endl);
					switch (docChoice) {
						/*! Choice 'a' from the third set.*/
					case 'a':
						cout << "You spend of the rest of the day caring for the patient. You feel as though you have gotten closer." << endl;
						cout << "After work, you head home and enjoy the rest of your day." << endl;
						break;
						/*! Choice 'b' from the third set.*/
					case 'b':
						cout << "You finish up some paperwork and head home after." << endl;
						cout << "After work, you head home and enjoy the rest of your day." << endl;
						break;
						/*! Choice 'c' from the third set.*/
					case 'c':
						cout << "You finish the day by helping your coworkers out. They appreciate it." << endl;
						cout << "After work, you head home and enjoy the rest of your day." << endl;
						break;
					}
					break;
					/*! Choice 'b' from the second set. */
					case 'b':
						do {
							cout << "You sit down and get some paperwork done!" << endl;
							cout << "What should they do next?" << endl;
							cout << "a) Spend the rest of the day talking with your patient." << endl;
							cout << "b) Get more paperwork done." << endl;
							cout << "c) Assist your coworkers in their work." << endl;
							cout << endl;
							cin >> docChoice;
						} while (docChoice != 'a' && docChoice != 'b' && docChoice != 'c' && cout << "Invalid input" << endl);
						switch (docChoice) {
							/*! Choice 'a' from the third set.*/
						case 'a':
							cout << "You spend of the rest of the day caring for the patient. You feel as though you have gotten closer." << endl;
							cout << "After work, you head home and enjoy the rest of your day." << endl;
							break;
							/*! Choice 'b' from the third set.*/
						case 'b':
							cout << "You finish up some paperwork and head home after." << endl;
							cout << "After work, you head home and enjoy the rest of your day." << endl;
							break;
							/*! Choice 'c' from the third set.*/
						case 'c':
							cout << "You finish the day by helping your coworkers out. They appreciate it." << endl;
							cout << "After work, you head home and enjoy the rest of your day." << endl;
							break;
						}
						break;
						/*! Choice 'c' from the second set.*/
					case 'c':
						do {
							cout << "You help some coworkers out with their work. They're grateful!" << endl;
							cout << "What should they do next?" << endl;
							cout << "a) Spend the rest of the day talking with your patient." << endl;
							cout << "b) Get some paperwork done." << endl;
							cout << "c) Go home early." << endl;
							cin >> docChoice;
						} while (docChoice != 'a' && docChoice != 'b' && docChoice != 'c' && cout << "Invalid input" << endl);
						switch (docChoice) {
							/*! Choice 'a' from the third set.*/
						case 'a':
							cout << "You spend of the rest of the day caring for the patient. You feel as though you have gotten closer." << endl;
							cout << "After work, you head home and enjoy the rest of your day." << endl;
							break;
							/*! Choice 'b' from the third set.*/
						case 'b':
							cout << "You finish up some paperwork and head home after." << endl;
							cout << "After work, you head home and enjoy the rest of your day." << endl;
							break;
							/*! Choice 'c' from the third set.*/
						case 'c':
							cout << "You treat yourself and head home early. Not sure your boss loved that." << endl;
							cout << "After work, you head home and enjoy the rest of your day." << endl;
							break;
						}
						break;
					}
					break;

				}
				cout << endl;
				break;
				/*! NEW DESIGN STUFF
				This is where the menu for the career starts if the pet has the personality of Energetic. Here they will be a chef and the player will be able
				to cook a few items and inputting some choices.*/
		case 'E':
			do {
					cout << "Your pet gets to the kitchen and starts to prepare to cook." << endl;
					cout << "What should they make today?" << endl;
					cout << "a) Something sweet." << endl;
					cout << "b) Something savory." << endl;
					cout << "c) Something salty." << endl;
					cout << "d) Something umami." << endl;
					cin >> chefChoice;
			} while (chefChoice != 'a' && chefChoice != 'b' && chefChoice != 'c' && chefChoice != 'd' && cout << "Invalid input" << endl);
				switch (chefChoice) {
				case 'a':
					cout << "Your pet makes a nice sweet pastry! If they didn't have such a sweet tooth they may have given you some." << endl;
					break;
				case 'b':
					cout << "You pet makes a savory and juicy stew! It fills you up quite well." << endl;
					break;
				case 'c':
					cout << "Your pet makes a salty pulled pork dish with white rice. It's pretty tasty!" << endl;
					break;
				case 'd':
					cout << "Your pet makes some very umami orange chicken with noodles. It's very umami." << endl;
					break;
					}
				cout << endl;
				break;
		}
	}

	/*!NEW DESIGN STUFF
	A getter for the personality string of the Personality class*/
	char return_Personality() {
		return digiPersonality->get_Personality();
	}

	/*NEW DESIGN STUFF
	A function that that will print the relevant information depending on what life stage the pet is in. Since an Egg doesn't have a cleanliness or happiness
	stat, it can be redifined differently in each class.*/
	virtual void status() = 0;

	/*! Default Constructor. Initial values should be set to zero, except health = 100.*/
	DigiPet() {
		health = 100;
		happiness = 0;
		cleanliness = 0;
		age = 0;
		life_stage = 0;
		digiPersonality = new Personality;
	}

	/*! A constructor for the base class DigiPet.*/
	DigiPet(size_t happiness, size_t health, size_t cleanliness, size_t age) {
		this->health = health;
		this->happiness = happiness;
		this->age = age;
		this->cleanliness = cleanliness;
		life_stage = 0; //! Just to ensure that all values are initialized stabily.
		digiPersonality = new Personality;
	}

	/*! Getter for happiness memebr.*/
	size_t get_happiness() {
		return happiness;
	}

	/*! Getter for the health member. */
	size_t get_health() {
		return health;
	}

	/*! Getter for the cleanliness member.*/
	size_t get_cleanliness() {
		return cleanliness;
	}

	/*! Getter for the age member. */
	size_t get_age() {
		return age;
	}

	/*! Mutator for the happiness member.*/
	void modify_happiness(int happiness) {
		
		if (happiness > 100) { //Checking if value is over max value.
			this->happiness = 100;
		}
		else if (happiness < 0) {//Checking if value is under min value.
			this->happiness = 0;
		}
		else {
			this->happiness = happiness;
		}
	}

	/*! Mutator for the health member. */
	void modify_health(int health) {
	
		if (health > 100) { //Checking if value is over max value.
			this->health = 100;
		}
		else if (health < 0) { //Checking if value is under min value.
			this->health = 0;
		}
		else {
			this->health = health;
		}
	}

	/*! Mutator for the cleanliness member. */
	void modify_cleanliness(int cleanliness) {
		
		if (cleanliness > 100) {
			this->cleanliness = 100;
		}
		else if (cleanliness < 0) {
			this->cleanliness = 0;
		}
		else {
			this->cleanliness = cleanliness;
		}
	}

	/*! Just increases the age member by one.*/
	void grow_older() {
		age = age + 1;
	}

	/*! Increases the life_stage member by one. */
	virtual void advance_life_stage() {
		life_stage = life_stage + 1;
		if (life_stage > 1) {
			life_stage = 1;
		}
	}

	/*! Bathe should decrease health by one, increase cleanliness by 3, and decrease happiness by 1. Ensure the values remain within the range.*/
	virtual void bathe() {
		//Neat pets prefer to bathe.
		if (digiPersonality->get_Personality() == 'N') {
			digiPersonality->more_Proficient(); //Increases proficiency by one
			health = health - 1;
			cleanliness = cleanliness + 3;
			happiness = happiness + 4;
			//Assuring that the values stay within the range.
			if (health < 0 || health > 100) {
				health = 0;
			}
			if (cleanliness > 100) {
				cleanliness = 100;
			}
			if (happiness > 100) {
				happiness = 100;
			}
		}
		//Fiesty pets hate bathing
		else if (digiPersonality->get_Personality() == 'F') {
			health = health - 1;
			cleanliness = cleanliness + 3;
			happiness = happiness - 4;

			//Assuring that the values stay within the range.
			if (health < 0 || health > 100) {
				health = 0;
			}
			if (cleanliness > 100) {
				cleanliness = 100;
			}
			if (happiness < 0 || happiness > 100) {
				happiness = 0;
			}
		}
		//Pets with no pref/hate
		else {
			health = health - 1;
			cleanliness = cleanliness + 3;
			happiness = happiness - 1;

			//Assuring that the values stay within the range.
			if (health < 0 || health > 100) {
				health = 0;
			}
			if (cleanliness > 100) {
				cleanliness = 100;
			}
			if (happiness < 0 || happiness > 100) {
				happiness = 0;
			}
		}
	}

	/*! Eat should increase health by three, decrease cleanliness by 5, and decrease happiness by one. Ensure the values remain within the range.*/
	virtual void eat() {
		//If a pet is energetic, they love to eat.
		if (digiPersonality->get_Personality() == 'E') {
			digiPersonality->more_Proficient(); //Increases proficiency by one
			health = health + 3;
			cleanliness = cleanliness - 5;
			happiness = happiness + 3;
			if (health > 100) {
				health = 100;
			}
			if (cleanliness < 0 || cleanliness > 100) {
				cleanliness = 0;
			}
			if (happiness > 100) {
				happiness = 100;
			}
		}
		//If a pet is neat, they have to eat.
		else if (digiPersonality->get_Personality() == 'N') {
			health = health + 3;
			cleanliness = cleanliness - 5;
			happiness = happiness - 6;
			if (health > 100) {
				health = 100;
			}
			if (cleanliness < 0 || cleanliness > 100) {
				cleanliness = 0;
			}
			if (happiness < 0 || happiness > 100) {
				happiness = 0;
			}
		}
		//Pets with no pref/hate
		else {
			health = health + 3;
			cleanliness = cleanliness - 5;
			happiness = happiness - 1;

			//Assuring that the values stay within the range.
			if (health > 100) {
				health = 100;
			}
			if (cleanliness < 0 || cleanliness > 100) {
				cleanliness = 0;
			}
			if (happiness < 0 || happiness > 100) {
				happiness = 0;
			}
		}
	}

	/*!The play function should decrease health by 1, decrease cleanliness by 7, and increase happiness by 3. Be sure these values stay within the desired ranges.*/
	virtual void play() {
		//If the pet has a fiesty personality, they love to play.
		if (digiPersonality->get_Personality() == 'F') {
			digiPersonality->more_Proficient(); //Increases proficiency by one
			health = health - 1;
			cleanliness = cleanliness - 7;
			happiness = happiness + 7;
			//Assuring values stay within range.
			if (health > 100 || health < 0) {
				health = 0;
			}
			if (cleanliness > 100 || cleanliness < 0) {
				cleanliness = 0;
			}
			if (happiness > 100) {
				happiness = 100;
			}
		}
		//If the pet has a reserved personality, they hate to play.
		else if (digiPersonality->get_Personality() == 'R') {
			health = health - 1;
			cleanliness = cleanliness - 7;
			happiness = happiness - 3;
			//Assuring values stay within range.
			if (health > 100 || health < 0) {
				health = 0;
			}
			if (cleanliness > 100 || cleanliness < 0) {
				cleanliness = 0;
			}
			if (happiness > 100 || happiness < 0) {
				happiness = 0;
			}
		}
		//Pets with no play pref/hate
		else {
			health = health - 1;
			cleanliness = cleanliness - 7;
			happiness = happiness + 3;
			//Assuring the values stay within range.
			if (health > 100 || health < 0) {
				health = 0;
			}
			if (cleanliness > 100 || cleanliness < 0) {
				cleanliness = 0;
			}
			if (happiness > 100) {
				happiness = 100;
			}
		}
	}

	/*! NEW DESIGN STUFF
	The nap function should increase health by 5, increase happiness by 4 and decreases cleanliness by 8 as a default.
	This function was made to give each different personality a different preffered activity and hated activity.*/
	virtual void nap() {
		//Pets with the Lazy personality
		if (digiPersonality->get_Personality() == 'L') {
			digiPersonality->more_Proficient(); //Increases proficiency by one
			health = health + 5;
			happiness = happiness + 8;
			cleanliness = cleanliness - 8;
			//Assuring values stay within range.
			if (cleanliness > 100 || cleanliness < 0) {
				cleanliness = 0;
			}
			if (health > 100) {
				health = 100;
			}
			if (happiness > 100) {
				happiness = 100;
			}
		}
		//Pets with the Energetic personality 
		else if (digiPersonality->get_Personality() == 'E') {
			health = health + 5;
			happiness = happiness - 5;
			cleanliness = cleanliness - 8;
			//Assuring values stay within range.
			if (cleanliness > 100 || cleanliness < 0) {
				cleanliness = 0;
			}
			if (health > 100) {
				health = 100;
			}
			if (happiness > 100 || happiness < 0) {
				happiness = 0;
			}
		}
		//Pets with no nap pref/hate
		else {
			health = health + 5;
			happiness = happiness + 4;
			cleanliness = cleanliness - 8;
		}
		//Assuring values stay within range.
		if (cleanliness > 100 || cleanliness < 0) {
			cleanliness = 0;
		}
		if (health > 100) {
			health = 100;
		}
		if (happiness > 100) {
			happiness = 100;
		}
	}

	/*! NEW DESIGN STUFF
	The read function should decrease health by 8, decrease cleanliness by 4, and increase happiness by 4.
	This was another function made so that each personality could have a different preffered and hated activity.*/
	virtual void read() {
		//Reserved pets prefer to read
		if (digiPersonality->get_Personality() == 'R') {
			digiPersonality->more_Proficient(); //Increases proficiency by one
			health = health - 8;
			cleanliness = cleanliness - 4;
			happiness = happiness + 8;
			if (cleanliness > 100 || cleanliness < 0) {
				cleanliness = 0;
			}
			if (health > 100 || health < 0) {
				health = 0;
			}
			if (happiness > 100) {
				happiness = 100;
			}
		}
		//Lazy pets hate reading
		else if (digiPersonality->get_Personality() == 'L') {
			health = health - 8;
			cleanliness = cleanliness - 4;
			happiness = happiness - 4;
			if (cleanliness > 100 || cleanliness < 0) {
				cleanliness = 0;
			}
			if (health > 100 || health < 0) {
				health = 0;
			}
			if (happiness > 100) {
				happiness = 100;
			}
		}
		//Pets with no pref/hate
		else {
			health = health - 8;
			cleanliness = cleanliness - 4;
			happiness = happiness + 4;
			if (cleanliness > 100 || cleanliness < 0) {
				cleanliness = 0;
			}
			if (health > 100 || health < 0) {
				health = 0;
			}
			if (happiness > 100) {
				happiness = 100;
			}
		}
	}
	/*! Function to return the hasCareer bool from digiPersonality.*/
	bool get_careerBool() {
		return digiPersonality->get_check();
	}

	/*! Function to set the hasCareer bool from digiPersonality.*/
	void set_careerBool(bool a) {
		digiPersonality->set_check(a);
	}
};

#endif