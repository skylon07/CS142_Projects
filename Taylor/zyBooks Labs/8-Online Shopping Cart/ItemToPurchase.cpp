#include "ItemToPurchase.h"


// default constructor
ItemToPurchase::ItemToPurchase(std::string itemName, std::string itemDescription,
                               double itemPrice, int itemQty) {
    SetItemName(itemName);
    SetItemDescription(itemDescription);
    SetItemPrice(itemPrice);
    SetItemQty(itemQty);
}

// alternate order to handle description-less items
ItemToPurchase::ItemToPurchase(std::string itemName, double itemPrice, int itemQty) {
    // automatic definition
    std::string itemDescription = "none";
    // construct default
    ItemToPurchase(itemName, itemDescription, itemPrice, itemQty);
}


// prints the total cost of an item
void ItemToPurchase::PrintItemQtyAndCost() {
    double totalItemCost = GetItemPrice() * GetItemQty();

    std::cout << std::setprecision(2); // sets precision to cents in price
    std::cout << GetItemName() << " " << GetItemQty() << " @ $" << GetItemPrice() 
        << " = $" << totalItemCost << std::endl;
}

// prints some information about the item
void ItemToPurchase::PrintItemNameAndDescription() {
    std::cout << GetItemName() << ": " << GetItemDescription() << std::endl;
}