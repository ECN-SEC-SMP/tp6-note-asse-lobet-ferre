#include "land.hpp"

Land::Land(string name, Type type) : name(name), type(type) { }

Land::~Land() {}

string Land::getName() const
{
    return name;
}

Type Land::getType() const
{
    return this->type;
}

ostream& operator<<(ostream& os, const Land& l)
{
    os << "Nom: " << l.getName() << endl;
    os << "Type de la case: ";
    Type type = l.getType();
    switch (type)
    {
    case Type::START:
        os << "Départ" << endl;
        break;
    case Type::JAIL:
        os << "Prison" << endl;
        break;
    case Type::PUBLIC_SERVICE:
        os << "Service public" << endl;
        break;
    case Type::STATION:
        os << "Gare" << endl;
        break;
    case Type::REAL_ESTATE_LAND:
        os << "Terrain achetable" << endl;
        break;

    case Type::COMMUNITY_FUND:
        os << "Caisse de communauté" << endl;
        break;

    case Type::GO_TO_JAIL:
        os << "Aller en prison" << endl;
        break;

    case Type::LUCK:
        os << "Case chance" << endl;
        break;

    case Type::TAX:
        os << "Case de taxe" << endl;
        break;

    case Type::FREE_PARK:
        os << "Parking gratuit" << endl;
        break;

    default:
        os << "Euuhh.... La on a un probleme? jsp, je dis ca, je dis rien..." << endl;
        break;
    }
    return os;
}