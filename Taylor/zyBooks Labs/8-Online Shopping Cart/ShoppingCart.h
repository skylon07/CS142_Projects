#ifndef SHOPPING_CART_H
#define SHOPPING_CART_H

#include <string>
#include <vector>
#include <iostream>

#include "ItemToPurchase.h"

class ShoppingCart {
public:
    // constructors
    ShoppingCart(std::string customerName="none", std::string cartDate="January 1, 2016"); // default

    // getters for private data members
    std::string GetCustomerName() const { return customerName; }

    std::string GetDateCreated() const { return cartCreationDate; }


    // cart list information getters/calculators
    int GetSizeOfCart() const { return inCartList.size(); }

    int GetNumItemsInCart();

    double GetTotalCostOfCart() const;
    

    // manipulators for the cart list items
    void AddItemToCart(ItemToPurchase newItem);

    void RemoveItemFromCartByName(std::string targetName);

    void UpdateItemQtyByName(std::string targetName, int newQty);


    // printing functions
    void PrintCartNameAndDate() const;

    void PrintAllItemsCostAndQty();

    void PrintAllItemsAndDescriptions() const;


private:
    std::string customerName;
    std::string cartCreationDate;
    std::vector<ItemToPurchase> inCartList;

    // setters are private, must be constructed
    void SetCustomerName(std::string newName) { customerName = newName; }

    void SetDateCreated(std::string newDate) { cartCreationDate = newDate; }

    // cart list item finder that returns the index of the item in the cart
    int FindItemInCartByName(std::string targetName);
};

#endif