#include <iostream>
#include <vector>
#include <iomanip>
#include <string>


// PROGRAM SETTINGS

const char BOARD_SPACE = '_';
const char BOARD_X = 'X';
const char BOARD_O = 'O';


// return a random integer within a range
int RandInt(int lowBound, int highBound) {
    int randVal = rand(); // get some random value
    int range = highBound - lowBound; // calculate the range of values
    int randValInRange = randVal % (range + 1); // limit inside range (inclusive of high)
    int randValShifted = lowBound + randValInRange; // shift to set range at the low bound

    return randValShifted;
}

// randomly choose from values in a vector
template <typename anyType>
anyType RandChoice(std::vector<anyType> vect) {
    int idx = RandInt(0, vect.size() - 1);
    return vect.at(idx);
}

// displays a tictactoe board
void DispBoard(char board[3][3]) {
    // display col numbers
    std::cout << " ";
    for (int i = 1; i <= 3; ++i) {
        std::cout << std::setw(3) << i;
    }
    std::cout << std::endl;

    // display row numbers and elements
    for (int row = 0; row < 3; ++row) {
        std::cout << (row + 1);
        for (int col = 0; col < 3; ++col) {
            std::cout << std::setw(3) << board[row][col];
        }
        std::cout << std::endl;
    }
}

// displays the basic view (message + board)
void DispView(std::string msg, char board[3][3]) {
    system("clear");
    std::cout << msg << std::endl;
    std::cout << std::endl;
    DispBoard(board);
    std::cout << std::endl;
}

// display with input asking for players choice
void DispViewAsk(std::string msg, char board[3][3], char playerTurn, int& col, int& row) {
    DispView(msg, board);

    std::cout << playerTurn << "'s turn, enter collumn and row: ";
    std::cin >> col >> row;
}

// display with a winning message
void DispViewWin(char board[3][3], char winningPlayer) {
    std::string msg = "The " ;
    msg += winningPlayer;
    msg += "'s won!!!";
    DispView(msg, board);

    std::cout << "Press Enter to quit" << std::endl;
    system("read");
}

// display with a draw message
void DispViewDraw (char board[3][3]) {
    DispView("Nobody won, game is a draw", board);

    std::cout << "Press Enter to quit" << std::endl;
    system("read");
}


// tests if either player won given a board
bool DidPlayerWin(char board[3][3]) {
    // test if 3 in a row on rows
    for (int row = 0; row < 3; ++row) {
        // if theres a match without spaces
        if (board[row][0] != BOARD_SPACE) {
            if (board[row][0] == board[row][1] && board[row][1] == board[row][2]) {
                return true;
            }
        }
    }
    // test if 3 in a row on cols
    for (int col = 0; col < 3; ++col) {
        // if theres a match without spaces
        if (board[0][col] != BOARD_SPACE) {
            if (board[0][col] == board[1][col] && board[1][col] == board[2][col]) {
                return true;
            }
        }
    }
    // test if 3 in a row for diagonals
    if (board[0][0] != BOARD_SPACE) {
        if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
            return true;
        }
    }
    if (board[2][0] != BOARD_SPACE) {
        if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
            return true;
        }
    }
    // no more cases, return false
    return false;
}


// raises an error with a message
void RaiseError(std::string message) {
    std::cout << "ERROR: " << message << std::endl;
    std::cout << "Press Enter to continue" << std::endl;
    system("read");
}


// main program enterance
int main() {
    srand(time(0));

    // initialize main variables
    char board[3][3];
    char playerTurn = 'X'; // whose turn it is

    // messages to appear while players take turns
    const std::vector<std::string> DISPLAY_MESSAGES = {
    "Enter collumn first, then row",
    "The first games of Tic-Tac-Toe were played as early as 1300 BC in Egypt!",
    "\"OXO\" was the first video game made on a computer",
    "Tit-tat-toe, three in a row!",
    "The \"cat\" wins when the game is scratched (cat's scratch)",
    "Did you know the game can still be fun even if nobody wins?"
    };

    // populate board with space characters
    for (int row = 0; row < 3; ++row) {
        for (int col = 0; col < 3; ++col) {
            board[row][col] = BOARD_SPACE;
        }
    }

    // main program loop
    bool programRunning = true;
    int playerRow = 0; // input row/col
    int playerCol = 0;
    int turnCount = 0; // number of turns taken
    while (programRunning) {
        // first message to appear (will randomly change later)
        static std::string msg = "Hit Ctrl+C to quit at any time";

        // output menu/view
        DispViewAsk(msg, board, playerTurn, playerCol, playerRow);

        // reload a guaranteed new random tip/message
            // after dispview because first is always "Ctrl+C to quit"
        std::string newMsg = msg;
        while (newMsg == msg) {
            newMsg = RandChoice(DISPLAY_MESSAGES);
        }
        msg = newMsg;

        // check bounds
        if (playerRow < 1 || playerRow > 3 || playerCol < 1 || playerCol > 3) {
            RaiseError("Invalid row/col number (1-3)");
            continue;
        }

        // set input values to array indexes
        --playerRow;
        --playerCol;

        // check if elements are already set
        if (board[playerRow][playerCol] != BOARD_SPACE) {
            RaiseError("Space already chosen");
            continue;
        }

        // set board element to players char
        board[playerRow][playerCol] = playerTurn;

        // test if players have won
        if (DidPlayerWin(board)) {
            // redisplay board with win message
            DispViewWin(board, playerTurn);
            programRunning = false;
            break;
        }


        // swap players turn
        if (playerTurn == BOARD_X) {
            playerTurn = BOARD_O;
        }
        else {
            playerTurn = BOARD_X;
        }
        ++turnCount; // incrememt turn count

        // test if match ends in a draw
        if (turnCount == 9) {
            // redisplay board with draw message
            DispViewDraw(board);
            programRunning = false;
            break;
        }
    }

    system("clear");
    return 0;
}