#include "jail.hpp"

Jail::Jail(string name) : Land(name, Type::JAIL) { }

Jail::~Jail() { }

void Jail::action() const
{
    cout << "Prendre une carte..." << endl;
}