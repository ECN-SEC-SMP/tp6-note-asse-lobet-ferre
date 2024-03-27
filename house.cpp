#include "house.hpp"

#include <iostream>

// Getter pour obtenir le prix d'une hotel
int House::getPrice() const {
    return House::PriceHouse;
}


void House::print() const {
    std::cout << "House" << std::endl;
    std::cout << "Price: " << getPrice() << std::endl;
}