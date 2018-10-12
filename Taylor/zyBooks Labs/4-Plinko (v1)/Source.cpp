// Taylor Brown && Marisol Mattson
// Section 2
// taylor@davtar.org
// Used only Visual Studio as IDE

#include <iostream>
#include <iomanip>


using namespace std;

int main() {
	int userSelection = 0;
	const int MENU_DROP_SINGLE = 1;
	const int MENU_DROP_MULTI = 2;
	const int MENU_SHOW_OPTIONS = 3;
	const int MENU_QUIT = 4;

	bool programRunning = true;

	//WHY NO USE ARRAY!?!?!?!?!
	const double PRIZE0 = 100.00;
	const double PRIZE1 = 500.00;
	const double PRIZE2 = 1000.00;
	const double PRIZE3 = 0.00;
	const double PRIZE4 = 10000.00;
	double totWinnings = 0.0;
	double avgWinnings = 0.0;

	const int NUM_SLOTS = 9;
	const unsigned int BOARD_HEIGHT = 6; // 1 board height = 2 rows of pegs
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

			/*slot validation*/
			if (userSlot < 0 || userSlot >= NUM_SLOTS) {
				cout << "Invalid slot.";
				break; // im needed!
			}

			else {
				cout << "*** Dropping chip into slot " << userSlot << " ***" << endl;
				chipPos = userSlot;

				cout << setprecision(1) << "Path: [";
				for ( unsigned int row = 0; row < (BOARD_HEIGHT * 2) ; ++row) {
					cout << chipPos << ", "; 

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
				cout << chipPos << "]" << endl;

				// set totWinnings with value
				switch ((int) chipPos) {
				case 0: 
				case 8:
					totWinnings = PRIZE0;
					break;

				case 1:
				case 7:
					totWinnings = PRIZE1;
					break;

				case 2:
				case 6:
					totWinnings = PRIZE2;
					break;

				case 3:
				case 5:
					totWinnings = PRIZE3;
					break;

				case 4:
					totWinnings = PRIZE4;
					break;
				
				default:
					cout << "ERROR CHIPPOS SWITCH" << endl;
				}

				cout << setprecision(2) << "Winnings: $" << totWinnings << endl;

			}

			break;

		case MENU_DROP_MULTI:
			cout << "*** Drop multiple chips ***" << endl;
			cout << endl;
			cout << "How many chips do you want to drop (>0)? ";
			cin >> numChips;
			cout << endl;

			// Number of chips validation
			if (numChips <= 0) {
				cout << "Invalid number of chips." << endl;
				break; // needed dont delete
			}

			cout << "Which slot do you want to drop the chip in (0-8)? ";
			cin >> userSlot;
			cout << endl;

			/*slot validation*/
			if (userSlot < 0 || userSlot >= NUM_SLOTS) {
				cout << "Invalid slot." << endl;
				break; // im needed!
			}

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

					// set totWinnings with value
					switch ((int)chipPos) {
					case 0:
					case 8:
						totWinnings += PRIZE0;
						break;

					case 1:
					case 7:
						totWinnings += PRIZE1;
						break;

					case 2:
					case 6:
						totWinnings += PRIZE2;
						break;

					case 3:
					case 5:
						totWinnings += PRIZE3;
						break;

					case 4:
						totWinnings += PRIZE4;
						break;

					default:
						cout << "ERROR CHIPPOS SWITCH" << endl;
					}

				}
			}

			avgWinnings = totWinnings / numChips;

			cout << setprecision(2);
			cout << "Total winnings on " << numChips << " chips: $" << totWinnings << endl;
			cout << "Average winnings per chip: $" << avgWinnings << endl; 

			break;

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