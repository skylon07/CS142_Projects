#include "BakedGood.h"


// default constructor
BakedGood::BakedGood(std::string foodType) {
    SetFoodType(foodType);
}


// returns the food type
std::string BakedGood::GetFoodType() {
    return foodType;
}

// sets the food type
void BakedGood::SetFoodType(std::string newFoodType) {
    foodType = newFoodType;
}


// manipulators for food price
double BakedGood::GetPrice() {
    return individualPrice;
}

void BakedGood::SetPrice(double newPrice) {
    individualPrice = newPrice;
}


// calculates price and formats into a string
std::string BakedGood::PriceToStr(double priceToConvert) {
    // converts raw double to a string (with money sign)
    std::string priceStr = '$' + std::to_string(priceToConvert);
    
    // price is two decimal places; strip off all floating zeros left by to_string()
    priceStr.erase(priceStr.find_last_not_of('0') + 1, std::string::npos);
    // add in two trailing zeros if necessary
    // if last char is '.'
    if (priceStr.at(priceStr.size() - 1) == '.') {
        priceStr.push_back('0');
    }
    // if the second to last char is '.'
    if (priceStr.at(priceStr.size() - 2) == '.') {
        priceStr.push_back('0');
    }
    
    return priceStr;
}