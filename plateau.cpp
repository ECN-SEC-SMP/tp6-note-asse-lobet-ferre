#include "plateau.hpp"
#include "box.hpp" // Supposons que vous avez défini la classe Box dans un fichier box.hpp

// Constructeur par défaut
Plateau::Plateau() {
    // Initialisation de chaque case du plateau avec des instances de Box
    for (int i = 0; i < 40; ++i) {
        global[i] = new Box(); // Vous devrez probablement définir un constructeur par défaut dans la classe Box
    }
}

// Destructeur
Plateau::~Plateau() {
    // Libération de la mémoire allouée pour chaque case du plateau
    for (int i = 0; i < 40; ++i) {
        delete global[i];
    }
}

// Getter pour obtenir une case du plateau par son index
Box* Plateau::getBoxAt(int index) const {
    if (index >= 0 && index < 40) {
        return global[index];
    } else {
        // Gestion de l'erreur si l'index est invalide
        return nullptr;
    }
}
