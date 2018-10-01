// Taylor Brown && Marisol Mattson
// Section 2
// taylor@davtar.org

#include <iostream>



using namespace std;
int main() {
	int userSelection = 0;
	const int MENU_DROP_SINGLE = 1;
	const int MENU_DROP_MULTI = 2;
	const int MENU_SHOW_OPTIONS = 3;
	const int MENU_QUIT = 4;
	bool programRunning = true;
	//WHY NO USE ARRAY!?!?!?!?!
	const int PRIZE0 = 100;
	const int PRIZE1 = 500;
	const int PRIZE2 = 1000;
	const int PRIZE3 = 0;
	const int PRIZE4 = 10000;
	const int NUM_SLOTS = 9;

	

	cout << "Welcome to the Plinko simulator! Enter 3 to see options." << endl;
	cout << endl;

	// Main Loop
	while (programRunning) {
		cout << "Enter your selection now :";
		cin >> userSelection;
		cout << endl; // simulate return key for zyBooks

		// Process Selection
		switch (userSelection) {
			if (userSelection == MENU_QUIT) {
				break;
			}
		case MENU_DROP_SINGLE:
			int userSlot = 0;
			cout << "*** Drop a single chip ***" << endl;
			cout << endl;
			cout << "Which slot would you like to drop the chip in (0-8)? " << endl;
			cin >> userSlot;
				
			/*slot validation*/ 
			if (userSlot < 0) {

			}
			if (userSlot >= NUM_SLOTS) {

			}
			//TODO
			break;

		case MENU_DROP_MULTI:
			//TODO
			break;

		case MENU_SHOW_OPTIONS:
			//TODO
			break;

		case MENU_QUIT:
			//TODO
			break;

		default:
			cout << "Invalid Selection" << endl;
			cout << "Enter your Selection" << endl;
			cin >> userSelection;
			break;
		}

	}
	cout << "Goodbye!";

	return 0;
}