#include <iostream>
#include <string>
#include <vector>

// Returns a base character given a decimal value
char GetCharFromDecimal(int decimal) {
    const std::string ALPHABET = "0123456789abcdefghijklmnopqrstuvwxyz";
    return ALPHABET.at(decimal);
}

// Returns the decimal value of a base character
int GetDecimalOfChar(char baseChar) {
    const std::string ALPHABET = "0123456789abcdefghijklmnopqrstuvwxyz";
    char letterTemp = '\0';

    // Iterate over every letter and return if the letter is baseChar
    for (int i = 0; i < sizeof(ALPHABET); i++) {
        letterTemp = ALPHABET.at(i);
        if (letterTemp == baseChar) {
            return i;
        }
    }

    return -1; // should never run; gets rid of warnings
}

// Converts a number of any base, input as a string, to a decimal integer
int ConvBaseToDec(std::string numString, int base) {
    char tempChar = '\0';
    int digitMultiple = 0;
    int numDec = 0;
    const int NUM_STRING_LENGTH = numString.length();

    // Sets digitMultiple to the highest power (base ^ numString.length())
    digitMultiple = 1;
    for (int i = 0; i < NUM_STRING_LENGTH - 1; i++) {
        digitMultiple *= base;
    }

    // Multiplies all digits together and adds them to total
    for (int i = 0; i < NUM_STRING_LENGTH; i++) {
        tempChar = numString.at(i);
        numDec += digitMultiple * GetDecimalOfChar(tempChar); // adds TOTAL number value at digit
        digitMultiple /= base; // effectively changes digits
    }

    return numDec;
}

// Converts an integer (decimal) to any base (returns a string)
std::string ConvDecToBase(int numDec, int base) {
    char tempChar = '\0';
    std::string numString = "";

    // Goes until division cant be done anymore
    while (numDec != 0) {
        tempChar = GetCharFromDecimal(numDec % base);
        numString = tempChar + numString; // Dividing from ones and up means we push to front
        numDec /= base;
    }

    return numString;
}

// Converts from one base to another
std::string ConvertNumber(std::string numOrig, int origBase, int convBase) {
    int intermediateDec = ConvBaseToDec(numOrig, origBase);
    return ConvDecToBase(intermediateDec, convBase);
}

// Splits input string by a given character
std::vector<std::string> SplitString(std::string stringOrig, char splitChar) {
    std::vector<std::string> stringSplit;
    char tempChar = '\0';
    std::string tempString = "";

    // probes every character and tests if a space
    for (int i = 0; i < stringOrig.length(); i++) {
        tempChar = stringOrig.at(i);

        // perform splitting logic
        if (tempChar == splitChar) {
            stringSplit.push_back(tempString);
            tempString = "";
        }
        // record character and repeat
        else {
            tempString += tempChar;
        }
    }

    stringSplit.push_back(tempString); // get that last part in there...
    return stringSplit;
}

// Menu logic for the Quick Mode Menu
void RunQuickModeMenu() {
    bool doRepeat = true;
    std::string userInput = "";
    std::vector<std::string> userInputSplit;
    int origBase = 0;
    int convBase = 0;
    std::string numOrig = "";

    // output terminate keywords, then initiate the main repeating loop
    std::cout << "Type \"done\", \"quit\", or \"stop\" to terminate" << std::endl;
    while (doRepeat) {
        // Input as Original base, Converted base, Number to convert
        std::cout << "(From To Num): ";
        std::getline(std::cin, userInput);

        // quits if correct keyword is inputted
        if (userInput == "quit" || userInput == "stop" || userInput == "done") {
            doRepeat = false;
        }

        // resume the calculation using the input string
        else {
            // split input and store in the variables
            userInputSplit = SplitString(userInput, ' ');
            origBase = std::stoi(userInputSplit.at(0));
            convBase = std::stoi(userInputSplit.at(1));
            numOrig = userInputSplit.at(2);

            // output the returned converted number
            std::cout << "Converted num: " << ConvertNumber(numOrig, origBase, convBase) << std::endl;
        }
    }
}

// UI that ties all functions together
void RunMenu() {
    std::string quickMode = "";
    int origBase = 0;
    int convBase = 0;
    std::string numOrig = "";

    // Quickmode is a mode that gets all three inputs at once
    // and displays the answer below, then repeats
    std::cout << "Enter \"q\" for quick mode, otherwise just hit [Enter]: ";
    std::getline(std::cin, quickMode);

    if (quickMode == "q" ) { // fast, repeated entries
        RunQuickModeMenu();
    }

    else { // detailed, single entry
        std::cout << "Enter starting base (in decimal): ";
        std::cin >> origBase;

        std::cout << "Enter base to convert to (in decimal): ";
        std::cin >> convBase;

        std::cout << "Enter the number to convert: ";
        std::cin >> numOrig;

        // Calculates and outputs results
        std::cout << numOrig << " (" << origBase << ") converted to base " << convBase << " is: "
            << ConvertNumber(numOrig, origBase, convBase) << std::endl;
    }
}

int main() {
    RunMenu();

    return 0;
}