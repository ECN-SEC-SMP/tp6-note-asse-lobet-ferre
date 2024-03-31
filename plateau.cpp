#include "plateau.hpp"
#include "realEstateLand.hpp"

// Constructeur par défaut
Plateau::Plateau()
{
    // Initialisation de chaque case du plateau avec des instances de Land
    for (int i = 0; i < 40; ++i)
    {
        global.push_back(new RealEstateLand("Unkown", 666, Color::GREEN));
    }
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

// Méthode pour imprimer le plateau
void Plateau::print() const
{
    int length = global.size();

    for (int i = 0; i < length; ++i)
    {
        //cout << "Case " << i << ": " << global[i]->getDescription() << std::endl; // Supposons que la classe Land ait une méthode getDescription()
        cout << "Case " << i << ": " << "none" << endl; // Supposons que la classe Land ait une méthode getDescription()

    }
}

// Méthode pour imprimer le contenu de la case à l'index spécifié
void Plateau::printLandAt(int index) const
{
    int length = global.size();

    if (index >= 0 && index < length)
    {
        cout << "Contenu de la case " << index << ": " << "not defined yet"<< endl; // Supposons que la classe Land ait une méthode getDescription()
    } else
    {
        cerr << "Erreur : indice de case invalide." << endl;
    }
}