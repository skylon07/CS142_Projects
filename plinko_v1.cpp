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

	cout << "Welcome to the Plinko simulator!  Enter 3 to see options." << endl;
	cout << endl;

	// Main Loop
	while (programRunning) {
		cout << "Enter your selection now :";
		cin >> userSelection;
		cout << endl; // simulate return key for zyBooks

		// Process Selection
		switch (userSelection) {
		case MENU_DROP_SINGLE:
			// TODO

		case MENU_DROP_MULTI:
			// TODO

		case MENU_SHOW_OPTIONS:
			//TODO

		case MENU_QUIT:
			//TODO

		default:
		}
			   		 	  	  	   
	}
	return 0;
}