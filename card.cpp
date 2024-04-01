#include "card.hpp"

Card::Card(string name, Type type) : Land(name, type) { }

Card::~Card() { }

void Card::action() const
{
    cout << "Prendre une carte..." << endl;
}