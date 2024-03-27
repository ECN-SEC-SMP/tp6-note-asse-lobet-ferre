#include "plateau.hpp"
#include "box.hpp" // Supposons que vous avez défini la classe Box dans un fichier box.hpp

#include <iostream>

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

// Méthode pour imprimer le plateau
void Plateau::print() const {
    for (int i = 0; i < 40; ++i) {
        //cout << "Case " << i << ": " << global[i]->getDescription() << std::endl; // Supposons que la classe Box ait une méthode getDescription()
        cout << "Case " << i << ": " << "none" << endl; // Supposons que la classe Box ait une méthode getDescription()

    }
}

// Méthode pour imprimer le contenu de la case à l'index spécifié
void Plateau::printBoxAt(int index) const {
    if (index >= 0 && index < 40) {
        cout << "Contenu de la case " << index << ": " << "not defined yet"<< endl; // Supposons que la classe Box ait une méthode getDescription()
    } else {
        cerr << "Erreur : indice de case invalide." << endl;
    }
}