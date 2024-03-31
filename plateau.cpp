#include <string>
#include "plateau.hpp"
#include "realEstateLand.hpp"

// Constructeur par défaut
Plateau::Plateau()
{
    // Initialisation de chaque case du plateau avec des instances de Land
    for (int i = 0; i < 10; ++i)
    {
        global.push_back(new RealEstateLand("Unkown", 666, Color::GREEN));
    }
}

Plateau::Plateau(string filename)
{
    this->cfp = new ConfigFileParser(filename);
    global = cfp->parseBoardConfigFile();
}

// Destructeur
Plateau::~Plateau()
{
    int length = global.size();
    // Libération de la mémoire allouée pour chaque case du plateau
    for (int i = 0; i < length; i++)
    {
        delete global[i];
    }
    delete this->cfp;
 }

// Getter pour obtenir une case du plateau par son index
Land* Plateau::getLandAt(int index) const
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
void Plateau::printLandAt(int index) const
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

ostream& operator<<(ostream& os, const Plateau& p)
{
    int length = p.global.size();

    for (int i = 0; i < length; ++i)
        os << *p.global[i] << endl;
    return os;
}