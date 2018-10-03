#include <iostream>

int main() {
    const int NUM_ITEMS = 9;
    int testArray[NUM_ITEMS] = {6, 9, 7, 8, 2, 1, 4, 3, 5};

    for (int asdf = 0; asdf < NUM_ITEMS - 1; ++asdf) { // iterates to get all largest values
        for (int i = 0; i < NUM_ITEMS - 1; ++i) { // gets one largest value to the end
            if (testArray[i] > testArray[i+1]) { // swap numbers
                int temp = testArray[i];
                testArray[i] = testArray[i+1];
                testArray[i+1] = temp;
            }
        }
    }

    for (int i = 0; i < NUM_ITEMS; ++i) {
        std::cout << testArray[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}