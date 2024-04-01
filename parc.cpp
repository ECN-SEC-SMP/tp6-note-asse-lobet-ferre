#include "parc.hpp"

Parc::Parc(string name) : Land(name, Type::FREE_PARK) { }

Parc::~Parc() { }

void Parc::action() const
{
    cout << "Passer son tour" << endl;
}