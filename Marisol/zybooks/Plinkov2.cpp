
#include <iostream>
#include <iomanip>

using namespace std;

// Menu constants
	const int MENU_DROP_SINGLE = 1;
	const int MENU_DROP_MULTI = 2;
	const int MENU_SHOW_OPTIONS = 3;
	const int MENU_QUIT = 4;

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
 		0.0,
		0.0,
};

//Winnings Function for single chip
	//double ComputeWinnings(int slot){

//	}

// set totWinnings with value
double Total_Winnings (int chipPos){
	double totWinnings = 0.0;
			switch ((int) chipPos) {
				case 0: 
				case 8:
					totWinnings = PRIZE_SLOTS[0];
					break;

				case 1:
				case 7:
					totWinnings = PRIZE_SLOTS[1];
					break;

				case 2:
				case 6:
					totWinnings = PRIZE_SLOTS[2];
					break;
				case 3:
				case 5:
					totWinnings = PRIZE_SLOTS[3];
					break;

				case 4:
					totWinnings = PRIZE_SLOTS[4];
					break;
				
				default:
					cout << "ERROR CHIPPOS SWITCH" << endl;
				
			}
				cout << setprecision(2) << "Winnings: $" << totWinnings << endl;
}			







int main() {
	int userSelection = 0;


	bool programRunning = true;


	double totWinnings = 0.0;
	double avgWinnings = 0.0;


	 // 1 board height = 2 rows of pegs
	int userSlot = 0;
	int numChips = 0;

	bool chipDir = 0; // False = Left   True = Right
	double chipPos = 0.0;

	const int RANDOM_SEED = 42; 
	srand(RANDOM_SEED);

	cout << fixed << "Welcome to the Plinko simulator! Enter 3 to see options." << endl;
	cout << endl;

	// Main Loop
	while (programRunning) {
		totWinnings = 0;
		avgWinnings = 0;

		cout << "Enter your selection now: ";
		cin >> userSelection;
		cout << endl; // simulate return key for zyBooks

		// Process Selection
		switch (userSelection) {
			if (userSelection == MENU_QUIT) {
				break;
			}
		case MENU_DROP_SINGLE:
			cout << "*** Drop a single chip ***" << endl;
			cout << endl;
			cout << "Which slot do you want to drop the chip in (0-8)? ";
			cin >> userSlot;
			cout << endl;


			cout << "*** Drop multiple chips ***" << endl;
			cout << endl;
			cout << "How many chips do you want to drop (>0)? ";
			cin >> numChips;
			cout << endl;

			cout << "Which slot do you want to drop the chip in (0-8)? ";
			cin >> userSlot;
			cout << endl;


			else {
				// drop the chips
				for (int chip = 0; chip < numChips; ++chip) {
					chipPos = userSlot;

					for (unsigned int row = 0; row < (BOARD_HEIGHT * 2); ++row) {
						// boundary setting
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
					}

				}
			}

		case MENU_SHOW_OPTIONS:
			cout << "Menu: PLease select one of the following options: " << endl;
			cout << endl;
			cout << MENU_DROP_SINGLE << " - Drop a single chip into one slot" << endl;
			cout << MENU_DROP_MULTI << " - Drop multiple chips into one slot" << endl;
			cout << MENU_SHOW_OPTIONS << " - Show the options menu" << endl;
			cout << MENU_QUIT << " - Quit the program" << endl; 
			break;

		case MENU_QUIT:
			programRunning = false;
			break;

		default:
			cout << "Invalid Selection. Enter 3 to see options." << endl;
			break;
		}

	}
	cout << "Goodbye!";

	return 0;
}