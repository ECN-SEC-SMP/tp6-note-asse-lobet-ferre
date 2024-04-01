#include "publicService.hpp"

PublicService::PublicService(string name, int price) : BuyableLand(name, Type::PUBLIC_SERVICE, price)
{

}

PublicService::~PublicService()
{

}

int PublicService::getRent() const
{
    return this->rent;
}

void PublicService::action() const
{
    cout << "action!" << endl;
}

ostream& operator<<(ostream& os, const PublicService& ps)
{
    os << static_cast<const BuyableLand&> (ps);
    os << "         Loyer: " << ps.getRent() << endl;
    return os;
}