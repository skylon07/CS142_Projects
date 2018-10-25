
#include <iostream>
#include <iomanip>
#include <sstream>

using namespace std;

// Menu constants
	const int MENU_DROP_SINGLE = 1;
	const int MENU_DROP_MULTI = 2;
	const int MENU_DROP_MULTI_ALL = 3;
	const int MENU_SHOW_OPTIONS = 4;
	const int MENU_QUIT = 5;
	

//Board constants
const int NUM_SLOTS = 9;
const unsigned int BOARD_HEIGHT = 6;

//Winnings Constants Array
	const double PRIZE_SLOTS[NUM_SLOTS]{
		100.00,
		500.00,
		1000.00,
		0.00,
		10000.00,
		0.00,
		1000.00,
		500.00,
		100.00,
	};

// Average winnings function
	void AvgWinningString (double totWinnings, int numChips){
	    double avgWinnings = (totWinnings/numChips);
		cout << setprecision(2);
		cout << "Total winnings on " << numChips << " chips: $" << totWinnings << endl;
		cout << "Average winnings per chip: $" << avgWinnings << endl; 
	}

//Chip path code for one row
	double ChipPathOneRow (double chipPos) {
		bool chipDir = false;
	    
		// boundary setting
			if (chipPos <= 0) {
				chipPos = 0.5;
			}
			else if (chipPos >= NUM_SLOTS - 1) {
				chipPos = NUM_SLOTS - 1.5;
			}
			// random bounce
			else {
				 chipDir = rand() % 2;
				chipPos += chipDir - 0.5;
			}

		return chipPos;
	}

//The whole path and makes printing optional
	int FullPath(int startPos, bool printPath = false) {
	// if printPath = false, start outputting chip path
		if (printPath) {
			cout << setprecision(1) << "Path: [";
		}

	double chipPos = startPos;
	for ( unsigned int row = 0; row < (BOARD_HEIGHT * 2) ; ++row) {
		// if printing path, list next position
			if (printPath) {
				cout << chipPos << ", ";
			}
		
		//update chip position DONT DELETE
			chipPos = ChipPathOneRow(chipPos);
	}
	if (printPath) {
		cout << chipPos << "]" << endl;
	}
	return (int)chipPos;
}

//Winnings Function for given path
	double ComputeWinnings(int finalSlot){
		return PRIZE_SLOTS[finalSlot];
	}

//Get UserMenu Selection
	int GetUserInput(string promptInput, string promptError, int lowVal, int highVal){
		int userInput;

		cout << promptInput;
		cin  >> userInput;
		cout << endl;

		while (cin.fail() || userInput < lowVal || userInput > highVal){
			cout << promptError << endl;
		//Resets value
			cin.clear();
		//buffer
			cin.ignore(9999, '\n');
		//gets new input
			cout << promptInput;
			cin  >> userInput;
			cout << endl;
			cout << endl;
		}
	return userInput;
	}

