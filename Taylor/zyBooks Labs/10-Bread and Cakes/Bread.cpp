#include "Bread.h"


// default constructor
Bread::Bread(std::string breadType) : BakedGood("Bread") {
    SetBreadType(breadType);
    
    SetPrice(CalcPrice());
}


// getters and setters for the bread type
std::string Bread::GetBreadType() {
    return breadType;
}

void Bread::SetBreadType(std::string newBreadType) {
    breadType = newBreadType;
}


// returns an information string
std::string Bread::ToInfoString() {
    std::string infoString;
    infoString += GetBreadType();
    infoString += " bread (";
    infoString += PriceToStr(GetPrice());
    infoString += ")";

    return infoString;
}


// returns the calculated price given a number of those item
double Bread::CalcPrice() {
    double priceOfAllBread = 4.50;
    return priceOfAllBread;
}

// calculates the discounted price given the number of same items
double Bread::CalcDiscountedPrice(int numSameItems) {
    // for every 3 breads, one is free
    double totalPrice = 0.0;
    for (int i = 0; i < numSameItems; ++i) {
        if (i % 3 == 0 || i % 3 == 1) {
            totalPrice += CalcPrice();
        }
    }

    return totalPrice;
}