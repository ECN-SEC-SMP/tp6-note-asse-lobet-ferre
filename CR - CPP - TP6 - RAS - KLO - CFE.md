# CPP - TP6

*Romain ASSE - Cédric FERRE - Kadwalon LOBET*

***Replit:***

***Github:***

[https://github.com/ECN-SEC-SMP/tp6-note-asse-lobet-ferre](https://github.com/ECN-SEC-SMP/tp6-note-asse-lobet-ferre)

<aside>
ℹ️ Si vous ne souhaitez pas vous embêter avec Replit, le projet est “prêt à l’emploi” et ne dépend pas d’un IDE.

</aside>

# Introduction

Ce TP à pour but de récréer le jeu Monopoly au format numérique et plus précisément à l’aide du langage C++. Pour ce faire avons défini une architecture spécifique que voici :

![Untitled](CPP%20-%20TP6%20b90f789def8f421d82d10c1e7620aba1/Untitled.png)

Nous avons en premier lieu, une classe `GameMaster` qui, comme son nom l’indique, va servir de maître du jeu et organiser le séquencement des différentes phases de jeu. Ce maitre du jeu va régir les classes `Player` et `Dice` (qui ne sera finalement pas implémentée et intégrée directement dans le `GameMaster`).

Pour ce qui est du plateau nous avons choisi d’avoir une classe `BoardGame` pour l’implémenter. Cette classe aura pour héritière `Land` car le plateau est composé de terrains. Ces terrains se divisent en deux catégories à savoir achetable ou non-achetable, c’est pourquoi il existe une classe `BuyableLand`, héritée par `PublicsServices`, `Land`, `Station`, `Tax`, et `Luck`. Les autres composantes du plateau qui ne sont pas achetables (à savoir : `Parc`, `Start`, et `Jail`) hériterons de `Land` directement.

En complément on retrouve la classes `Chance`, héritière de `Cards` pour la gestion des cartes. Ainsi que la gestion des liquidités et des actifs immobiliers tels que les maisons et les hôtels, on a donc la classe `RealEstate` qui est héritée par `Hotel` et `Maison` pour gérer la notion de patrimoine.

# Classe BoardGame

> Cette classe permet de représenter le plateau de jeu sous forme de buffer circulaire composé d’instances de `Land` qui sont les cases qui composent le plateau.
> 

![Untitled](CPP%20-%20TP6%20b90f789def8f421d82d10c1e7620aba1/Untitled%201.png)

Cette classe devra répondre au diagramme de classe ci dessus qui a été fourni dans le cahier des charges.

***Code:***

Déclaration

```cpp
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
```

> Concernant les choix techniques, on notera l’attribut `global` qui représente un vecteur de pointeurs sur cases afin de faire référence au plateau.
On peut également noter l’utilisation d’un pointeur sur `ConfigFileParser` qui permet d’aller lire les information du fichier `plateau.config` afin d’extraire les informations sur chaque cases qui sont renseignées dans ce fichier.
On notera également la méthode `printLandAt()` qui permet d’attribuer les informations lues dans le fichier `plateau.config` a une case en particulier.
Rien d’autre de particulier n’est à noter si ce n’est une déclaration classique d’accesseur et une surcharge de l’opérateur de redirection de flux `<<` afin de pouvoir afficher les instances de la classe lors de l’utilisation d’un `cout`.
> 

Et maintenant sa définition:

```cpp
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
```

> Rien de particulier à remonter qui n’est pas détaillé dans les commentaires.
> 

***Test:***

Vous trouverez dans la batterie de tests:

- Un test du constructeur par défaut.
- Un test de l’accesseur
- Un test d’accès à une case spécifique

Nous pouvons maintenant passer aux classes héritières de `BoardGame` à savoir `ConfigFileParser` et `Land`.

# Classe ConfigFileParser

> `ConfigFileParser` permet de lire et extraire le contenu du fichier `plateau.config` qui n’est en réalité rien qu’un fichier texte brut.
> 

![Untitled](CPP%20-%20TP6%20b90f789def8f421d82d10c1e7620aba1/Untitled%202.png)

Cette classe devra répondre au diagramme de classe ci dessus qui a été fourni dans le cahier des charges.

***Code:***

Ci dessous sa déclaration

```cpp
#pragma once

#include <string>
#include <vector>
#include "land.hpp"

using namespace std;

class ConfigFileParser
{
public:
    ConfigFileParser(string filename);
    vector<Land *> parseBoardConfigFile();

private:
    string filename;

    string& ltrim(string &str, string const &whitespace);
    string extractStringProperty(string line);
    int extractIntProperty(string line);

};
```

> Ici, rien de nouveau à ajouter en plus de ce qui à été présenté précédemment.
> 

Et sa définition

```cpp
#include <fstream>
#include <iostream>
#include "configFileParser.hpp"
#include "realEstateLand.hpp"
#include "station.hpp"
#include "publicService.hpp"
#include "card.hpp"
#include "jail.hpp"
#include "gotoJail.hpp"
#include "tax.hpp"
#include "parc.hpp"
#include "start.hpp"

ConfigFileParser::ConfigFileParser(string filename) : filename(filename) { }

string& ConfigFileParser::ltrim(string &str, string const &whitespace = " \r\n\t\v\f")
{
    str.erase(0, str.find_first_not_of(whitespace));
    return str;
}

string ConfigFileParser::extractStringProperty(string line)
{
    string st_property;
    size_t semicolon_index = line.find("=");

    if (semicolon_index != string::npos)
    {
        st_property = line.substr(semicolon_index + 1);
        return ltrim(st_property);
    }

    return st_property;
}

int ConfigFileParser::extractIntProperty(string line)
{
    string string_property = extractStringProperty(line);
    int int_property = stoi(string_property);

    return int_property;
}

// Fonction pour parser le fichier texte
vector<Land *> ConfigFileParser::parseBoardConfigFile()
{
    string line;
    ifstream myfile(filename);
    vector<Land *> board;

    if (myfile.is_open())
    {
        cout << "Parsing du fichier: " << filename << endl;
        while (getline(myfile, line))
        {
            cout << "----- Ajout d'une case: " << line << " -----" << endl;
            if (!line.compare("[Depart]"))
            {
                string name;

                while (getline(myfile, line))
                {
                    if (line.find("Nom") != string::npos)
                    {
                        name = extractStringProperty(line);
                    }
                    else
                    {
                        if (!name.empty())
                        {
                            cout << "Instanciation de la case départ" << endl;
                            Start* newStart = new Start(name);
                            board.push_back(newStart);
                        }
                        break;
                    }
                }
            }
            else if (!line.compare("[Propriete]"))
            {
                string name;
                int price = 0;
                string color;

                while (getline(myfile, line))
                {
                    if (line.find("Nom") != string::npos)
                    {
                        name = extractStringProperty(line);
                    }
                    else if (line.find("Prix")  != string::npos)
                    {
                        price = extractIntProperty(line);
                    }
                    else if(line.find("Couleur") != string::npos)
                    {
                        color = extractStringProperty(line);
                    }
                    else if (line.find("Loyers") != string::npos)
                    {
                        cout << "La gestion du loyer n'est pas implémentée" << endl;
                    }
                    else
                    {
                        if (!name.empty() && price != 0 && !color.empty())
                        {
                            cout << "Instanciation des cases propriétés" << endl;
                            RealEstateLand* newRealEstateLand = new RealEstateLand(name, price, color);
                            board.push_back(newRealEstateLand);
                        }
                        break;
                    }
                }
            }
            else if (!line.compare("[Carte]"))
            {
                string name;
                string type;

                while (getline(myfile, line))
                {
                    if (line.find("Nom") != string::npos)
                    {
                        name = extractStringProperty(line);
                    }
                    else if (line.find("Type") != string::npos)
                    {
                        type = extractStringProperty(line);
                    }
                    else
                    {
                        if (!name.empty() && !type.empty())
                        {
                            cout << "Instanciation d'une case: " << type << endl;
                            Type t = !type.compare("communaute") ? Type::COMMUNITY_FUND : Type::LUCK;
                            Card* newCardLand = new Card(name, t);
                            board.push_back(newCardLand);
                        }
                        break;
                    }
                }
            }
            else if (!line.compare("[Gare]"))
            {
                string name;
                int price = 0;

                while (getline(myfile, line))
                {
                    if (line.find("Nom") != string::npos)
                    {
                        name = extractStringProperty(line);
                    }
                    else if (line.find("Prix") != string::npos)
                    {
                        price = extractIntProperty(line);
                    }
                    else if (line.find("Loyers") != string::npos)
                    {
                        cout << "La gestion du loyer n'est pas implémentée" << endl;
                    }
                    else
                    {
                        if (!name.empty() && price != 0)
                        {
                            cout << "Instanciation d'une station" << endl;
                            Station* newStation = new Station(name, price);
                            board.push_back(newStation);
                        }
                        break;
                    }
                }
            }
            else if (!line.compare("[Service publique]"))
            {
                string name;
                int price = 0;

                while (getline(myfile, line))
                {
                    if (line.find("Nom") != string::npos)
                    {
                        name = extractStringProperty(line);
                    }
                    else if (line.find("Prix") != string::npos)
                    {
                        price = extractIntProperty(line);
                    }
                    else
                    {
                        if (!name.empty() && price != 0)
                        {
                            cout << "Instanciation d'un service publique" << endl;
                            PublicService* newService = new PublicService(name, price);
                            board.push_back(newService);
                        }
                        break;
                    }
                }
            }
            else if (!line.compare("[Prison]"))
            {
                string name;

                while (getline(myfile, line))
                {
                    if (line.find("Nom") != string::npos)
                    {
                        name = extractStringProperty(line);
                    }
                    else
                    {
                        if (!name.empty())
                        {
                            cout << "Instanciation d'une prison" << endl;
                            Jail* newJail = new Jail(name);
                            board.push_back(newJail);
                        }
                        break;
                    }
                }
            }
            else if (!line.compare("[Aller prison]"))
            {
                string name;

                while (getline(myfile, line))
                {
                    if (line.find("Nom") != string::npos)
                    {
                        name = extractStringProperty(line);
                    }
                    else
                    {
                        if (!name.empty())
                        {
                            cout << "Instanciation d'une case \"allez en prison\"" << endl;
                            GotoJail* newGotoJail = new GotoJail(name);
                            board.push_back(newGotoJail);
                        }
                        break;
                    }
                }
            }
            else if (!line.compare("[Taxe]"))
            {
                string name;
                int tax;

                while (getline(myfile, line))
                {
                    if (line.find("Nom") != string::npos)
                    {
                        name = extractStringProperty(line);
                    }
                    else if (line.find("Taxe") != string::npos)
                    {
                        tax = extractIntProperty(line);
                    }
                    else
                    {
                        if (!name.empty() && tax != 0)
                        {
                            cout << "Instanciation d'une case de taxe\"" << endl;
                            Tax* newTax = new Tax(name, tax);
                            board.push_back(newTax);
                        }
                        break;
                    }
                }
            }
            else if (!line.compare("[Parc]"))
            {
                string name;

                while (getline(myfile, line))
                {
                    if (line.find("Nom") != string::npos)
                    {
                        name = extractStringProperty(line);
                    }
                    else
                    {
                        if (!name.empty())
                        {
                            cout << "Instanciation d'une case de parc" << endl;
                            Parc* newParc = new Parc(name);
                            board.push_back(newParc);
                        }
                        break;
                    }
                }
            }
            else
            {
                //cout << "Ligne non traitée" << endl;
            }
        }

        myfile.close();
    }

    return board;
}
```

> Ici, on remarque que l’implémentation de cette classe est conséquente, néanmoins elle est utile afin de générer un plateau à la volée. Un avantage concernant cette manière de faire, pourrait être d’avoir la possibilité de pouvoir éditer notre version de jeu du Monopoly. Par exemple, si l’on veux jouer à une version anglaise, il suffirait de créer un nouveau fichier `englishBoard.config` et d’y renseigner la configuration complète d’un plateau de jeu anglais, ainsi tout le code existant ne serait pas abandonné.
> 

***Test:***

Vous trouverez dans la batterie de tests:

- Un test de la classe au complet lors de la génération d’un plateau de jeu et de l’affichage des informations d’une case.

# Classe Land

> Un terrain hérite des propriétés de la classe `BoardGame`.
> 

![Untitled](CPP%20-%20TP6%20b90f789def8f421d82d10c1e7620aba1/Untitled%203.png)

Cette classe devra répondre au diagramme de classe ci dessus qui a été fourni dans le cahier des charges.

***Code:***

Ci dessous sa déclaration

```cpp
#pragma once

#include <string>
#include <iostream>

using namespace std;

enum Type
{
    START,
    REAL_ESTATE_LAND,
    COMMUNITY_FUND,
    PUBLIC_SERVICE,
    STATION,
    LUCK,
    JAIL,
    FREE_PARK,
    GO_TO_JAIL,
    TAX,
};

class Land
{
protected:
    string name;
    Type type;

public:
    Land(string name, Type type);
    virtual ~Land();

    Type getType() const;
    string getName() const;
    virtual void action() const = 0;
};

ostream& operator<<(std::ostream& os, const Land& obj);
```

> Rien de nouveau ici, on notera tout de même que cette classe est abstraite.
> 

Et sa définition

```cpp
#include "land.hpp"

Land::Land(string name, Type type) : name(name), type(type) { }

Land::~Land() {}

string Land::getName() const
{
    return name;
}

Type Land::getType() const
{
    return this->type;
}

ostream& operator<<(ostream& os, const Land& l)
{
    os << "Nom: " << l.getName() << endl;
    os << "Type de la case: ";
    Type type = l.getType();
    switch (type)
    {
    case Type::START:
        os << "Départ" << endl;
        break;
    case Type::JAIL:
        os << "Prison" << endl;
        break;
    case Type::PUBLIC_SERVICE:
        os << "Service public" << endl;
        break;
    case Type::STATION:
        os << "Gare" << endl;
        break;
    case Type::REAL_ESTATE_LAND:
        os << "Terrain achetable" << endl;
        break;

    case Type::COMMUNITY_FUND:
        os << "Caisse de communauté" << endl;
        break;

    case Type::GO_TO_JAIL:
        os << "Aller en prison" << endl;
        break;

    case Type::LUCK:
        os << "Case chance" << endl;
        break;

    case Type::TAX:
        os << "Case de taxe" << endl;
        break;

    case Type::FREE_PARK:
        os << "Parking gratuit" << endl;
        break;

    default:
        os << "Euuhh.... La on a un probleme? jsp, je dis ca, je dis rien..." << endl;
        break;
    }
    return os;
}
```

> Ici, rien de nouveau.
> 

***Test:***

Vous trouverez dans la batterie de tests:

- Un test du constructeur par défaut.
- Des tests des accesseurs et mutateurs.

Passons maintenant à l’implémentation des classes filles de `Land`.

# Classe Card

> La classe `Card` représente les cases du plateau qui font piocher une carte et déclenchent une action
> 

![Untitled](CPP%20-%20TP6%20b90f789def8f421d82d10c1e7620aba1/Untitled%204.png)

Cette classe devra répondre au diagramme de classe ci dessus qui a été fourni dans le cahier des charges.

***Code:***

Voici sa déclaration

```cpp
#pragma once

#include <string>
#include <ostream>
#include "land.hpp"

using namespace std;

class Card : public Land
{
private:

public:
    Card(string name, Type type);
    ~Card() override;

    void action() const override;
};

ostream& operator<<(ostream& os, const Card& c);
```

> Une déclaration qui n’ajoute rien de particulièrement notable en termes de choix techniques ou de conception
> 

Ainsi que sa définition:

```cpp
#include "card.hpp"

Card::Card(string name, Type type) : Land(name, type) { }

Card::~Card() { }

void Card::action() const
{
    cout << "Prendre une carte..." << endl;
}

ostream& operator<<(ostream& os, const Card& c)
{
    os << static_cast<const Land&> (c);
    return os;
}
```

> Ici, on ne notera pas de choix technique particulier car notre implémentation de la méthode `action()` n’est pas complète par manque de temps.
> 

***Test:***

Vous trouverez dans la batterie de tests:

- Un test simple de la classe lors de l’ajout d’une case `Card` au plateau de jeu.

# Classe GoToJail

> La classe `goToJail` permet d’envoyer un joueur en prison.
> 

![Untitled](CPP%20-%20TP6%20b90f789def8f421d82d10c1e7620aba1/Untitled%205.png)

Cette classe devra répondre au diagramme de classe ci dessus qui a été fourni dans le cahier des charges.

***Code:***

Voici sa déclaration

```cpp
#pragma once

#include <string>
#include <ostream>
#include "land.hpp"

using namespace std;

class GotoJail : public Land
{
private:

public:
    GotoJail(string name);
    ~GotoJail() override;

    void action() const override;
};

ostream& operator<<(ostream& os, const GotoJail& gj);
```

> Rien de spécial a signaler.
> 

Ainsi que sa définition:

```cpp
#include "gotoJail.hpp"

GotoJail::GotoJail(string name) : Land(name, Type::GO_TO_JAIL) { }

GotoJail::~GotoJail() { }

void GotoJail::action() const
{
    cout << "Direction la zonzon!" << endl;
}

ostream& operator<<(ostream& os, const GotoJail& gj)
{
    os << static_cast<const Land&> (gj);
    return os;
}
```

> Ici, rien à signaler non plus, il reste la méthode `action()` à implémenter pour amener le joueur sur la case prison du plateau.
> 

 

***Test:***

Vous trouverez dans la batterie de tests:

- Pas de test de la classe `goToJail`, nous n’avons pas eu le temps de lier les fonctionnalités des classes `Player` et `GameMaster` dans nos jeux d’essais.

# Classe Jail

> La classe `Jail` représente la case prison du jeu.
> 

![Untitled](CPP%20-%20TP6%20b90f789def8f421d82d10c1e7620aba1/Untitled%206.png)

Cette classe devra répondre au diagramme de classe ci dessus qui a été fourni dans le cahier des charges.

***Code:***

Voici sa déclaration

```cpp
#pragma once

#include <string>
#include <ostream>
#include "land.hpp"

using namespace std;

class Jail : public Land
{
private:

public:
    Jail(string name);
    ~Jail() override;

    void action() const override;
};

ostream& operator<<(ostream& os, const Jail& j);
```

> Rien de spécial a signaler.
> 

Ainsi que sa définition:

```cpp
#include "jail.hpp"

Jail::Jail(string name) : Land(name, Type::JAIL) { }

Jail::~Jail() { }

void Jail::action() const
{
    cout << "Prendre une carte..." << endl;
}

ostream& operator<<(ostream& os, const Jail& j)
{
    os << static_cast<const Land&> (j);
    return os;
}
```

> Ici, rien à signaler non plus.
> 

 

***Test:***

Vous trouverez dans la batterie de tests:

- Un test simple de la classe lors de l’ajout d’une case `Jail` au plateau de jeu.

# Classe Parc

> La classe `Parc` représente la case parc du jeu.
> 

![Untitled](CPP%20-%20TP6%20b90f789def8f421d82d10c1e7620aba1/Untitled%207.png)

Cette classe devra répondre au diagramme de classe ci dessus qui a été fourni dans le cahier des charges.

***Code:***

Voici sa déclaration

```cpp
#pragma once

#include <string>
#include <ostream>
#include "land.hpp"

using namespace std;

class Parc : public Land
{
private:

public:
    Parc(string name);
    ~Parc() override;

    void action() const override;
};

ostream& operator<<(ostream& os, const Parc& p);
```

> Rien de spécial a signaler.
> 

Ainsi que sa définition:

```cpp
#include "parc.hpp"

Parc::Parc(string name) : Land(name, Type::FREE_PARK) { }

Parc::~Parc() { }

void Parc::action() const
{
    cout << "Passer son tour" << endl;
}

ostream& operator<<(ostream& os, const Parc& p)
{
    os << static_cast<const Land&> (p);
    return os;
}
```

> Ici, rien à signaler non plus.
> 

 

***Test:***

Vous trouverez dans la batterie de tests:

- Un test simple de la classe lors de l’ajout d’une case `Parc` au plateau de jeu.

# Classe Start

> La classe `Start` représente la case départ du jeu.
> 

![Untitled](CPP%20-%20TP6%20b90f789def8f421d82d10c1e7620aba1/Untitled%208.png)

Cette classe devra répondre au diagramme de classe ci dessus qui a été fourni dans le cahier des charges.

***Code:***

Voici sa déclaration

```cpp
#pragma once

#include <string>
#include <ostream>
#include "land.hpp"

using namespace std;

class Start : public Land
{
private:

public:
    Start(string name);
    ~Start() override;

    void action() const override;
};

ostream& operator<<(ostream& os, const Start& s);
```

> Rien de spécial a signaler.
> 

Ainsi que sa définition:

```cpp
#include "start.hpp"

Start::Start(string name) : Land(name, Type::START) { }

Start::~Start() { }

void Start::action() const
{
    cout << "Passer son tour" << endl;
}

ostream& operator<<(ostream& os, const Start& s)
{
    os << static_cast<const Land&> (s);
    return os;
}
```

> Ici, rien à signaler non plus.
> 

 

***Test:***

Vous trouverez dans la batterie de tests:

- Un test simple de la classe lors de l’ajout d’une case `Start` au plateau de jeu.

# Classe Tax

> La classe `Tax` représente la case impôts du jeu.
> 

![Untitled](CPP%20-%20TP6%20b90f789def8f421d82d10c1e7620aba1/Untitled%209.png)

Cette classe devra répondre au diagramme de classe ci dessus qui a été fourni dans le cahier des charges.

***Code:***

Voici sa déclaration

```cpp
#pragma once

#include <string>
#include <ostream>
#include "land.hpp"

using namespace std;

class Tax : public Land
{
private:
    int tax = 0;

public:
    Tax(string name, int tax);
    ~Tax() override;

    void action() const override;
};

ostream& operator<<(ostream& os, const Tax& t);
```

> Rien de spécial a signaler.
> 

Ainsi que sa définition:

```cpp
#include "tax.hpp"

Tax::Tax(string name, int tax) : Land(name, Type::TAX), tax(tax) { }

Tax::~Tax() { }

void Tax::action() const
{
    cout << "Payer la taxe" << endl;
}

ostream& operator<<(ostream& os, const Tax& t)
{
    os << static_cast<const Land&> (t);
    return os;
}
```

> Ici, rien à signaler non plus.
> 

 

***Test:***

Vous trouverez dans la batterie de tests:

- Un test simple de la classe lors de l’ajout d’une case `Tax` au plateau de jeu.

# Classe BuyableLand

> Maintenant que nous avons parlé des autres classes héritant de `Land`, nous allons parler de sa dernière héritière qui est `BuyableLand`.
> 

![Untitled](CPP%20-%20TP6%20b90f789def8f421d82d10c1e7620aba1/Untitled%2010.png)

Cette classe devra répondre au diagramme de classe ci dessus qui a été fourni dans le cahier des charges.

***Code:***

Voici sa déclaration

```cpp
#pragma once

#include <string>
#include <iostream>
#include "land.hpp"
#include "player.hpp"

using namespace std;

class BuyableLand : public Land
{
public:
    BuyableLand(string name, Type type, int price);

    virtual int getRent() const = 0;

    int getPrice() const;
    bool isPurchased() const;
    Player* getOwner() const;

protected:
    int price;
    int rent;
    Player *owner = nullptr;
};

ostream& operator<<(ostream& os, const BuyableLand& bl);
```

> Cette fois-ci, nous notons la présence d’une fonction virtuelle pure ce qui rend la classe abstraite.
Nous notons également l’existence d’un pointeur sur joueur afin de pouvoir attribuer ces cases à un joueur ou non. Au début de la partie les terrains achetables n’ont pas de propriétaires.
> 

Ainsi que sa définition:

```cpp
#include <stdexcept>
#include "buyableLand.hpp"

BuyableLand::BuyableLand(string name, Type type, int price) : Land(name, type), price(price), rent(price) { };

int BuyableLand::getPrice() const
{
    return this->price;
}

bool BuyableLand::isPurchased() const
{
    return this->owner != nullptr ? true : false;
}

Player* BuyableLand::getOwner() const
{
    if (this->owner == nullptr)
        throw runtime_error("Aucun propriétaire n'est défini pour ce terrain.");
    return this->owner;
}

ostream& operator<<(ostream& os, const BuyableLand& bl)
{
    os << static_cast<const Land&> (bl);
    os << "     Prix: " << bl.getPrice() << endl;
    os << "     Propriétaire: ";
    try
    {
        os << bl.getOwner() << endl;
    }
    catch(const exception& e)
    {
        os << "Aucun" << endl;
    }
    return os;
}
```

> Ici, on note l’usage du pointeur sur propriétaire afin de renseigner si la case achetable est effectivement achetée ou bien disponible.
> 

 

***Test:***

Vous trouverez dans la batterie de tests:

- Un test d’affichage des caractéristiques d’un terrain et donc de son propriétaire si le terrain est acheté.

# Classe PublicService

> La classe `PublicService` représente les cases des services publiques tels que la compagnie des eaux ou de l’électricité.
> 

![Untitled](CPP%20-%20TP6%20b90f789def8f421d82d10c1e7620aba1/Untitled%2011.png)

Cette classe devra répondre au diagramme de classe ci dessus qui a été fourni dans le cahier des charges.

***Code:***

Voici sa déclaration

```cpp
#pragma once

#include <string>
#include <ostream>
#include "buyableLand.hpp"

using namespace std;

class PublicService : public BuyableLand
{
private:

public:
    PublicService(string name, int price);
    ~PublicService() override;

    int getRent() const override;
    void action() const override;
};

ostream& operator<<(ostream& os, const PublicService& ps);
```

> Rien de spécial a signaler.
> 

Ainsi que sa définition:

```cpp
#include "publicService.hpp"

PublicService::PublicService(string name, int price) : BuyableLand(name, Type::PUBLIC_SERVICE, price)
{

}

PublicService::~PublicService()
{

}

int PublicService::getRent() const
{
    return this->rent;
}

void PublicService::action() const
{
    cout << "action!" << endl;
}

ostream& operator<<(ostream& os, const PublicService& ps)
{
    os << static_cast<const BuyableLand&> (ps);
    os << "         Loyer: " << ps.getRent() << endl;
    return os;
}
```

> Ici, rien à signaler non plus.
> 

 

***Test:***

Vous trouverez dans la batterie de tests:

- Un test simple de la classe lors de l’ajout d’une case `PublicService` au plateau de jeu.

# Classe Station

> La classe `Station` représente les cases gares du jeu.
> 

![Untitled](CPP%20-%20TP6%20b90f789def8f421d82d10c1e7620aba1/Untitled%2012.png)

Cette classe devra répondre au diagramme de classe ci dessus qui a été fourni dans le cahier des charges.

***Code:***

Voici sa déclaration

```cpp
#pragma once

#include <string>
#include <ostream>
#include "buyableLand.hpp"

using namespace std;

class Station : public BuyableLand
{
private:

public:
    Station(string name, int price);
    ~Station() override;

    int getRent() const override;
    void action() const override;
};

ostream& operator<<(ostream& os, const Station& s);
```

> Rien de spécial a signaler.
> 

Ainsi que sa définition:

```cpp
#include "station.hpp"

Station::Station(string name, int price) : BuyableLand(name, Type::STATION, price)
{

}

Station::~Station()
{

}

int Station::getRent() const
{
    return this->rent;
}

void Station::action() const
{
    cout << "action!" << endl;
}

ostream& operator<<(ostream& os, const Station& s)
{
    os << static_cast<const BuyableLand&> (s);
    os << "         Loyer: " << s.getRent() << endl;
    return os;
}
```

> Ici, rien à signaler non plus.
> 

 

***Test:***

Vous trouverez dans la batterie de tests:

- Un test simple de la classe lors de l’ajout d’une case `Station` au plateau de jeu.

# Classe Player

> La classe `Player` implémente les joueurs de Monopoly.
> 

![Untitled](CPP%20-%20TP6%20b90f789def8f421d82d10c1e7620aba1/Untitled%2013.png)

Cette classe devra répondre au diagramme de classe ci dessus qui a été fourni dans le cahier des charges.

***Code:***

Voici sa déclaration

```cpp
#pragma once

#include <string>
#include <iostream>

using namespace std;

class Player
{
    private:

        string name;
        int financialAssets;
        int nbDouble;
        int position;

    public:

        Player(string newName, int newFinancialAssets, int nbDouble, int position);

        void buyHouse();
        void buyHotel();
        void buyRealEstateLand();

        string getName() const;
        int getFinancialAssets() const;
        int getNbDouble() const;
        int getPosition () const;

        void setPosition(int newPosition);
        void setNbDouble(int newNbDouble);

        friend ostream& operator<<(ostream& os, const Player& player);
};
```

> Rien de spécial a signaler.
> 

Ainsi que sa définition:

```cpp
#include "player.hpp"

Player::Player(string newName, int newFinancialAssets, int nbDouble, int position)
{
    this->name = newName;
    this->financialAssets = newFinancialAssets;
    this->nbDouble = nbDouble;
    this->position = position;
}

void Player::buyHouse()
{

}

void Player::buyHotel()
{

}

void Player::buyRealEstateLand()
{

}

string Player::getName() const
{
    return this->name;
}

int Player::getFinancialAssets() const
{
    return this->financialAssets;
}

int Player::getNbDouble() const
{
    return this->nbDouble;
}

int Player::getPosition () const
{
    return this->position;
}

void Player::setPosition(int newPosition)
{
    this->position = newPosition;
}

void Player::setNbDouble(int newNbDouble)
{
    this->nbDouble = newNbDouble;
}

ostream& operator<<(ostream& os, const Player& player)
{
    os << "Nom du joueur :" << player.getName() << endl;
    os << "     Patrimoine Financier : " <<player.getFinancialAssets() << endl;
    os << "     Nombre de doubles consécutifs : " <<player.getNbDouble() << endl;
    os << "     Position : " <<player.getPosition() << endl;

    return os;
}
```

> Ici, rien à signaler non plus. La gestion des doubles initialement prévue pour une classe `Dice` se fera dans la classe `GameMaster` directement.
> 

 

***Test:***

Vous trouverez dans la batterie de tests:

- Des tests pour la classe `Player` existent sur la branche `cocobis` de notre dépôt, malheureusement nous n’avons pas eu le temps des les ajouter lors de la fusion de nos travaux (certains tests du `GameMaster` composé de la classe `Player` étaient incomplets c’est pourquoi nous n’avons pas choisi de les intégrer tout de suite).

# Classe GameMaster

> La classe `GameMaster` effectue le séquencement du jeu.
> 

![Untitled](CPP%20-%20TP6%20b90f789def8f421d82d10c1e7620aba1/Untitled%2014.png)

Cette classe devra répondre au diagramme de classe ci dessus qui a été fourni dans le cahier des charges.

***Code:***

Voici sa déclaration

```cpp
#pragma once

#include <iostream>
#include <vector>

#include "player.hpp"

using namespace std;

class GameMaster
{
    private:

        int nbPlayers;
        int dice1;
        int dice2;
        vector<Player> Players;

    public:

        GameMaster();

        void Game();
        void startGame();
        void movePlayerToPosition(Player player, int position);
        void movePlayerFromPosition(Player player, int movement);
        void goToHornyJail(Player horny);

        Player getPlayer(int i);
        int getDice1Number();
        int getDice2Number();

        int newDiceRoll();

        bool checkDiceForDouble(int dice1, int dice2);
        bool askForEndOfTurn();
};

enum GamePhase
{
    HOW_MANY_PLAYERS = 0,
    NEW_GAME_TURN,
    DICE_ROLL
};
```

> On note la création d’une `enum` afin de gérer les différentes phases de jeu.
De même, on peut remarquer la présence d’un vecteur de joueurs, ce qui va permettre d’itérer sur les joueurs à chaque tour de jeu ainsi que d’accéder aux joueurs en fonction de leur indice.
Enfin, on note différentes fonctions plus ou moins liées qui seront assez différentes à implémenter.
> 

Ainsi que sa définition:

```cpp
#include "gameMaster.hpp"

// Constructor
GameMaster::GameMaster()
{
    this->nbPlayers = 0;
    this->dice1 = 0;
    this->dice2 = 0;
}

// Begging of a game
void GameMaster::startGame()
{
    cout << "Combien y-a-t'il de joueurs ?" << endl;
    cin >> this->nbPlayers;

    if (this->nbPlayers > 8)
    {
        return;
    }

    string name;
    for (int i = 0; i < this->nbPlayers; i++)
    {
        cout << "Nom du joueur ?" << endl;
        cin >> name;
        Player joueur_i(name, 1500, 0, 0);

        Players.push_back(joueur_i);
    }
}

// Moves a player to a specific position
void GameMaster::movePlayerToPosition(Player player, int position)
{
    player.setPosition(position);
}

// Moves a player from his current position
void GameMaster::movePlayerFromPosition(Player player, int movement)
{
    player.setPosition(player.getPosition() + movement);
}

// Generates a rand number modulo 6 as a new dice roll
int GameMaster::newDiceRoll()
{
    return rand() % 6;
}

// Checks if two dice rolls are equals
bool GameMaster::checkDiceForDouble(int dice1, int dice2)
{
    return (dice1 == dice2) ? true : false;
}

// Returns an instance of player
Player GameMaster::getPlayer(int i)
{
    return this->Players[i];
}

// Getter for the first dice
int GameMaster::getDice1Number()
{
    return this->dice1;
}

// Getter for the second dice
int GameMaster::getDice2Number()
{
    return this->dice2;
}

// Moves a player directly to the jail
void GameMaster::goToHornyJail(Player horny)
{
    int coordinates = 10;
    movePlayerToPosition(horny, coordinates);
}

// ask if the player's turn is effectively finished before starting a new player's turn
bool GameMaster::askForEndOfTurn()
{
    string yesOrNo;
    cout << "End of turn (Y/N)." << endl;
    cin >> yesOrNo;

    if(yesOrNo == "Y" || yesOrNo == "y")
    {
        return true;
    }
    else
    {
        return false;
    }
}

// The main game sequence
void GameMaster::Game()
{
    GamePhase gp = GamePhase::HOW_MANY_PLAYERS;
    switch (gp)
    {
        case GamePhase::HOW_MANY_PLAYERS:
            cout << "Lancement du jeu !" << endl;
            startGame();
            gp = GamePhase::NEW_GAME_TURN;

        case GamePhase::NEW_GAME_TURN:

            for (int j=0; j < this->nbPlayers; j++)
            {
                cout << "Début d'un tour de jeu pour : " << this->getPlayer(j).getName() << "." << endl;

                this->dice1 = newDiceRoll();
                cout << "Résultat du premier dé : " << dice1 << "." << endl;

                this->dice2 = newDiceRoll();
                cout << "Résultat du deuxième dé : " << dice2 << "." << endl;

                if(checkDiceForDouble(this->dice1, this->dice2))
                {
                    cout << this->getPlayer(j).getName() << " a fait un double !" << endl;

                    this->getPlayer(j).setNbDouble((this->getPlayer(j).getNbDouble() + 1));

                    cout << "Ce joueur cumule un total de " << this->getPlayer(j).getNbDouble() << " double(s)." << endl;
                    if (this->getPlayer(j).getNbDouble() == 3)
                    {
                        cout << "Go to horny jail " << this->getPlayer(j).getName() << "." << endl;
                        this->goToHornyJail(this->getPlayer(j));

                        // reset the Player's Nb of double
                        this->getPlayer(j).setNbDouble(0);
                        cout << this->getPlayer(j).getName() << " voit son nombre de doubles être remis à " << this->getPlayer(j).getNbDouble() << "." << endl;
                    }
                }

                this->getPlayer(j).setPosition(dice1 + dice2); //todo case courante + dés

                cout << this->getPlayer(j).getName() << " est maintenant sur la case " << this->getPlayer(j).getPosition() << "." << endl;

                askForEndOfTurn();
            }
        break;

        default:
            break;

    }
}
```

> Outre les différents accesseurs et les mutateurs, on note la présence de fonctions spécifiques :
-  `startGame()` : permet d’initialiser le nombre de joueurs et donc d’agrandir la taille du vecteurs de joueurs en conséquence.
- `newDiceRoll()` : permet de tirer un nombre aléatoire modulo 6 et donc de reproduire un jet de dé.
- `checkDiceForDouble()` : renvoie `vrai` si les deux tirages de dés du tour en cours sont égaux, `faux` sinon.
- `getPlayer()` : qui renvoie un joueur et permet d’accéder a un joueur en fonction de son indice dans le vecteur de joueurs ou bien en fonction de ses attributs comme le nom.
- `askForEndOfTurn()` : permet de confirmer la fin du tour afin que le maitre du jeu ne soit pas à enchainer les tours de jeu à sa propre vitesse sans que les joueurs ne puisse suivre. 
- `game()` : permet de lancer le déroulement du jeu.
> 

 

***Test:***

Vous trouverez dans la batterie de tests:

- Des tests pour la classe `GameMaster` existent sur la branche `cocobis` de notre dépôt, malheureusement certains tests sont incomplets c’est pourquoi nous n’avons pas choisi de les intégrer tout de suite.

# Classe RealEstate

> La classe `RealEstate` est l’équivalent de la banque qui est officiellement tenue par un joueur dans les règles du jeu physique.
> 

![Untitled](CPP%20-%20TP6%20b90f789def8f421d82d10c1e7620aba1/Untitled%2015.png)

Cette classe devra répondre au diagramme de classe ci dessus qui a été fourni dans le cahier des charges.

***Code:***

Voici sa déclaration

```cpp
#pragma once
#include <iostream>

class RealEstate {
public:
    // Constructeur virtuel
    RealEstate() {}
    // Destructeur virtuel
    virtual ~RealEstate() {}

    // Méthode virtuelle pour imprimer un bien immobilier
    virtual void print() const = 0;
    // Méthode virtuelle pour obtenir le prix d'un bien immobilier
    virtual int getPrice() const = 0;
};
```

> Rien de spécial a signaler.
> 

Cette classe ne possède pas de définition:

 

***Test:***

Vous trouverez dans la batterie de tests:

- Les tests d’accès au prix d’une maison ou d’un hôtel en fonction de la case.

# Classe Hotel

> La classe `Hotel` permet de donner le prix d’un hôtel.
> 

![Untitled](CPP%20-%20TP6%20b90f789def8f421d82d10c1e7620aba1/Untitled%2016.png)

Cette classe devra répondre au diagramme de classe ci dessus qui a été fourni dans le cahier des charges.

***Code:***

Voici sa déclaration

```cpp
#pragma once

#include "realEstate.hpp"

#include <iostream>

using namespace std; 

class Hotel :public RealEstate 
{
	private:
	    int PriceHotel;
	public:
	    // Constructeur
	    Hotel();
	    // Destructeur
	    ~Hotel();
	    // Getter pour obtenir le prix d'une hotel
	    int getPrice() const override;
	    // Méthode pour imprimer une hotel
	    void print() const override;
};
```

> Rien de spécial a signaler.
> 

Ainsi que sa définition:

```cpp
#include "hotel.hpp"

#include <iostream>

//Constructeur
Hotel::Hotel()
{
    Hotel::PriceHotel = 250;
}

//Destructeur 
Hotel::~Hotel()
{
}

// Getter pour obtenir le prix d'une hotel
int Hotel::getPrice() const
{
    return Hotel::PriceHotel;
}

// Print d'un hotel
void Hotel::print() const
{
    std::cout << "Hotel" << std::endl;
    std::cout << "Prix: " << getPrice() << std::endl;
}
```

> Ici, rien à signaler non plus.
> 

 

***Test:***

Vous trouverez dans la batterie de tests:

- Un test d’affichage du prix d’un hôtel.

# Classe House

> La classe `House` permet de donner le prix d’une maison.
> 

![Untitled](CPP%20-%20TP6%20b90f789def8f421d82d10c1e7620aba1/Untitled%2017.png)

Cette classe devra répondre au diagramme de classe ci dessus qui a été fourni dans le cahier des charges.

***Code:***

Voici sa déclaration

```cpp
#pragma once

#include "realEstate.hpp"

#include <iostream>

using namespace std; 

class House : public RealEstate
{
	private:
	    int PriceHouse;
	public:
	    // Constructeur
	    House();
	    // Destructeur
	    ~House();
	    // Getter pour obtenir le prix d'une maison
	    int getPrice() const override;
	    // Méthode pour imprimer une maison
	    void print() const override;
};
```

> Rien de spécial a signaler.
> 

Ainsi que sa définition:

```cpp
#include "house.hpp"

#include <iostream>

//Constructeur
House::House()
{
    House::PriceHouse = 200;
}

//Destructeur 
House::~House()
{
}

// Getter pour obtenir le prix d'une hotel
int House::getPrice() const
{
    return House::PriceHouse;
}

//Print d'une maison
void House::print() const
{
    std::cout << "Maison" << std::endl;
    std::cout << "Prix: " << getPrice() << std::endl;
}
```

> Ici, rien à signaler non plus.
> 

 

***Test:***

Vous trouverez dans la batterie de tests:

- Un test d’affichage du prix d’une maison.

# Conclusion :

Ce projet de reproduction d'un Monopoly en C++ présente une structure cohérente avec l'utilisation de classes telles que `BoardGame`, `Land`, `BuyableLand` et `GameMaster` pour gérer les différents aspects du jeu. 

Les fonctionnalités essentielles telles que le déplacement des joueurs, la gestion des doubles, et la possibilité de mettre un joueur en prison ont été partiellement implémentées. 

Cependant, des améliorations pourraient être apportées, notamment en enrichissant les mécanismes de jeu et en améliorant l'interaction utilisateur. 

En résumé, ce travail constitue une base solide pour un projet de Monopoly en C++, mais il pourrait être étendu et affiné pour une expérience de jeu plus complète et immersive.