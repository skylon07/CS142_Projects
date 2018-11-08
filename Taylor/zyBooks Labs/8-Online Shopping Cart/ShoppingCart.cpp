#include "ShoppingCart.h"


// default constructor
ShoppingCart::ShoppingCart(std::string customerName, std::string cartDate) {
    SetCustomerName(customerName);
    SetDateCreated(cartDate);
}


// adds an item to the cart
void ShoppingCart::AddItemToCart(ItemToPurchase newItem) {
    // check if the item is already in the cart
    if (FindItemInCartByName(newItem.GetItemName()) != -1) {
        std::cout << "Item is already in cart. Nothing added." << std::endl;
    }
    // item is not in cart, add it
    else {
        inCartList.push_back(newItem);
    }
}

// removes an item (by name) from the cart
void ShoppingCart::RemoveItemFromCartByName(std::string targetName) {
    // find the item with the target name
    int targetIdx = FindItemInCartByName(targetName);

    // if the item was found, erase it
    if (targetIdx != -1) {
        inCartList.erase(inCartList.begin() + targetIdx);
    }
    // item not found, print error
    else {
        std::cout << "Item not found in cart. Nothing removed." << std::endl;
    }
}

// updates the quantity of items given a target name
void ShoppingCart::UpdateItemQtyByName(std::string targetName, int newQty) {
    // find item in cart
    int targetIdx = FindItemInCartByName(targetName);

    // if the target was found, update the quantity
    if (targetIdx != -1) {
        inCartList.at(targetIdx).SetItemQty(newQty);
    }
    // if the target wasnt found, print an error
    else {
        std::cout << "Item not found in cart. Nothing modified." << std::endl;
    }
}


// returns the number of items in the cart
int ShoppingCart::GetNumItemsInCart() {
    int totalQty = 0;

    // iterate and add every items quantity
    for (int i = 0; i < GetSizeOfCart(); ++i) {
        totalQty += inCartList.at(i).GetItemQty();
    }

    return totalQty;
}

// calculates and returns the total cost of the cart
double ShoppingCart::GetTotalCostOfCart() const {
    double totalCost = 0.0;
    
    // calculate for every item
    for (int item = 0; item < GetSizeOfCart(); ++item) {
        // current item used as a temporary variable
        ItemToPurchase currItem = inCartList.at(item);

        // add (item cost * qty) to total cost
        totalCost += (currItem.GetItemPrice() * currItem.GetItemQty());
    }

    // return the total cost
    return totalCost;
}


// finds an item index given a name in the cart
int ShoppingCart::FindItemInCartByName(std::string targetName) {
    for (int item = 0; item < GetSizeOfCart(); ++item) {
        // test if the item matches the name
        if (targetName == inCartList.at(item).GetItemName()) {
            // return the item index
            return item;
        }
    }

    // item not found, so return -1
    return -1;
}


// prints the cart name and date
void ShoppingCart::PrintCartNameAndDate() const {
    std::cout << GetCustomerName() << "'s Shopping Cart - " << GetDateCreated() << std::endl;
}

// prints the total cost of all items and the total number of items
void ShoppingCart::PrintAllItemsCostAndQty() {
    // print customer name and date of the cart
    PrintCartNameAndDate();

    // if the cart size is zero, print empty message and stop the function
    if (GetSizeOfCart() == 0) {
        // print message
        std::cout << "Shopping cart is empty." << std::endl;

        // stop the function
        return;
    }

    // print number of items
    std::cout << "Number of Items: " << GetNumItemsInCart() << std::endl;
    
    // separator
    std::cout << std::endl;

    // set cout with precision and print type
    std::cout << std::setprecision(2) << std::fixed;

    // print all item costs and quantities
    for (int item = 0; item < GetSizeOfCart(); ++item) {
        // temporary variable that is the current item
        ItemToPurchase currItem = inCartList.at(item);

        // print the individual item cost and qty
        currItem.PrintItemQtyAndCost();
    }

    // separator
    std::cout << std::endl;

    // print the total cost of all items
    std::cout << "Total: $" << GetTotalCostOfCart() << std::endl;
}

// prints all item names and descriptions
void ShoppingCart::PrintAllItemsAndDescriptions() const {
    // print customer name and creation date
    PrintCartNameAndDate();
    
    // if the cart size is zero, print empty message and stop the function
    if (GetSizeOfCart() == 0) {
        // print message
        std::cout << "Shopping cart is empty." << std::endl;

        // stop the function
        return;
    }

    // separator
    std::cout << std::endl;

    // print the kind of information it is
    std::cout << "Item Descriptions" << std::endl;
    // print all item names and descriptions
    for (int item = 0; item < GetSizeOfCart(); ++item) {
        // temporary item variable
        ItemToPurchase currItem = inCartList.at(item);

        // print the item name and description
        currItem.PrintItemNameAndDescription();
    }
}