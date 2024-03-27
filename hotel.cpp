#include "hotel.hpp"

#include <iostream>

//Constructeur
Hotel::Hotel() {
    Hotel::PriceHotel = 250;
}

//Destructeur 
Hotel::~Hotel() {
}


// Getter pour obtenir le prix d'une hotel
int Hotel::getPrice() const {
    return Hotel::PriceHotel;
}

// Print d'un hotel
void Hotel::print() const {
    std::cout << "Hotel" << std::endl;
    std::cout << "Prix: " << getPrice() << std::endl;
}
