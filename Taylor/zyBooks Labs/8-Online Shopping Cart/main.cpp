#include <iostream>

#include "ShoppingCart.h"
#include "ItemToPurchase.h"


// gets the user input and returns it as a string, printint inputPrompt first (if any)
std::string GetUserInput(std::string inputPrompt="") {
    // output optional prompt
    std::cout << inputPrompt;
    
    // get input
    std::string userInput;
    std::getline(std::cin, userInput);
    std::cout << std::endl; // zybooks mimic enter

    // return the input
    return userInput;
}


// displays the menu function options
void DisplayOptionsMenu() {
    std::cout << "MENU"                                         << std::endl;
    std::cout << "add - Add item to cart"                       << std::endl;
    std::cout << "remove - Remove item from cart"               << std::endl;
    std::cout << "change - Change item quantity"                << std::endl;
    std::cout << "descriptions - Output items' descriptions"    << std::endl;
    std::cout << "cart - Output shopping cart"                  << std::endl;
    std::cout << "options - Print the options menu"             << std::endl;
    std::cout << "quit - Quit"                                  << std::endl;
}


// gets input and adds an item to the menu list
void MenuAddItem(ShoppingCart& activeCart) {
    // temporary variables to construct an ItemToPurchase
    std::string itemName;
    std::string itemDescription;
    double itemPrice = 0.0;
    int itemQty = 0;

    // get the item's attributes from the user
    std::cout << "Enter the item name: ";
    std::getline(std::cin, itemName);
    std::cout << std::endl; // zybooks mimic enter

    std::cout << "Enter the item description: ";
    std::getline(std::cin, itemDescription);
    std::cout << std::endl; // zybooks mimic enter

    std::cout << "Enter the item price: ";
    std::cin >> itemPrice;
    std::cout << std::endl; // zybooks mimic enter

    std::cout << "Enter the item quantity: ";
    std::cin >> itemQty;
    std::cin.ignore(); // ignore trailing '\n' for getline()s later
    std::cout << std::endl; // zybooks mimic enter

    // create the new item object
    ItemToPurchase newItem(itemName, itemDescription, itemPrice, itemQty);

    // append the new item object to activeCart
    activeCart.AddItemToCart(newItem);
}

// removes an item given the input
void MenuRemoveItem(ShoppingCart& activeCart) {
    std::string targetName;
    
    // get the user input
    std::cout << "Enter name of the item to remove: ";
    std::getline(std::cin, targetName);
    std::cout << std::endl; // zybooks mimic enter

    // remove the item from the shopping cart
    activeCart.RemoveItemFromCartByName(targetName);
}

// changes an items quantity given its name
void MenuChangeItemQty(ShoppingCart& activeCart) {
    std::string targetName;
    int newQty = 0;

    // get the name of the item
    std::cout << "Enter the item name: ";
    std::getline(std::cin, targetName);
    std::cout << std::endl; // zybooks mimic enter

    // get the new quantity
    std::cout << "Enter the new quantity: ";
    std::cin >> newQty;
    std::cin.ignore(); // ignore trailing '\n' for future calls to getline()
    std::cout << std::endl; // zybooks mimic enter

    // make the changes to the item in the cart
    activeCart.UpdateItemQtyByName(targetName, newQty);
}

// prints out the active carts items and their descriptions
void MenuPrintItemsAndDescriptions(const ShoppingCart& activeCart) {
    activeCart.PrintAllItemsAndDescriptions();
    // separate from next output
    std::cout << std::endl;
}

// prints out the shopping carts items, qtys, prices, and totals
// - cant have const here for using .at in the function, couldnt find workaround
void MenuPrintItemsAndInfo(ShoppingCart& activeCart) {
    activeCart.PrintAllItemsCostAndQty();
    // separate from next output
    std::cout << std::endl;
}

// processes a menu selection, returns if program exits or not
// - NOTE: no error checking (specs say it isnt required)
bool ProcessMenuSelection(std::string userSelection, ShoppingCart& activeCart) {
    // add an item to the cart
    if (userSelection == "add") {
        MenuAddItem(activeCart);
    }

    // remove an item from the cart
    else if (userSelection == "remove") {
        MenuRemoveItem(activeCart);
    }

    // change item quantity
    else if (userSelection == "change") {
        MenuChangeItemQty(activeCart);
    }

    // output item descriptions in the cart
    else if (userSelection == "descriptions") {
        MenuPrintItemsAndDescriptions(activeCart);
    }

    // outputs the shopping cart (items, qtys, prices, totals)
    else if (userSelection == "cart") {
        MenuPrintItemsAndInfo(activeCart);
    }

    // display the available options
    else if (userSelection == "options") {
        // display menu
        DisplayOptionsMenu();

        // separate from next output
        std::cout << std::endl;
    }

    // quit the program
    else if (userSelection == "quit") {
        // output message
        std::cout << "Goodbye." << std::endl;

        // tell calling function to exit
        return true;
    }

    // invalid input (YOU SAID YOU WOULDNT TEST)
    else {
        // display the menu
        DisplayOptionsMenu();

        // separate from next output
        std::cout << std::endl;
    }

    // keep the program running
    return false;
}


// main program entry
int main() {
    // get the users/customers name
    std::string userName = GetUserInput("Enter Customer's Name: ");
    // get the date
    std::string currDate = GetUserInput("Enter Today's Date: ");
    // separater
    std::cout << std::endl;

    // construct shopping cart
    ShoppingCart userCart(userName, currDate);

    // repeatedly process the users inputs
    bool programIsRunning = true;
    while (programIsRunning) {
        // variables needed by loop
        static std::string userOption;

        // get the menu selection option
        userOption = GetUserInput("Enter option: ");
        
        // determine the correct action to take
        programIsRunning = !ProcessMenuSelection(userOption, userCart);
    }

    return 0;
}