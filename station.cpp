#include "station.hpp"

Station::Station(string name, int price) : BuyableLand(name, Type::STATION, price)
{

}

Station::~Station()
{

}

int Station::getRent() const
{
    return this->rent;
}

void Station::action() const
{
    cout << "action!" << endl;
}

ostream& operator<<(ostream& os, const Station& s)
{
    os << static_cast<const BuyableLand&> (s);
    os << "         Loyer: " << s.getRent() << endl;
    return os;
}