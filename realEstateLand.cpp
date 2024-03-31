#include <iostream>
#include "realEstateLand.hpp"

using namespace std;

RealEstateLand::RealEstateLand(string name, int price, Color color) : BuyableLand(name, Type::REAL_ESTATE_LAND, price), color(color) {}

RealEstateLand::~RealEstateLand()
{
    cout << "deleted" << endl;
}

int RealEstateLand::getRent() const
{
    return this->price;
}

Color RealEstateLand::getColor() const
{
    return this->color;
}

void RealEstateLand::action() const
{
    cout << "action!" << endl;
}

ostream& operator<<(ostream& os, const RealEstateLand& rel)
{
    os << static_cast<const BuyableLand&> (rel);
    os << "         Loyer: " << rel.getRent() << endl;
    return os;
}