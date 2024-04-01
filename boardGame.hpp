#pragma once

#include <iostream>
#include <vector>
#include "land.hpp"
#include "configFileParser.hpp"

using namespace std;

class BoardGame
{
private:
    vector<Land *> global; // Utilisation de pointeurs pour permettre la polymorphie
    ConfigFileParser* cfp;
public:
    // Constructeur
    BoardGame();
    BoardGame(string filename);
    // Destructeur
    ~BoardGame();
    // Getter pour obtenir une case du BoardGame par son index
    Land* getLandAt(int index) const;
    // Méthode pour imprimer le contenu de la case à l'index spécifié
    void printLandAt(int index) const;

    friend ostream& operator<<(ostream& os, const BoardGame& p);
};
