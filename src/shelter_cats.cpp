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
	int space_count;
	int menu_choice;
	int cats_number = 0;
	string delete_choice;

	bool exit = false;

	//Ask for the amount of space you have in your shelter
	cout << "How much space do you have in shelter?" << endl;
	cin >> space_count;
	// Creates database with amount you submitted
	string cat_database[space_count - 1][3];

	//main loop
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

		if (menu_choice == 1) {
			//adding cat
			cout << endl;
			cout << "Space for cats: " << space_count - cats_number << endl;
			cout << endl;
			cout << "1. Name:" << endl;
			cin >> cat_database[cats_number][0];
			cout << "2. Age:" << endl;
			cin >> cat_database[cats_number][1];
			cout << "3. Vaccines" << endl;
			cin >> cat_database[cats_number][2];
			cout << "4. Description" << endl;
			cin >> cat_database[cats_number][3];
			//incrising number of cats
			cats_number++;

		}
		// kasowanie ostatniego kota
		if (menu_choice == 2) {
			cout
					<< "Are you sure that you want to remove last added cat? (y/n)";
			cin >> delete_choice;
			if (delete_choice == "y") {

				for (int j = 0; j < 4; j++) {
					cat_database[cats_number][j] = "NULL";

				}
				cats_number--;
			} else if (delete_choice == "y") {
				cout << "Deletind stops." << endl;
			} else {
			}
		}

		if (menu_choice == 3) {
			for (int i = 0; i < cats_number; i++) {
				for (int j = 0; j < 4; j++) {
					cout << cat_database[i][j] << " " << flush;
				}
				cout << endl;
			}
			cout << endl;
		}

		if (menu_choice == 4) {
			//exit the program
			exit = true;
		}
	}
	return 0;
}
