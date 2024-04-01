#include "parc.hpp"

Parc::Parc(string name) : Land(name, Type::FREE_PARK) { }

Parc::~Parc() { }

void Parc::action() const
{
    cout << "Passer son tour" << endl;
}

ostream& operator<<(ostream& os, const Parc& p)
{
    os << static_cast<const Land&> (p);
    return os;
}