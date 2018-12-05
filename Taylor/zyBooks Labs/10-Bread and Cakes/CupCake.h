#ifndef CUP_CAKE_H
#define CUP_CAKE_H

#include "Cake.h"

class CupCake : public Cake {
public:
    // constructors
    CupCake(std::string cakeFlavor = "none", std::string frostingFlavor = "none", std::string sprinklesColor = "none"); // default

    // getters for members
    std::string GetSprinklesColor();

    // setters for members
    void SetSprinklesColor(std::string newColor);

    // converts data to an information string
    std::string ToInfoString();

    // calculates total price, including discounts
    double CalcPrice();

    // calculates the discounted price given the number of same items
    double CalcDiscountedPrice(int numSameItems);

private:
    std::string sprinklesColor = "none";
};

#endif