#include "gotoJail.hpp"

GotoJail::GotoJail(string name) : Land(name, Type::GO_TO_JAIL) { }

GotoJail::~GotoJail() { }

void GotoJail::action() const
{
    cout << "Direction la zonzon!" << endl;
}