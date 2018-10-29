// Taylor Brown
// Section 2
// taylor@davtar.org

/* TEST CASES

Case 1: input adds McDonalds, Culvers, Taco Bell, and La Fountain
 - Display displays correct output
 - removing and adding McDonalds again works correctly (moves it)
 - Actually calling move function works

Case 2: input adds test1, test2, test3, test4, test5, and test6
 - trying to battle fails, as expected
 - adding test7 and test8 gets battle to work again

Case 3: input adds Culvers, McDonalds, Wendeys, La Fountain, Taco Bell, Del Taco,
        Mod Pizza, and Dennys
 - inputting battle (1 or 2) didnt work as expected (off by one error)
 - ran into a problem where error checking text in cutting broke the program, fixed
    by introducing another while loop to check for bounds outside of GetUserInputInt()
*/


#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <sstream>


// returns a line of the users input
std::string GetUserInput(std::string prompt="") {
    // output optional prompt
    if (prompt != "") {
        std::cout << prompt;
    }

    // get the input
    std::string userInput;
    std::getline(std::cin, userInput);
    std::cout << std::endl; // zybooks mimic enter
    
    // return the inputted line
    return userInput;
}

// default error check function (always returns true)
bool ErrorCheckDefault(int number) {
    return true;
}
// gets the user input, forcing it to be an integer
int GetUserInputInt(std::string inputPrompt="", std::string errorPrompt="",
                    bool errorCheck(int)=ErrorCheckDefault) {
	int userInput;
    std::string trashString; // used to clear cin buffer

	// get input
	std::cout << inputPrompt;
	std::cin >> userInput;
	std::cout << std::endl; // simulate return key for zyBooks

	// test for userInput validity
	while (std::cin.fail() || !errorCheck(userInput)) {
		// print error prompt and clear cin buffer
		std::cout << errorPrompt << std::endl;
		std::cin.clear(); // clear error flags
		std::getline(std::cin, trashString); // reset buffer

		// get input again
		std::cout << inputPrompt;
		std::cin >> userInput;
		std::cout << std::endl; // simulate return key for zyBooks
	}

    // reset buffer
    getline(std::cin, trashString);
	
	// return validated userInput
	return userInput;
}

// error checking functions that can be passed into GetUserInputInt
// - test for good input, ie returning false means there was an error
bool ErrorCheckIntAboveZero(int number) {
    return (number > 0);
}
bool ErrorCheckIntPowerOfTwo(int number) {
    // returns if log2 was whole or not
    int intNum = (int) std::log2(number);
    // implicitly converts intnum into a double again, losing the decimal data
    return (intNum == std::log2(number));
}
// unit test in zybooks
bool PowerOfTwo(int numberToCheck) {
    return ErrorCheckIntPowerOfTwo(numberToCheck);
}
bool ErrorCheckIntOneOrTwo(int number) {
    return (number == 1 || number == 2);
}


// a class that handles data for a restaurant
class Restaurant {
    public:
    // constructor with optional name
    Restaurant(std::string name="<No Name>") {
        SetName(name);
    }

    // returns the name of the restaurant
    std::string GetName() {
        return restaurantName;
    }
    // sets the name of the restaurant
    void SetName(std::string newName) {
        restaurantName = newName;
    }

    private:
    std::string restaurantName; // the name of the restaurant
};

// a class that contains restaurants as well as manipulators for them
class RestaurantArena {
    public:
    RestaurantArena() {} // default constructor does nothing

    // returns the restaurants location in the array given the name
    int FindRestaurantIdxFromName(std::string targetName);

    // function that adds a restaurant to the list
    void AddRestaurantToList(Restaurant newRestaurant);
    // function that removes a restaurant from a list
    void RemoveRestaurantFromList(std::string targetName);

    // function that moves a restaurant to a new index
    void MoveRestaurantInList(std::string targetName, int newIdx);

    // function that cuts the list of restaurants and restacks them given a starting position
    void CutList(int startPos);

    // function that changes restaurant order by alternating from two halves
    void ShuffleList();

    // outputs the restaurants
    void OutputRestaurants();

    // returns size of the main list
    int GetMainListSize();    

