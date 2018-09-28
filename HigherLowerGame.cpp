#include <iostream>
#include <chrono>
#include <thread>

int RandInt(int low, int high) {
    int randNum = rand() % (1 + high - low); // get it inside the range difference
    return randNum + low; // shift the range to the right place
}

void SleepFor(int milliseconds) {
    std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
}

void ComputerChooses(const int MAX_NUMBER, const int MAX_GUESSES) {
    int answerNum = 0;
    int userGuess = 0;
    int guessCount = 0;

    answerNum = RandInt(0, MAX_NUMBER);

    std::cout << "I have chosen a number between 0 and " << MAX_NUMBER << std::endl;

    // main guess loop
    while (userGuess != answerNum) {
        std::cout << "Guess a number (" << MAX_GUESSES - guessCount << " left): ";
        std::cin >> userGuess;
        guessCount += 1;

        // compare guess with answer number
        if (userGuess < answerNum) {
            std::cout << "Thats too low" << std::endl;
        }
        else if (userGuess > answerNum) {
            std::cout << "Thats too high" << std::endl;
        }
        else {
            std::cout << "Spot on! Youre a genius!" << std::endl;
            break;
        }

        // test if guesses ran out
        if (guessCount == MAX_GUESSES) {
            std::cout << "You ran out of guesses!" << std::endl;
        }

    }
}

void ComputerGuesses(const int MAX_NUMBER, const int MAX_GUESSES, int smartsEnabled) {
    int userNum = 0;
    int computerGuess = 0;
    int guessLow = 0;
    int guessHigh = MAX_NUMBER;
    int guessCount = 0;
    const int SLEEP_TIME_MIN = 430;
    const int SLEEP_TIME_MAX = 770;

    std::cout << "Enter a number for me to guess (0-" << MAX_NUMBER << "): ";
    std::cin >> userNum;

    std::cout << "I will attempt to guess your number..." << std::endl;

    // main guess loop
    bool didGuess = false;
    while (computerGuess != userNum || not didGuess) {
        // if smarts is enabled, use binary searching, otherwise choose (reasonably) randomly
        computerGuess = (smartsEnabled) ? 
            (guessHigh - guessLow) / 2 + guessLow : RandInt(guessLow, guessHigh);
        std::cout << "Guess " << guessCount + 1 << ":" << computerGuess;
        guessCount += 1;

        // test where the guess is compared with the user number
        if (computerGuess < userNum) {
            std::cout << "... Thats too low" << std::endl;
            guessLow = computerGuess;
        }
        else if (computerGuess > userNum) {
            std::cout << "... Thats too high" << std::endl;
            guessHigh = computerGuess;
        }
        else {
            std::cout << "... I win!!!" << std::endl;
            break;
        }

        // terminate if guesses are out
        if (guessCount == MAX_GUESSES) {
            std::cout << "I ran out of guesses. You win!" << std::endl;
            break;
        }

        // sleep for non-instant calculations
        SleepFor(RandInt(SLEEP_TIME_MIN, SLEEP_TIME_MAX));

    }
}

void RunMenu() {
    int userChoice = 0;
    const int MAX_NUMBER = 1000000;
    const int MAX_GUESSES = 20;
    
    srand(time(0)); // seed with current epoch time

    // get input for who chooses
    std::cout << "Who guesses the number? Enter 1 for me, 0 for you: ";
    std::cin >> userChoice;

    // run coresponding function (and options)
    if (userChoice == 1) {
        std::cout << "Smart mode (1), or Random mode (0): ";
        std::cin >> userChoice;

        ComputerGuesses(MAX_NUMBER, MAX_GUESSES, userChoice);
    }
    else {
        ComputerChooses(MAX_NUMBER, MAX_GUESSES);
    }
}

int main() {
    RunMenu();
    
    return 0;
}