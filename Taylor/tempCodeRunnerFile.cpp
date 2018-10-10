#include <iostream>
#include <vector>
#include <string>
#include <cstdio>


// function to display the menu
void DisplayMenu() {
    std::cout << "MENU" << std::endl;
    std::cout << "a - Add player" << std::endl;
    std::cout << "d - Remove player" << std::endl;
    std::cout << "u - Update player rating" << std::endl;
    std::cout << "r - Output players above a rating" << std::endl;
    std::cout << "o - Output roster" << std::endl;
    std::cout << "q - Quit" << std::endl;
    std::cout << std::endl;
}

void DisplayRoster(std::vector<int> playerNums, std::vector<int> playerRatings) {
    std::cout << "ROSTER" << std::endl;
    for (int i = 0; i < playerNums.size(); ++i) {
        std::cout << "Player " << (i + 1) << " -- Jersey number: " << playerNums.at(i)
            << ", Rating: " << playerRatings.at(i) << std::endl;
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> playerNums;
    std::vector<int> playerRatings;
    std::string userInput;

    // specification asks for 5 initial populations (for some reason...)
    // loop to grab 5 player inputs
    for (int i = 1; i <= 5; ++i) {
        // enter players jersey number
        std::printf("Enter player %i's jersey number: ", i);
        int playerNum = 0;
        std::cin >> playerNum;
        std::cout << std::endl; // zybooks mimic enter key
        playerNums.push_back(playerNum);

        // enter players rating
        std::printf("Enter player %i's rating: ", i);
        int playerRating;
        std::cin >> playerRating;
        std::cout << std::endl; // zybooks mimic enter key
        playerRatings.push_back(playerRating);
    }

    DisplayRoster(playerNums, playerRatings);

    // main program loop
    bool isRunning = true;
    char menuChoice = '\0';
    while (isRunning) {
        DisplayMenu();
        menuChoice = '\0';
        std::cout << "Choose an option: ";
        std::cin >> menuChoice;
        std::cout << std::endl; // zybooks mimic enter

        // runs specific commands based off of the letter user inputs
        int playerNum = 0;
        int playerRating = 0;
        int playerNewRating = 0;
        int playerIndex = 0;
        int minRating = 0;
        switch (menuChoice) { // .at(0) because
        case 'a': // add a new player
            std::cout << "Enter another player's jersey number: ";
            std::cin >> playerNum;
            std::cout << std::endl; // zybooks mimic enter

            playerNums.push_back(playerNum);

            std::cout << "Enter another player's rating: ";
            std::cin >> playerRating;
            std::cout << std::endl; // zybooks mimic enter

            playerRatings.push_back(playerRating);

            break;

        case 'd': // delete a player
            std::cout << "Enter a jersey number: ";
            std::cin >> playerNum;
            std::cout << std::endl; // zybooks mimic enter

            for (playerIndex = 0; playerIndex < playerNums.size(); ++playerIndex) {
                if (playerNums.at(playerIndex) == playerNum) {
                    break;
                }
            }

            playerNums.erase(playerNums.begin() + playerIndex);
            playerRatings.erase(playerRatings.begin() + playerIndex);

            break;

        case 'u': // update player rating
            std::cout << "Enter a jersey number: ";
            std::cin >> playerNum;
            std::cout << std::endl; // zybooks mimic enter

            std::cout << "Enter a new rating for player: ";
            std::cin >> playerNewRating;
            std::cout << std::endl; // zybooks mimc enter

            for (playerIndex = 0; playerIndex < playerNums.size(); ++playerIndex) {
                if (playerNums.at(playerIndex) == playerNum) {
                    break;
                }
            }

            playerRatings.at(playerIndex) = playerNewRating;

            break;

        case 'r': // output players above a rating
            std::cout << "Enter a rating: ";
            std::cin >> minRating;
            std::cout << std::endl; // zybooks mimic enter

            std::cout << "ABOVE " << minRating << std::endl;
            for (int i = 0; i < playerNums.size(); ++i) {
                if (playerRatings.at(i) > minRating) {
                    std::cout << "Player " << (i + 1) << " -- Jersey number: " << playerNums.at(i)
                        << ", Rating: " << playerRatings.at(i) << std::endl;
                }
            }

            break;

        case 'o': // output entire roster
            DisplayRoster(playerNums, playerRatings);
            
            break;

        case 'q': // quit the program
            isRunning = false;
        }
    }

    // pause before exiting
    system("read");
    return 0;
}