//Menu Function 
	void DropSingle(){
		cout << "*** Drop a single chip ***" << endl; 
		cout << endl;
	//user slot selection
		stringstream promptInput;
		
		promptInput << "Which slot do you want to drop the chip in (0-" << (NUM_SLOTS - 1) << ")? ";
		int dropSlot = GetUserInput(promptInput.str(),
			"Invalid slot.", 0, (NUM_SLOTS - 1));
	cout << "*** Dropping chip into slot " << dropSlot << " ***" << endl;
	int finalSlot = FullPath(dropSlot, true); // true so that it prints path	

	cout << setprecision(2) << "Winnings: $" << ComputeWinnings(finalSlot) << endl;
	}

	void MultiChipsSameSlot() {
		cout << "*** Drop multiple chips ***" << endl; 
		cout << endl;
		//number of chips
			int numChips = GetUserInput("How many chips do you want to drop (>0)? ",
				 "Invalid number of chips.", 1, 99999999);
		//slot number
			stringstream promptInput; 
			promptInput << "Which slot do you want to drop the chip in (0-" << (NUM_SLOTS - 1) << ")? ";
			int dropSlot = GetUserInput(promptInput.str(),
			"Invalid slot.", 0, (NUM_SLOTS - 1));
		//drop chip
			double totWinnings = 0.0;
			int finalSlot = 0;
			for (int chip = 0; chip < numChips; ++chip){
				finalSlot = FullPath(dropSlot);
				totWinnings +=ComputeWinnings(finalSlot);
			}
		//Average winnings
		AvgWinningString(totWinnings, numChips);
	}

	void MultiChipsAllSlots() {
		int finalSlot = 0;
		double totWinnings[NUM_SLOTS];
		double avgWinnings[NUM_SLOTS];
		

		for (int slot = 0; slot < NUM_SLOTS; ++slot) {
			totWinnings[slot] = 0.0;
			avgWinnings[slot] = 0.0;
		}

		cout << "*** Sequentially drop multiple chips ***" << endl;
		cout << endl;
		//input and validation
			int numChips = GetUserInput("How many chips do you want to drop (>0)? ",
				"Invalid number of chips.", 1, 99999);
		
		// array for average winnings per chip 
			for (int slot = 0; slot < NUM_SLOTS; ++slot) {
				// drop indiviual chips in slots
					for (int chip = 0; chip < numChips; ++chip){
						finalSlot = FullPath(slot);
						totWinnings[slot] += ComputeWinnings(finalSlot);
					}
			}
		for (int slot = 0; slot < NUM_SLOTS; ++slot){
			avgWinnings[slot] = totWinnings[slot] / numChips;
		}
		// out put total winnings
			cout << fixed << setprecision(2);
			for (int slot = 0; slot < NUM_SLOTS; ++slot){
				cout << "Total Winnings on " << numChips << " chips in slot " << slot << ": $" << totWinnings[slot] << endl;
				cout << "Average winnings per chip: $" << avgWinnings[slot] << endl;
				cout << endl; 
			}
	}


	void ShowMenuOptions() {
		cout << "Menu: PLease select one of the following options: " << endl;
		cout << endl;
		cout << MENU_DROP_SINGLE << " - Drop a single chip into one slot" << endl;
		cout << MENU_DROP_MULTI << " - Drop multiple chips into one slot" << endl;
		cout << MENU_DROP_MULTI_ALL << " - Drop multiple chips into each slot" << endl;
		cout << MENU_SHOW_OPTIONS << " - Show the options menu" << endl;
		cout << MENU_QUIT << " - Quit the program" << endl; 
	}

	bool MenuSelection(int userSelection) {
		switch (userSelection) {
		case MENU_DROP_SINGLE: // dropping a single chip
			DropSingle();
			break;

		case MENU_DROP_MULTI: // dropping multiple chips in one slot
			MultiChipsSameSlot();
			break;

		case MENU_DROP_MULTI_ALL: // dropping multiple chips in all slots
			MultiChipsAllSlots();
			break;

		case MENU_SHOW_OPTIONS: // show menu options
			ShowMenuOptions();
			break;

		case MENU_QUIT: 
			return false;
		}
	// keep program running
	return true;
}

int main() {
	// random seed
	srand(time(0));
	// FIXME: random seed declarations
	const int RANDOM_SEED = 42; 
	srand(RANDOM_SEED);



	cout << fixed << "Welcome to the Plinko simulator! Enter " 
		<< MENU_SHOW_OPTIONS << " to see options." << endl;
	cout << endl;

	// Main Loop
	int userSelection = 0;
	bool programRunning = true;
	stringstream errorPrompt;
	errorPrompt << "Invalid selection. Enter " << MENU_SHOW_OPTIONS << " to see options.";
	while (programRunning) {
		// get input
		userSelection = GetUserInput("Enter your selection now: ",
										  errorPrompt.str(), 1, 5);
		programRunning = MenuSelection(userSelection);
	}
	cout << "Goodbye!";

	return 0;
}