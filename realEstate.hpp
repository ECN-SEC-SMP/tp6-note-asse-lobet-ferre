#pragma once
#include <iostream>

class RealEstate {
public:
    // Constructeur virtuel
    RealEstate() {}
    // Destructeur virtuel
    virtual ~RealEstate() {}

    // Méthode virtuelle pour imprimer un bien immobilier
    virtual void print() const = 0;
    // Méthode virtuelle pour obtenir le prix d'un bien immobilier
    virtual int getPrice() const = 0;
};