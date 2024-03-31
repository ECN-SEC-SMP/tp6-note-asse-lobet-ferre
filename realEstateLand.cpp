#include <iostream>
#include "realEstateLand.hpp"

using namespace std;

RealEstateLand::RealEstateLand(string name, int price, Color color) : BuyableLand(name, Type::REAL_ESTATE_LAND, price), color(color) {}

RealEstateLand::RealEstateLand(string name, int price, string color) : BuyableLand(name, Type::REAL_ESTATE_LAND, price)
{
    if (color.compare("violet"))
    {
        this->color = Color::PURPLE;
    }
    else if (color.compare("gris"))
    {
        this->color = Color::GREY;
    }
    else if (color.compare("rose"))
    {
        this->color = Color::PINK;
    }
    else if (color.compare("orange"))
    {
        this->color = Color::ORANGE;
    }
    else if (color.compare("rouge"))
    {
        this->color = Color::RED;
    }
    else if (color.compare("jaune"))
    {
        this->color = Color::YELLOW;
    }
    else if (color.compare("vert"))
    {
        this->color = Color::GREEN;
    }
    else
    {
        throw invalid_argument("Donne une couleur de l'arc-en-ciel stp par contre, pas Acacia ou cyan, on n'est pas des bêtes quand même... Nan mais je veux dire, pas besoin d'étaler ta science avec tes couleurs qui n'existe pas? C'est bon, pas besoin d'étaler tes connaissances inutiles aux yeux de tout le monde? En plus ca interesse personne ok? tout le monde s'en fout. J'en ai parlé à Marlene, et à Jean, il te trouve imbu de ta personne. Personnellement, je trouve que tu es juste un gros c*n.... Cqfd. J'ai dis tout haut ce que les gens pensent tout bas...");
    }
}

RealEstateLand::~RealEstateLand()
{
    //cout << "deleted" << endl;
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