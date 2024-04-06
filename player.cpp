#include "player.hpp"

Player::Player(string newName, int newFinancialAssets, int nbDouble, int position)
{
    this->name = newName;
    this->financialAssets = newFinancialAssets;
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

int Player::getNbDouble() const
{
    return this->nbDouble;
}

int Player::getPosition () const
{
    return this->position;
}

void Player::setPosition(int m)
{
    this->position = m;
}

ostream& operator<<(ostream& os, const Player& player)
{
    os << "Nom du joueur :" << player.getName() << endl;
    os << "     Patrimoine Financier : " <<player.getFinancialAssets() << endl;
    os << "     Nombre de doubles consécutifs : " <<player.getNbDouble() << endl;
    os << "     Position : " <<player.getPosition() << endl;

    return os;
}