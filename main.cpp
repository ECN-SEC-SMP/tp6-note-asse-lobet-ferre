#include <iostream>
#include "plateau.hpp"
#include "box.hpp" // Supposons que vous avez défini la classe Box dans un fichier box.hpp

using namespace std; 

int main() {
    // Création d'un plateau
    Plateau plateau;

    cout << "Bonjour monde!" << endl;

    // Affichage du plateau
    std::cout << "Plateau avant initialisation :" << endl;
    plateau.printPlateau();

    // Accès à une case spécifique (par exemple, la case 5)
    int index = 5;
    Box* box = plateau.getBoxAt(index);
    if (box != nullptr) {
        plateau.printBoxAt(index);
    } else {
        cerr << "Erreur : indice de case invalide." << endl;
    }

    return 0;
}
