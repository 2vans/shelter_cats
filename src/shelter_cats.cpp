//============================================================================
// Name        : shelter_cats.cpp
// Author      : Michal Jablonski
// Version     :
// Copyright   : DeeR Corporation.
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {
	//declarations of variables
	int space_count;
	int menu_choice;
	int cats_number = 0;
	string delete_choice;

	bool exit = false;
	//first main loop
	while (!exit) {
		//Ask for the amount of space you have in your shelter
		cout << "How much space do you have in shelter?" << endl;
		cin >> space_count;
		//check if the input is a integer
		if (cin.fail()) {
			cin.clear();
			std::cin.ignore(256, '\n');
			cout << "Enter number" << endl;
			//check if the number is zero and less
		} else if (space_count <= 0) {
			cout << "Space cannot be less or equal to 0" << endl;
		} else {
			// Creates database with amount you submitted

			string cat_database[space_count][4];

			//secend main loop
			while (!exit) {
				//simple menu
				cout << "Space for cats: " << space_count << endl;
				cout << "Number of cats: " << cats_number << endl;
				cout << endl;
				cout << "===OPTIONS===" << endl;
				cout << "1. Add cat." << endl;
				cout << "2. Remove cat." << endl;
				cout << "3. Status" << endl;
				cout << "4. Exit" << endl;

				//your input in menu
				cin >> menu_choice;
				//make sure that user iput is integer
				if (cin.fail()) {
					cin.clear();
					std::cin.ignore(256, '\n');
					cout << "Enter number" << endl;

				}
				// mennu logic
				// choice 1. add cat
				if (menu_choice == 1) {
					if (cats_number >= space_count) {
						//overflow logic
						cout << "you have to many cats, remove at least one."
								<< endl;
					} else {
						//adding cat logic
						cout << endl;
						cout << "Space for cats: " << space_count - cats_number
								<< endl;
						cout << endl;
						//spcecifie name
						cout << "1. Name:" << endl;
						cin >> cat_database[cats_number][0];
						//specifie age
						cout << "2. Age:" << endl;
						cin >> cat_database[cats_number][1];
						// specifie vaccines
						cout << "3. Vaccines" << endl;
						cin >> cat_database[cats_number][2];
						//specifie description
						cout << "4. Description" << endl;
						cin >> cat_database[cats_number][3];

						//incrising number of cats
						cats_number++;
					}
				} else
				// kasowanie ostatniego kota
				if (menu_choice == 2) {

					// checking if yoy have a cat
					if (cats_number <= 0) {
						cout << "You have no cats in database" << endl;
					} else {
						//make sure option
						cout
								<< "Are you sure that you want to remove last added cat? (y/n)"
								<< endl;

						cin >> delete_choice;
						if (delete_choice == "y") {
							//deleting kat
							for (int j = 0; j < 4; j++) {
								cat_database[cats_number - 1][j] = "NULL";

							}
							cats_number--;

						} else if (delete_choice == "n") {
							//no option in deleting cat
							cout << "Deleting stops." << endl;
						} else {

							cout << "Unknown command, please try again" << endl;
						}
					}
					//comand status
				} else if (menu_choice == 3) {
					//print on screen list of cats
					for (int i = 0; i < cats_number; i++) {
						for (int j = 0; j < 4; j++) {
							cout << cat_database[i][j] << " " << flush;
						}
						cout << endl;
					}
					cout << endl;
				} else
				//comand exit
				if (menu_choice == 4) {
					//exit the program
					exit = true;
				} else {
				}
			}
		}
	}
	return 0;
}
