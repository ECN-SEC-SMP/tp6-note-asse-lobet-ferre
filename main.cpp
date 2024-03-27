#include <iostream>
#include "plateau.hpp"
#include "box.hpp" // Supposons que vous avez défini la classe Box dans un fichier box.hpp
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

int main() {
    // Création d'un plateau
    Plateau plateau;

    cout << "Bonjour monde!" << endl;

    // Affichage du plateau
    std::cout << "Plateau avant initialisation :" << endl;
    plateau.print();

    // Accès à une case spécifique (par exemple, la case 5)
    int index = 5;
    Box* box = plateau.getBoxAt(index);
    if (box != nullptr) {
        plateau.printBoxAt(index);
    } else {
        cerr << "Erreur : indice de case invalide." << endl;
    }

    // Exécuter les tests
    testHotel();
    testHouse();

    cout << "Tout les tests sont réussi" << endl;

    return 0;
}
