#include <stdexcept>
#include "buyableLand.hpp"

BuyableLand::BuyableLand(string name, Type type, int price) : Land(name, type), price(price), rent(price) { };

int BuyableLand::getPrice() const
{
    return this->price;
}

bool BuyableLand::isPurchased() const
{
    return this->owner != nullptr ? true : false;
}

Player* BuyableLand::getOwner() const
{
    if (this->owner == nullptr)
        throw runtime_error("Aucun propriétaire n'est défini pour ce terrain.");
    return this->owner;
}

ostream& operator<<(ostream& os, const BuyableLand& bl)
{
    os << static_cast<const Land&> (bl);
    os << "     Prix: " << bl.getPrice() << endl;
    os << "     Propriétaire: ";
    try
    {
        os << bl.getOwner() << endl;
    }
    catch(const exception& e)
    {
        os << "Aucun" << endl;
    }
    return os;
}