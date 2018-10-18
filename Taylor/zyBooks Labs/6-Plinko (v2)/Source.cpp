// Taylor Brown
// Section 2
// taylor@davtar.org

#include <iostream>
#include <iomanip>
#include <sstream>

using namespace std;


// PROGRAM SETTINGS

// menu options
const int MENU_DROP_SINGLE = 1;
const int MENU_DROP_MULTI_ONE_SLOT = 2;
const int MENU_DROP_MULTI_ALL_SLOTS = 3;
const int MENU_SHOW_OPTIONS = 4;
const int MENU_QUIT = 5;

// board dimension declarations
const unsigned int BOARD_HEIGHT = 6; // 1 board height = 2 rows of pegs
const int NUM_SLOTS = 9;

// highest inputted integer
const int MAX_INPUT_INT = 99999999;

// prize slot values
const double PRIZE_SLOTS[NUM_SLOTS] = {
	100.0, 
	500.0, 
	1000.0, 
	0.0, 
	10000.0, 
	0.0, 
	1000.0, 
	500.0, 
	100.0
};


// simulate the chip falling one row, returns position of chip
double SimChipFallOneRow(double chipPos) {
	bool chipDir = false; // false = left, true = right
	// check boundaries
	if (chipPos <= 0) {
		chipPos = 0.5;
	}
	else if (chipPos >= NUM_SLOTS - 1) {
		chipPos = NUM_SLOTS - 1.5;
	}

	// randomly bounce
	else {
		chipDir = rand() % 2;
		chipPos += (int)chipDir - 0.5;
	}
	
	return chipPos;
}

// given the starting position, returns the last element the chip lands on
	// optionally, print the path
int SimChipFallWholePath(int startPos, bool printPath=false) {
	// if printing path, set precision and start outputting the path
	if (printPath) {
		cout << setprecision(1) << "Path: [";
	}
	
	// main loop
	double chipPos = startPos;
	for ( unsigned int row = 0; row < (BOARD_HEIGHT * 2) ; ++row) {
		// if printing path, output next position element
		if (printPath) {
			cout << chipPos << ", ";
		}
		
		// update chip position
		chipPos = SimChipFallOneRow(chipPos);
	}

	// if printing path, output last value
	if (printPath) {
		cout << chipPos << "]" << endl;
	}

	return (int)chipPos;
}

// return the winnings from a given path
double ComputeWinnings(int finalSlot, bool printPath=false) {
	return PRIZE_SLOTS[finalSlot];
}


// returns integer user input given prompts and an error expression to check
int GetUserInput(std::string inputPrompt, std::string errorPrompt,
				 int lowestVal, int highestVal) {
	int userInput;

	// get input
	cout << inputPrompt;
	cin >> userInput;
	cout << endl; // simulate return key for zyBooks

	// test for userInput validity
	while (cin.fail() || userInput < lowestVal || userInput > highestVal) {
		// print error prompt and clear cin buffer
		cout << errorPrompt << endl;
		cin.clear();
		cin.ignore(9999, '\n'); // reset buffer

		// get input again
		cout << inputPrompt;
		cin >> userInput;
		cout << endl; // simulate return key for zyBooks
		cout << endl;
	}
	
	// return validated userInput
	return userInput;
}


// simulates one chip dropped in one slot
void DropSingleChip() {
	cout << "*** Drop a single chip ***" << endl;
	cout << endl;

	// get input for user slot choice
	stringstream inputPrompt;
	inputPrompt << "Which slot do you want to drop the chip in (0-" << (NUM_SLOTS-1) << ")? ";
	int userSlot = GetUserInput(inputPrompt.str(),
									"Invalid slot.", 0, (NUM_SLOTS-1));
	
	// drop one chip into a single slot
	cout << "*** Dropping chip into slot " << userSlot << " ***" << endl;

	int finalSlot = SimChipFallWholePath(userSlot, true);

	cout << setprecision(2) << "Winnings: $" << ComputeWinnings(finalSlot, true) << endl;
}

