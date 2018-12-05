#ifndef LAYER_CAKE_H
#define LAYER_CAKE_H

#include "Cake.h"

class LayerCake : public Cake {
public:
    // constructors
    LayerCake(std::string cakeFlavor = "none", std::string frostingFlavor = "none", int numLayers = 0); // default

    // getters for members
    int GetNumLayers();

    // setters for members
    void SetNumLayers(int newNumLayers);

    // converts data to an information string
    std::string ToInfoString();

    // calculates total price, including discounts
    double CalcPrice();

    // calculates the discounted price given the number of same items
    double CalcDiscountedPrice(int numSameItems);

private:
    int numLayers = 0;
};

#endif