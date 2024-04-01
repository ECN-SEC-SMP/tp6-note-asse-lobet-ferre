#include <string>
#include "boardGame.hpp"
#include "realEstateLand.hpp"

// Constructeur par défaut
BoardGame::BoardGame()
{
    // Initialisation de chaque case du BoardGame avec des instances de Land
    for (int i = 0; i < 10; ++i)
    {
        global.push_back(new RealEstateLand("Unkown", 666, Color::GREEN));
    }
}

BoardGame::BoardGame(string filename)
{
    this->cfp = new ConfigFileParser(filename);
    global = cfp->parseBoardConfigFile();
}

// Destructeur
BoardGame::~BoardGame()
{
    int length = global.size();
    // Libération de la mémoire allouée pour chaque case du BoardGame
    for (int i = 0; i < length; i++)
    {
        delete global[i];
    }
    delete this->cfp;
 }

// Getter pour obtenir une case du BoardGame par son index
Land* BoardGame::getLandAt(int index) const
{
    int length = global.size();

    if (index >= 0 && index < length)
    {
        return global[index];
    } else
    {
        // Gestion de l'erreur si l'index est invalide
        return nullptr;
    }
}

// Méthode pour imprimer le contenu de la case à l'index spécifié
void BoardGame::printLandAt(int index) const
{
    int length = global.size();

    if (index >= 0 && index < length)
    {
        cout << *global[index] << endl; // Supposons que la classe Land ait une méthode getDescription()
    } else
    {
        cerr << "Erreur : indice de case invalide." << endl;
    }
}

ostream& operator<<(ostream& os, const BoardGame& p)
{
    int length = p.global.size();

    for (int i = 0; i < length; ++i)
        os << *p.global[i] << endl;
    return os;
}