// simulates multiple chips dropped into one slot
void DropMultiChipsOneSlot() {
	cout << "*** Drop multiple chips ***" << endl;
	cout << endl;
	
	// get number of chips to drop
	int numChipsToDrop = GetUserInput("How many chips do you want to drop (>0)? ",
									  "Invalid number of chips.", 1, MAX_INPUT_INT);
	// get drop slot
	stringstream inputPrompt;
	inputPrompt << "Which slot do you want to drop the chip in (0-" << (NUM_SLOTS-1) << ")? ";
	int userDropSlot = GetUserInput(inputPrompt.str(),
									"Invalid slot.", 0, (NUM_SLOTS-1));

	// drop each chip
	double totWinnings = 0.0;
	int finalSlot = 0;
	for (int chip = 0; chip < numChipsToDrop; ++chip) {
		// set totWinnings with value
		finalSlot = SimChipFallWholePath(userDropSlot);
		totWinnings += ComputeWinnings(finalSlot);
	}

	// calculate average winnings
	double avgWinnings = totWinnings / numChipsToDrop;

	// output final winnings
	cout << setprecision(2);
	cout << "Total winnings on " << numChipsToDrop << " chips: $" << totWinnings << endl;
	cout << "Average winnings per chip: $" << avgWinnings << endl; 
}

// simulates multiple chips dropped into all slots
void DropMultiChipsAllSlots() {
	cout << "*** Sequentially drop multiple chips ***" << endl;
	cout << endl;

	// get input, test for failure
	int numChipsToDrop = GetUserInput("How many chips do you want to drop (>0)? ",
									  "Invalid number of chips.", 1, MAX_INPUT_INT);

	// winnings variable declarations
	double totWinnings[NUM_SLOTS];
	double avgWinnings[NUM_SLOTS];
	// initialize arrays with 0
	for (int slot = 0; slot < NUM_SLOTS; ++slot) {
		totWinnings[slot] = 0.0;
		avgWinnings[slot] = 0.0;
	}

	// iterate over every slot
	int finalSlot = 0;
	for (int slot = 0; slot < NUM_SLOTS; ++slot) {
		// drop every chip into the slot
		for (int chip = 0; chip < numChipsToDrop; ++chip) {
			// find the final slot
			finalSlot = SimChipFallWholePath(slot);
			// add to total winnings in that slot
			totWinnings[slot] += ComputeWinnings(finalSlot);
		}
	}

	// set average winnings
	for (int slot = 0; slot < NUM_SLOTS; ++slot) {
		avgWinnings[slot] = totWinnings[slot] / numChipsToDrop;
	}

	// display total and average winnings per slot
	cout << fixed << setprecision(2);
	for (int slot = 0; slot < NUM_SLOTS; ++slot) {
		cout << "Total Winnings on " << numChipsToDrop << " chips in slot "
			<< slot << ": $" << totWinnings[slot] << endl;
		cout << "Average winnings per chip: $" << avgWinnings[slot] << endl;
		cout << endl; // separate slot groups
	}
}


// show menu options
void ShowMenuOptions() {
	cout << "Menu: PLease select one of the following options: " << endl;
	cout << endl;
	cout << MENU_DROP_SINGLE << " - Drop a single chip into one slot" << endl;
	cout << MENU_DROP_MULTI_ONE_SLOT << " - Drop multiple chips into one slot" << endl;
	cout << MENU_DROP_MULTI_ALL_SLOTS << " - Drop multiple chips into each slot" << endl;
	cout << MENU_SHOW_OPTIONS << " - Show the options menu" << endl;
	cout << MENU_QUIT << " - Quit the program" << endl; 
}


// processes user selection number, returns if program should keep executing
bool ProcessMenuSelection(int userSelection) {
	switch (userSelection) {
	case MENU_DROP_SINGLE: // dropping a single chip
		DropSingleChip();
		break;

	case MENU_DROP_MULTI_ONE_SLOT: // dropping multiple chips in one slot
		DropMultiChipsOneSlot();
		break;

	case MENU_DROP_MULTI_ALL_SLOTS: // dropping multiple chips in all slots
		DropMultiChipsAllSlots();
		break;

	case MENU_SHOW_OPTIONS: // show menu options
		ShowMenuOptions();
		break;

	case MENU_QUIT: // quit program
		return false;
	}

	// keep program running
	return true;
}


// main program entry
int main() {
	// random seed
	srand(time(0));
	// FIXME: random seed declarations
	const int RANDOM_SEED = 42; 
	srand(RANDOM_SEED);

	// welcome message
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

		programRunning = ProcessMenuSelection(userSelection);
	}
	cout << "Goodbye!";

	return 0;
}