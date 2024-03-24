#include "plateau.hpp"
#include "box.hpp" // Supposons que la classe Box est défini dans un fichier box.hpp

// Constructeur par défaut
Plateau::Plateau() {
    // Initialisation de chaque case du plateau avec des instances de Box
    for (int i = 0; i < 40; ++i) {
        plateau[i] = new Box(); // Vous devrez probablement définir un constructeur par défaut dans la classe Box
    }
}

// Destructeur
Plateau::~Plateau() {
    // Libération de la mémoire allouée pour chaque case du plateau
    for (int i = 0; i < 40; ++i) {
        delete plateau[i];
    }
}
