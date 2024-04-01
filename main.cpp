#include <iostream>
#include "realEstateLand.hpp"
#include "boardGame.hpp"
#include "hotel.hpp"
#include "house.hpp"
#include <cassert>

using namespace std;

void testHotel() {
    Hotel hotel;

    // Test de la méthode getPrice()
    assert(hotel.getPrice() == 250);

    // Test de la méthode print()
    cout << "Détail d'une Hotel:" << endl;
    hotel.print();
}

void testHouse() {
    House house;

    // Test de la méthode getPrice()
    assert(house.getPrice() == 200);

    // Test de la méthode print()
    cout << "Détail d'une Maison: " << endl;
    house.print();
}

void testRealEstateLand()
{
    RealEstateLand my_land("Mairie de doulon", 666, Color::GREEN);

    assert(my_land.getName() == "Mairie de doulon");
    assert(my_land.getPrice() == 666);
    assert(my_land.getColor() == Color::GREEN);
    assert(my_land.getType() == Type::REAL_ESTATE_LAND);
    assert(my_land.isPurchased() == false);

    try
    {
        my_land.getOwner();
        assert(false);
    }
    catch(const exception& e)
    {

    }

    //Todo ajouter joueur
    //todo tester getOwner avec joueur
    //todo tester isPuchased avec joueur
    cout << my_land << endl;

}


void testBoard()
{
    // Création d'un plateau
    BoardGame plateau("plateau.config");

    // Accès à une case spécifique (par exemple, la case 5)
    int index = 3;
    Land* land = plateau.getLandAt(index);
    assert(land != nullptr);
}

int main()
{
    // Exécuter les tests
    testBoard();
    testHotel();
    testHouse();
    testRealEstateLand();

    cout << "Tout les tests sont réussi" << endl;

    return 0;
}
