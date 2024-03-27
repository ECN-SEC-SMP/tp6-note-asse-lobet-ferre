#include "hotel.hpp"

#include <iostream>

// Getter pour obtenir le prix d'une hotel
int Hotel::getPrice() const {
    return Hotel::PriceHotel;
}


void Hotel::print() const {
    std::cout << "Hotel" << std::endl;
    std::cout << "Price: " << getPrice() << std::endl;
}
