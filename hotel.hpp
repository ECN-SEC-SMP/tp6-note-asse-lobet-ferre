#pragma once

#include "realEstate.hpp"

#include <iostream>

using namespace std; 


class Hotel :public RealEstate {
private:
    int PriceHotel;
public:
    // Constructeur
    Hotel();
    // Destructeur
    ~Hotel();
    // Getter pour obtenir le prix d'une hotel
    int getPrice() const override;
    // Méthode pour imprimer une hotel
    void print() const override;
};