    // begins the battle process
    void BeginRestaurantBattle();

    private:
    std::vector<Restaurant> restaurantList; // main list for containing restaurant data

    // function that splits the main list into two halves given an index
    //  - note that firstPart and secondPart must be EMPTY upon calling this function
    void SplitListTwoParts(int splitIdx, std::vector<Restaurant>& firstPart,
                           std::vector<Restaurant>& secondPart);

    // returns a group of two contenders given a match offset number
    std::vector<Restaurant> GetBattleContenders(std::vector<Restaurant> currContenders, int matchNum);

    // gets input and returns the victor of an individual battle result
    Restaurant CompleteBattle(std::vector<Restaurant> contenderPair);

    // runs getting individual battle inputs in a loop, and returns the victors
    std::vector<Restaurant> CompleteRoundSequence(std::vector<Restaurant> contenders);
};

int RestaurantArena::FindRestaurantIdxFromName(std::string targetName) {
    for (int i = 0; i < restaurantList.size(); ++i) {
        if (restaurantList.at(i).GetName() == targetName) {
            return i;
        }
    }
    // name not found
    return -1;
}

void RestaurantArena::AddRestaurantToList(Restaurant newRestaurant) {
    int newRestaurantIdx = FindRestaurantIdxFromName(newRestaurant.GetName());
    // if the restaurant is already in the list, dont add it again
    if (newRestaurantIdx != -1) {
        std::cout << "That restaurant is already in the list, you can not add it again." << std::endl;
    }
    // valid input, add it
    else {
        restaurantList.push_back(newRestaurant);
    }
}
void RestaurantArena::RemoveRestaurantFromList(std::string targetName) {
    int targetIdx = FindRestaurantIdxFromName(targetName);
    restaurantList.erase(restaurantList.begin() + targetIdx);
}

void RestaurantArena::MoveRestaurantInList(std::string targetName, int newIdx) {
    int currIdx = FindRestaurantIdxFromName(targetName);
    // temporary save to move later
    Restaurant targetRestaurant = restaurantList.at(currIdx);
    RemoveRestaurantFromList(targetName);
    // add it back in
    restaurantList.insert(restaurantList.begin() + newIdx, targetRestaurant);
}

void RestaurantArena::SplitListTwoParts(int splitIdx, std::vector<Restaurant>& firstPart,
                                        std::vector<Restaurant>& secondPart) {
    // push back to the first list, up to the index
    for (int i = 0; i < splitIdx; ++i) {
        firstPart.push_back(restaurantList.at(i));
    }
    // push back the rest of the values to the second part
    for (int i = splitIdx; i < restaurantList.size(); ++i) {
        secondPart.push_back(restaurantList.at(i));
    }
}

void RestaurantArena::CutList(int startPos) {
    std::vector<Restaurant> firstPart;
    std::vector<Restaurant> secondPart;
    
    // split main list into two parts
    SplitListTwoParts(startPos, firstPart, secondPart);

    // add the lists back, but in reverse order
    for (int i = 0; i < secondPart.size(); ++i) {
        restaurantList.at(i) = secondPart.at(i);
    }
    for (int i = 0; i < firstPart.size(); ++i) {
        restaurantList.at(i + secondPart.size()) = firstPart.at(i);
    }
}

void RestaurantArena::ShuffleList() {
    std::vector<Restaurant> firstHalf;
    std::vector<Restaurant> secondHalf;

    // check if the vector size is not a power of 2
    if (!ErrorCheckIntPowerOfTwo(GetMainListSize())) {
        std::cout << "The current tournament size (" << GetMainListSize() 
            << ") is not a power of two (2, 4, 8...)." << std::endl;
        std::cout << "A shuffle is not possible. Please add or remove restaurants." 
            << std::endl;
        return;
    }

    // split the main list into two halves
    //  - note that if the number of elements is odd, secondHalf will be bigger
    SplitListTwoParts(restaurantList.size() / 2, firstHalf, secondHalf);

    /*
    // in the case the size is odd, set the middle element to firstHalf
    // - firstHalf must be larget or equal to the second half
    if (restaurantList.size() % 2 == 1) {
        firstHalf.push_back(secondHalf.at(0));
        // removes the first element of second half
        secondHalf.erase(secondHalf.begin());
    }
    */

    // restack the main list to alternating contents of firstHalf and secondHalf
    for(int i = 0; i < restaurantList.size(); ++i) {
        // add secondHalf if i is even
        if (i % 2 == 0) {
            // must be i / 2 because indeces of the halves dont match up with the main list
            restaurantList.at(i) = secondHalf.at(i / 2);
        }
        // i is odd, add firstHalf
        else {
            restaurantList.at(i) = firstHalf.at(i / 2);
        }
    }
}

