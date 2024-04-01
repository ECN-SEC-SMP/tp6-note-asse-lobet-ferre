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