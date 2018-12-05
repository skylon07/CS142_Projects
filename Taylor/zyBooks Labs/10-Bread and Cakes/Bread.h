#ifndef BREAD_H
#define BREAD_H

#include "BakedGood.h"

class Bread : public BakedGood {
public:
    // constructors
    Bread(std::string breadType = "none"); // default

    // getters for members
    std::string GetBreadType();

    // setters for members
    void SetBreadType(std::string newType);

    // converts data to an information string
    std::string ToInfoString();

    // calculates total price, including discounts
    double CalcPrice();

    // calculates the discounted price given the number of same items
    double CalcDiscountedPrice(int numSameItems);

private:
    std::string breadType = "none";
};

#endif