void RestaurantArena::OutputRestaurants() {
    std::cout << "Here are the current restaurants: " << std::endl;
    std::cout << std::endl;

    // prints all restaurant names (tabbed over and in quotes)
    for (int i = 0; i < restaurantList.size(); ++i) {
        std::cout << "\t" << "\"" << restaurantList.at(i).GetName() << "\"" << std::endl;
    }

    std::cout << std::endl; // separates from next print
}

int RestaurantArena::GetMainListSize() {
    return restaurantList.size();
}

void RestaurantArena::BeginRestaurantBattle() {
    // check if the vector size is not a power of 2
    if (!ErrorCheckIntPowerOfTwo(GetMainListSize())) {
        std::cout << "The current tournament size (" << GetMainListSize() 
            << ") is not a power of two (2, 4, 8...)." << std::endl;
        std::cout << "A battle is not possible. Please add or remove restaurants." 
            << std::endl;
    }
    else {
        std::vector<Restaurant> currContenders = restaurantList;
        // go through the rounds
        // - log2(size()) is the total number of rounds
        // - log2(size()) is guaranteed to be whole power of 2 because of above if block
        for (int rnd = 1; rnd <= std::log2(restaurantList.size()); ++rnd) {
            // print the round
            std::cout << "Round: " << rnd << std::endl;
            std::cout << std::endl;
            // complete the round and update the contenders
            currContenders = CompleteRoundSequence(currContenders);
            // separate from next round
            std::cout << std::endl;
        }

        // print the winner
        std::cout << "The winning restaurant is " << currContenders.at(0).GetName() 
            << "." << std::endl;
        std::cout << std::endl;
    }
}

std::vector<Restaurant> RestaurantArena::GetBattleContenders(std::vector<Restaurant> currContenders, int matchNum) {
    // generate the list of two contenders
    std::vector<Restaurant> contenderList = {
        currContenders.at(matchNum * 2),
        currContenders.at((matchNum * 2) + 1)
        };

    // return the list
    return contenderList;
}

std::vector<Restaurant> RestaurantArena::CompleteRoundSequence(std::vector<Restaurant> contenders) {
    std::vector<Restaurant> restaurantVictors;
    Restaurant currVictor;
    // run over every duel sequence
    for (int battle = 0; battle < (contenders.size() / 2); ++battle) {
        // complete the battle with the contender pair
        currVictor = CompleteBattle(GetBattleContenders(contenders, battle));
        // add the victor to the list of victors
        restaurantVictors.push_back(currVictor);
    }

    // return the victors
    return restaurantVictors;
}

Restaurant RestaurantArena::CompleteBattle(std::vector<Restaurant> contenderPair) {
    int userChoice = 0;
    std::stringstream inputPromptSStream;

    // print the two contenders
    inputPromptSStream << "Type \"1\" if you prefer " << contenderPair.at(0).GetName() << " or" << std::endl;
    inputPromptSStream << "type \"2\" if you prefer " << contenderPair.at(1).GetName()          << std::endl;
    inputPromptSStream << "Choice: ";
    
    // get the user choice, and validate it is 1 or 2
    userChoice = GetUserInputInt(inputPromptSStream.str(), "Invalid choice", ErrorCheckIntOneOrTwo);

    // return the user's victor
    Restaurant victor = contenderPair.at(userChoice - 1);
    return victor;
}




