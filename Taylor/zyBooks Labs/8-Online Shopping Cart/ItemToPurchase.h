#ifndef ITEM_TO_PURCHASE_H
#define ITEM_TO_PURCHASE_H

#include <string>
#include <iostream>
#include <iomanip>

class ItemToPurchase {
public:
    // constructors
    // default constructor
    ItemToPurchase(std::string itemName="none", std::string itemDescription="none",
                   double itemPrice=0, int itemQty=0);
    // alt order with numbers without a description
    ItemToPurchase(std::string itemName="none", double itemPrice=0, int itemQty=0);


    // setters and getters for private data members
    std::string GetItemName() { return itemName; }
    void SetItemName(std::string newName) { itemName = newName; }

    std::string GetItemDescription() { return itemDescription; }
    void SetItemDescription(std::string newDescription) { itemDescription = newDescription; }

    double GetItemPrice() { return itemPrice; }
    void SetItemPrice(double newPrice) { itemPrice = newPrice; }

    int GetItemQty() { return itemQty; }
    void SetItemQty(int newQty) { itemQty = newQty; }
    

    // printing function for the cost per item and the total cost
    void PrintItemQtyAndCost();

    // printing function that prints descriptive information
    void PrintItemNameAndDescription();


private:
    // informational data members
    std::string itemName;
    std::string itemDescription;
    double itemPrice;
    int itemQty;
};

#endif