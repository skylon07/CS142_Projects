#ifndef BAKED_GOOD_H
#define BAKED_GOOD_H

#include <string>

class BakedGood {
public:
    // constructors
    BakedGood(std::string foodType = "none"); // default

    // converts data to an information string
    virtual std::string ToInfoString() = 0;

    // calculates total price, including discounts
    virtual double CalcPrice() = 0;
    // calculates a discounted price, given a number of items
    virtual double CalcDiscountedPrice(int numSameItems) = 0;
    // converts what is returned above into a string
    std::string PriceToStr(double priceToConvert);

    // getters for memebers
    std::string GetFoodType();
    double GetPrice();

    // setters for members
    void SetPrice(double newPrice);

protected:
    // defined by subclasses, contains the type of baked good
    std::string foodType = "none";
    double individualPrice = 0;

    void SetFoodType(std::string newFoodType);
};

#endif