// prints the available options
void PrintMenuSelectionOptions() {
    std::cout << "Please select one of the following options:"      << std::endl;
    std::cout << std::endl;
    std::cout << "quit - Quit the program"                          << std::endl;
    std::cout << "display - Display all restaurants"                << std::endl;
    std::cout << "add - Add a restaurant"                           << std::endl;
    std::cout << "remove - Remove a restaurant"                     << std::endl;
    std::cout << "cut - \"Cut\" the list of restaurants"            << std::endl;
    std::cout << "shuffle - \"Shuffle\" the list of restaurants"    << std::endl;
    std::cout << "battle - Begin the tournament"                    << std::endl;
    std::cout << "options - Print the options menu"                 << std::endl;
    std::cout << std::endl;
}

// handles a menu selection
//  - returns (if the program should terminate)
//  - MAY EDIT original arena, depending on user selection
bool ProcessMenuSelection(std::string userSelection, RestaurantArena& arena) {
    std::string userInput;
    int userInputInt = 0;


    // quit program entirely
    if (userSelection == "quit") {
        return true;
    }

    // show the options menu
    else if (userSelection == "options") {
        PrintMenuSelectionOptions();
    }

    // display all restaurants
    else if (userSelection == "display") {
        arena.OutputRestaurants();
    }

    // add a restaurant to the list
    else if (userSelection == "add") {
        // get the name of the restaurant
        userInput = GetUserInput("What is the name of the restaurant you want to add?\n");

        if (arena.FindRestaurantIdxFromName(userInput) != -1) {
            std::cout << "That restaurant is already on the list, you can not add it again." << std::endl;
        }
        // valid input, add it
        else {
            arena.AddRestaurantToList(Restaurant(userInput));

            // display confirmation
            std::cout << userInput << " has been added." << std::endl;
        }
        std::cout << std::endl; // separate from next prompt
    }

    // remove a restaurant from the list
    else if (userSelection == "remove") {
        // get the name of the restaurant
        userInput = GetUserInput("What is the name of the restaurant you want to remove?\n");

        // if the target wasnt found
        if (arena.FindRestaurantIdxFromName(userInput) == -1) {
            std::cout << "That restaurant is not on the list, you can not remove it." << std::endl;
        }
        // valid input, remove it
        else {
            arena.RemoveRestaurantFromList(userInput);

            // display confirmation
            std::cout << userInput << " has been removed." << std::endl;
        }

        std::cout << std::endl; // separate from next prompt
    }

    // cut the list of restaurants (like a deck of cards)
    else if (userSelection == "cut") {
        std::stringstream errorSStream; // converts error string
        errorSStream << "The cut number must be between 0 and "
                << arena.GetMainListSize() << std::endl;\
        
        userInputInt = GetUserInputInt("How many restaurants should be taken"
                                       " from the top and put on the bottom? ", 
                                       errorSStream.str());
        // validate range
        while (userInputInt < 0 || userInputInt > arena.GetMainListSize()) {
            std::cout << errorSStream.str() << std::endl;
            userInputInt = GetUserInputInt("How many restaurants should be taken"
                                           " from the top and put on the bottom? ", 
                                           errorSStream.str());
        }

        // valid input, cut the list
        arena.CutList(userInputInt);
    }

    // shuffle the list of restaurants (like a deck of cards)
    else if (userSelection == "shuffle") {
        arena.ShuffleList();
    }

    else if (userSelection == "battle") {
        arena.BeginRestaurantBattle();
    }

    // invalid selection, print error and then options menu
    else {
        std::cout << "Invalid Selection" << std::endl;
        PrintMenuSelectionOptions();
    }

    // keep the program running: do not terminate
    return false;
}


// main program entry
int main() {
    // set up variables
    RestaurantArena mainBattleArrayna; // get it? Array-na?
    bool programRunning = true;

    // display title
    std::cout << "Welcome to the restaurant battle!"
        << "  Enter \"options\" to see options." << std::endl;
    std::cout << std::endl;

    // main menu loop
    std::string userSelection;
    while (programRunning) {
        // get user selection
        userSelection = GetUserInput("Enter your selection: ");
        std::cout << std::endl; // separate from next prompt

        // process the menu selection
        programRunning = !ProcessMenuSelection(userSelection, mainBattleArrayna);
    }

    // upon quitting, print goodbye
    std::cout << "Goodbye!" << std::endl;

    return 0;
}