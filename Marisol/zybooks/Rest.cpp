#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <sstream>

using namespace std;

const int NOT_FOUND = -1; 


int FindRestuarantInVector (vector <string> &resturantNames, string findResturant){
    for (unsigned int i = 0; i < resturantNames.size(); ++i){
        if (resturantNames.at(i) == findResturant){
            return i;
        }
    }
    return NOT_FOUND;
}

void AddRestuarant (vector <string> &restuarantNames){
    string restuarantName;
    int restaurantLocationInVector = NOT_FOUND;
    cout << "What is the name of the restaurant you want to add?" << endl;
    getline(cin,restuarantName);
    restaurantLocationInVector = FindRestuarantInVector(restuarantNames, restuarantName);
    if (restaurantLocationInVector == NOT_FOUND){
        restuarantNames.push_back(restuarantName);
        cout << restuarantName << " has been added."<< endl;
    }
    else {
        cout << "That restaurant is already in the list, you can not add it again." << endl;
    }
}

void DisplayResturant(const vector <string> &restuarantNames){
    cout << "Here are the current restaurants:" << endl;
    for (int i = 0; i < restuarantNames.size(); ++i) {
        cout << "\t" << "\"" << "poop" << "\"" << endl;
    }
}


//Function to get input
    string GetUserInput(string prompt="") {
        // optional prompt output
        if (prompt != "") {
            cout << prompt;
        }

        // get the input
        string userInput;
        getline(cin, userInput);
        cout << endl;

        // return the inputted line
        return userInput;
    } 

//Error check Function
    bool ErrorDefault(int num){
        return true;
    }

//Get input int
    int GetUserInputNum(string inputPrompt="", string errorPrompt="",
                        bool errorCheck(int)=ErrorDefault){
        int userInput;
        string clearString;

        cout << inputPrompt;
        cin  >> userInput;
        cout << endl;

        while (cin.fail()|| !errorCheck(userInput)){
            cout << errorPrompt << endl;
            cin.clear();
            getline(cin,clearString);

            //get new input
            cout << inputPrompt;
            cin  >> userInput;
            cout << endl;
        }

        getline(cin,clearString);
        return userInput;

    }
//error check int > 0
    bool ErrorIntAboveZero(int num){
        return (num > 0);
    }

//error check int one or two
    bool ErrorIntRasiedTwo(int num){
        int newNum = (int) log2(num);
        return (newNum == log2(num));
    }

//test unit
    bool PowOfTwo (int numToBeChecked){
        return ErrorIntRasiedTwo(numToBeChecked);
    }

//Check if int is one or two
    bool ErrorIntOneorTwo(int num){
        return (num == 1 || num == 2);
    }


//void print menu
    void PrintMenu(){
        cout << "Please select one of the following options:"      << endl;
        cout << endl;
        cout << "quit - Quit the program"                      << endl;
        cout << "display - Display all restaurants"                << endl;
        cout << "add - Add a restaurant"                           << endl;
        cout << "remove - Remove a restaurant"                     << endl;
        cout << "cut - \"Cut\" the list of restaurants"            << endl;
        cout << "shuffle - \"Shuffle\" the list of restaurants"    << endl;
        cout << "battle - Begin the tournament"                    << endl;
        cout << "options - Print the options menu"                 << endl;
    }



//Menu selection
	bool MenuSelection(string userSelection) {
	  vector <string> restuarantNames;
      // quit
        if (userSelection == "quit"){
            cout << "Goodbye!" << endl;
            return false;
        } 
      // display
        else if (userSelection == "display"){
            DisplayResturant(restuarantNames);
        }
      // options
        else if (userSelection == "options"){
            PrintMenu();
        }
      // add restaurant to list
        else if (userSelection == "add"){
            AddRestuarant (restuarantNames);
        }
      //Invaild Input 
        else {
        cout << "Invalid Selection" << endl;
        PrintMenu();
        }

}





int main(){
 bool programRunning = true;
 string userSelection;
 vector <string> restuarantNames;
 const int RANDOM_SEED = 42;
 srand(RANDOM_SEED);

    cout << "Welcome to the restaurant battle!" << "  Enter \"options\" to see options." << endl;
    cout << endl;
    
    while (programRunning == true){
        userSelection = GetUserInput("Enter your selection: ");
        cout << endl;

        programRunning = MenuSelection(userSelection);
        
    }

    return 0;
}