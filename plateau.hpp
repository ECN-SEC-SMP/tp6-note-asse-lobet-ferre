#pragma once

#include <iostream>
#include <vector>
#include "land.hpp"

using namespace std;

class Plateau
{
private:
    vector<Land *> global; // Utilisation de pointeurs pour permettre la polymorphie
public:
    // Constructeur
    Plateau();
    // Destructeur
    ~Plateau();
    // Getter pour obtenir une case du plateau par son index
    Land* getLandAt(int index) const;
    // Méthode pour imprimer le plateau
    void print() const;
    // Méthode pour imprimer le contenu de la case à l'index spécifié
    void printLandAt(int index) const;
};
