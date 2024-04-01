#include "jail.hpp"

Jail::Jail(string name) : Land(name, Type::JAIL) { }

Jail::~Jail() { }

void Jail::action() const
{
    cout << "Prendre une carte..." << endl;
}

ostream& operator<<(ostream& os, const Jail& j)
{
    os << static_cast<const Land&> (j);
    return os;
}