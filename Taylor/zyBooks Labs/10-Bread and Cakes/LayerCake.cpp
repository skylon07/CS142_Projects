#include "LayerCake.h"


// default constructor
LayerCake::LayerCake(std::string cakeFlavor, std::string frostingFlavor, int numLayers) : Cake("LayerCake", cakeFlavor, frostingFlavor) {
    SetNumLayers(numLayers);
    
    SetPrice(CalcPrice());
}


// manipulators for the number of layers
int LayerCake::GetNumLayers() {
    return numLayers;
}

void LayerCake::SetNumLayers(int newNumLayers) {
    numLayers = newNumLayers;
}


// returns the information string
std::string LayerCake::ToInfoString() {
    std::string infoString;
    infoString += std::to_string(GetNumLayers());
    infoString += "-layer ";
    infoString += GetCakeFlavor();
    infoString += " cake with ";
    infoString += GetFrostingFlavor();
    infoString += " frosting (";
    infoString += PriceToStr(GetPrice());
    infoString += ")";

    return infoString;
}


// calculates the price given the number of items
double LayerCake::CalcPrice() {
    double basePrice = 6.00;
    double pricePerLayer = 3.00;
    double pricePerCheeseFrostingLayer = 1.00;

    double totalPrice = basePrice;
    // add the price per layer
    totalPrice += pricePerLayer * GetNumLayers();
    // if there is cream cheese frosting, add the cheese price per layer
    totalPrice += (GetFrostingFlavor() == "cream-cheese") ? (pricePerCheeseFrostingLayer * GetNumLayers()) : 0;

    return totalPrice;
}


// calculates the discounted price given the number of same items
double LayerCake::CalcDiscountedPrice(int numSameItems) {
    double discountedPrice = 0.0;

    // buy 3 or more and get $2.00 off each
    if (numSameItems >= 3) {
        discountedPrice = 2.0;
    }

    return CalcPrice() - (discountedPrice * numSameItems);
}