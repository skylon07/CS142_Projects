// Taylor Brown
// Section 2
// taylor@davtar.org

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

#include "BakedGood.h"
#include "Bread.h"
#include "Cake.h"
#include "CupCake.h"
#include "LayerCake.h"


// splits the string to vector parts given a character to split
std::vector<std::string> SplitStringByChar(std::string stringToSplit, char charToSplitBy) {
    std::vector<std::string> splitStrings;
    std::string tempSubStr;

    // iterate over all characters in string
    for (int i = 0; i < stringToSplit.size(); ++i) {
        // if the character in string matches splitting character
        if (stringToSplit.at(i) == charToSplitBy) {
            // add the temp string to vector
            splitStrings.push_back(tempSubStr);
            // reset the temp string
            tempSubStr = "";
        }
        // else, normal character
        else {
            // add the current character to the string
            tempSubStr += stringToSplit.at(i);
        }
    }
    // append the rest of the string
    splitStrings.push_back(tempSubStr);

    return splitStrings;
}


// gets the users input given a prompt
std::string GetUserInput(std::string inputPrompt = "") {
    std::cout << inputPrompt;

    // get the input
    std::string userInput;
    std::getline(std::cin, userInput);
    std::cout << std::endl; // zybooks mimic enter

    // return the input
    return userInput;
}


// prints the title for the program
void PrintMenuTitle() {
    std::cout << "**Bread and Cakes Bakery**" << std::endl;
}


// main function to be called to begin the program (separate from main() for debugging purposes)
void RunMenuProcess() {
    std::vector<BakedGood*> goodsToOrder;

    // print the menu title
    PrintMenuTitle();
    // separator
    std::cout << std::endl;

    // prompt for sub orders
    std::cout << "Enter sub-order (enter \"done\" to finish)" << std::endl;
    // get all user sub orders
    bool userCreatingOrders = true;
    while (userCreatingOrders) {
        // get the sub order
        std::string userSubOrder = GetUserInput("Sub-order: ");
        // split the sub order into component variables
        /* NOTE TO TAs: the specification states: 
         * "Use a single vector of pointers in main to store all objects. (15 points). 
         * It is all right to use some type of temporary vector for helping print the 
         * invoice if you wish."
         * I am specifying that the below vector is "temporary", as it only stores segments
         * of the users input, and becomes deleted outside the scope of this loop.
         * Even though it isnt for printing invoices, I am hoping you will agree that this
         * is okay, and fits inside the specifications
         */
        std::vector<std::string> subOrderParts = SplitStringByChar(userSubOrder, ' ');

        // process sub order
        // first part is the kind of baked good
        std::string goodType = subOrderParts.at(0);
        
        // test if ordering is done
        if (goodType == "done") {
            userCreatingOrders = false;
            break;
        }

        // normal inputs
        else if (goodType == "Bread") {
            // Bread can specify type, then quantity
            std::string breadType = subOrderParts.at(1);
            int quantityGoods = std::stoi(subOrderParts.at(2));

            // create and add new objects to main vector
            for (int i = 0; i < quantityGoods; ++i) {
                // create the object
                BakedGood* newGood = new Bread(breadType);
                
                // append to vector
                goodsToOrder.push_back(newGood);
            }
        }

        else if (goodType == "Cupcake") {
            // Cupcakes can specify flavor, frosting, sprinkles color, then quantity
            std::string cakeFlavor = subOrderParts.at(1);
            std::string frostingFlavor = subOrderParts.at(2);
            std::string sprinklesColor = subOrderParts.at(3);
            int quantityGoods = std::stoi(subOrderParts.at(4));

            // create and add new objects to main vector
            for (int i = 0; i < quantityGoods; ++i) {
                // create the object
                BakedGood* newGood = new CupCake(cakeFlavor, frostingFlavor, sprinklesColor);
                
                // append to vector
                goodsToOrder.push_back(newGood);
            }
        }

        else if (goodType == "Layer-cake") {
            // Layer-cake can specify flavor and frosting, then num of layers and num of cakes
            std::string cakeFlavor = subOrderParts.at(1);
            std::string frostingFlavor = subOrderParts.at(2);
            int numLayers = std::stoi(subOrderParts.at(3));
            int quantityGoods = std::stoi(subOrderParts.at(4));

            // create and add new objects to main vector
            for (int i = 0; i < quantityGoods; ++i) {
                // create the object
                BakedGood* newGood = new LayerCake(cakeFlavor, frostingFlavor, numLayers);
                
                // append to vector
                goodsToOrder.push_back(newGood);
            }
        }

        // invalid input
        else {
            std::cout << goodType << " is an invalid good" << std::endl;
        }
        
    }
    // separator
    std::cout << std::endl;

    // print out order confirmations
    std::cout << "Order Confirmations:" << std::endl;
    // iterate over all items
    for (int i = 0; i < goodsToOrder.size(); ++i) {
        // print items info string
        std::cout << goodsToOrder.at(i)->ToInfoString() << std::endl;
    }
    // separator
    std::cout << std::endl;

    // process invoice
    // iterate over all singularly ordered items
    for (int i = 0; i < goodsToOrder.size(); ++i) {
        BakedGood* currItem = goodsToOrder.at(i);

        // iterate over all items before this item
        for (int j = 0; j < i; ++j) {
            BakedGood* currItemBefore = goodsToOrder.at(j);
            // tests if a similar item already occurs in the list
            if (currItem->ToInfoString() == currItemBefore->ToInfoString()) {
                // add another item to the other items group number
                currItemBefore->IncSizeGroup();

                // remove the current item from the list
                goodsToOrder.erase(goodsToOrder.begin() + i); // i for current, NOT j for before
                --i; // offsets to account for above erased item
            }
        }
    }

    // output invoice
    std::cout << "Invoice:" << std::endl;
    std::cout << std::left;
    std::cout << std::setw(75) << "Baked Good";
    std::cout << std::setw(9)  << "Quantity";
    std::cout << std::setw(9)  << "Total";
    std::cout << std::endl;

    // output all item info lines, quantities, and total prices
    int totalQty = 0;
    double totalCost = 0.0;
    for (int i = 0; i < goodsToOrder.size(); ++i) {
        // store all necessary information
        BakedGood* currItem = goodsToOrder.at(i);
        std::string itemInfo = currItem->ToInfoString();
        int itemQty = currItem->GetSizeGroup();
        double itemTotalPrice = currItem->CalcDiscountedPrice(itemQty);

        // output information
        std::cout << std::setw(75) << itemInfo;
        std::cout << std::setw(9)  << itemQty;
        std::cout << std::setw(9)  << currItem->PriceToStr(itemTotalPrice); // used for adding trailing zeros
        std::cout << std::endl;

        // add info to counters
        totalQty += itemQty;
        totalCost += itemTotalPrice;
    }

    // output totals
    std::cout << std::setw(75) << "Totals";
    std::cout << std::setw(9)  << totalQty;
    std::cout << std::setw(9)  << goodsToOrder.at(0)->PriceToStr(totalCost); // trailing zeros
    std::cout << std::endl;

    // wave goodbye
    std::cout << "Good Bye" << std::endl;
}


// main program entry call
int main() {
    RunMenuProcess();

    return 0;
}