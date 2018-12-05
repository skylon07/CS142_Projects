#include "Cake.h"


// default constructor
Cake::Cake(std::string foodType, std::string cakeFlavor, std::string frostingFlavor) : BakedGood(foodType) {
    SetCakeFlavor(cakeFlavor);
    SetFrostingFlavor(frostingFlavor);
}


// manipulators for cake flavor
std::string Cake::GetCakeFlavor() {
    return cakeFlavor;
}

void Cake::SetCakeFlavor(std::string newFlavor) {
    cakeFlavor = newFlavor;
}


// manipulators for frosting flavor
std::string Cake::GetFrostingFlavor() {
    return frostingFlavor;
}

void Cake::SetFrostingFlavor(std::string newFlavor) {
    frostingFlavor = newFlavor;
}