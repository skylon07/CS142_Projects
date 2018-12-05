#ifndef CAKE_H
#define CAKE_H

#include "BakedGood.h"

class Cake : public BakedGood {
public:
    // constructors
    Cake(std::string foodType = "none", std::string cakeFlavor = "none", std::string frostingFlavor = "none");

    // getters for members
    std::string GetCakeFlavor();
    std::string GetFrostingFlavor();

    // setters for members
    void SetCakeFlavor(std::string newFlavor);
    void SetFrostingFlavor(std::string newFlavor);

    virtual double CalcPrice() = 0;
    virtual double CalcDiscountedPrice(int numSameItems) = 0;
    virtual std::string ToInfoString() = 0;

private:
    std::string cakeFlavor = "none";
    std::string frostingFlavor = "none";
};

#endif