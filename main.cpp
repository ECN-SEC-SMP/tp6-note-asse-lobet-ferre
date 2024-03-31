#include <iostream>
#include "realEstateLand.hpp"
#include "plateau.hpp"
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

    std::cout << "Création d'une case de propriété" << endl;

    cout << my_land << endl;

}


void testBoard()
{
    // Création d'un plateau
    Plateau plateau("plateau.config");

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
