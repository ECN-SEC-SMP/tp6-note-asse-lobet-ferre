#include "gotoJail.hpp"

GotoJail::GotoJail(string name) : Land(name, Type::GO_TO_JAIL) { }

GotoJail::~GotoJail() { }

void GotoJail::action() const
{
    cout << "Direction la zonzon!" << endl;
}

ostream& operator<<(ostream& os, const GotoJail& gj)
{
    os << static_cast<const Land&> (gj);
    return os;
}