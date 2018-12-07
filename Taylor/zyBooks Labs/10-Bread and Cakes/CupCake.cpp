#include "CupCake.h"


// default constructor
CupCake::CupCake(std::string cakeFlavor, std::string frostingFlavor, std::string sprinklesColor) : Cake("CupCake", cakeFlavor, frostingFlavor) {
    SetSprinklesColor(sprinklesColor);
    
    SetPrice(CalcPrice());
}


// manupulators for sprinkles color
std::string CupCake::GetSprinklesColor() {
    return sprinklesColor;
}

void CupCake::SetSprinklesColor(std::string newColor) {
    sprinklesColor = newColor;
}


// returns the information string
std::string CupCake::ToInfoString() {
    std::string infoString;
    infoString += GetCakeFlavor();
    infoString += " cupcake with ";
    infoString += GetFrostingFlavor();
    infoString += " frosting and ";
    infoString += GetSprinklesColor();
    infoString += " sprinkles ($";
    infoString += PriceToStr(GetPrice());
    infoString += ")";

    return infoString;
}


// calculates the price of the item numItems times
double CupCake::CalcPrice() {
    double basePrice = 1.95;
    double cheeseFrostingPrice = 0.20;

    // adds cheese frosting price if the cupcake has cream cheese
    return (GetFrostingFlavor() == "cream-cheese") ? (basePrice + cheeseFrostingPrice) : basePrice;
}

// calculates the discounted price given the number of same items
double CupCake::CalcDiscountedPrice(int numSameItems) {
    double discountedPrice = 0.0;

    // buy 2 or more (up to 4?), get $0.30 off each
    if (numSameItems < 4 && numSameItems >= 2) {
        discountedPrice = 0.30;
    }

    // buy 4 or more, get $0.40 off each
    if (numSameItems >= 4) {
        discountedPrice = 0.40;
    }

    return (CalcPrice() - discountedPrice) * numSameItems;
}