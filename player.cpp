#include "joueur.hpp"

Joueur::Joueur(string newName, int newFinancialAssets)
{
    this->name = newName;
    this->financialAssets   = newFinancialAssets;
}

int const Joueur::getPlayerPosition()
{
    return this->position;
}

// void buyHouse();
// void buyHotel();
// void buyRealEstateLand();