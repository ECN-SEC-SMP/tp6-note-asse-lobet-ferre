#pragma once

#include "realEstate.hpp"

#include <iostream>
#include <array>

using namespace std; 


class House : public RealEstate {
private:
    int PriceHouse = 200;
public:
    // Constructeur
    House();
    // Destructeur
    ~House();
    // Getter pour obtenir le prix d'une maison
    int getPrice() const override;
    // Méthode pour imprimer une maison
    void print() const override;
};
