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

int main()
{
    // Création d'un plateau
    Plateau plateau;

    // Affichage du plateau
    cout << "Plateau avant initialisation :" << endl;
    plateau.print();

    // Accès à une case spécifique (par exemple, la case 5)
    int index = 5;
    Land* land = plateau.getLandAt(index);
    if (land != nullptr)
    {
        plateau.printLandAt(index);
    } else
    {
        cerr << "Erreur : indice de case invalide." << endl;
    }

    // Exécuter les tests
    testHotel();
    testHouse();
    testRealEstateLand();

    cout << "Tout les tests sont réussi" << endl;

    return 0;
}
