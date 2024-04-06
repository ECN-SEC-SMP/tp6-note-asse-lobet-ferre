#include "player.hpp"

Player::Player(string newName, int newFinancialAssets, int movement, int nbDouble, int position)
{
    this->name = newName;
    this->financialAssets = newFinancialAssets;
    this->movement = movement;
    this->nbDouble = nbDouble;
    this->position = position;
}

void Player::buyHouse()
{

}

void Player::buyHotel()
{

}

void Player::buyRealEstateLand()
{

}

string Player::getName() const
{
    return this->name;
}

int Player::getFinancialAssets() const
{
    return this->financialAssets;
}

int Player::getMovement() const
{
    return this->movement;
}

int Player::getNbDouble() const
{
    return this->nbDouble;
}

int Player::getPosition () const
{
    return this->position;
}

void Player::setMovement(int newMovement)
{
    this->movement = newMovement;
}

void Player::setNbDouble(int newNbDouble)
{
    this->nbDouble = newNbDouble;
}

void Player::setPosition(int newPosition)
{
    this->position = newPosition;
}

// ostream& operator<<(ostream& os, const Player& player)
// {
//     os << "Nom du joueur : " << player.getName() << endl;
//     os << "     Patrimoine Financier : " << player.getFinancialAssets() << endl;
//     os << "     Résultat cumulé des dés : " << player.getMovement() << endl;
//     os << "     Nombre de doubles consécutifs : " << player.getNbDouble() << endl;
//     os << "     Position : " << player.getPosition() << endl;

//     return os;
// }