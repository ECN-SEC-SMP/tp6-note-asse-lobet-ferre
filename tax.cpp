#include "tax.hpp"

Tax::Tax(string name, int tax) : Land(name, Type::TAX), tax(tax) { }

Tax::~Tax() { }

void Tax::action() const
{
    cout << "Payer la taxe" << endl;
}