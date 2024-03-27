#include "house.hpp"

#include <iostream>

//Constructeur
House::House() {
    House::PriceHouse = 200;
}

//Destructeur 
House::~House() {
}

// Getter pour obtenir le prix d'une hotel
int House::getPrice() const {
    return House::PriceHouse;
}

//Print d'une maison
void House::print() const {
    std::cout << "House" << std::endl;
    std::cout << "Price: " << getPrice() << std::endl;
}