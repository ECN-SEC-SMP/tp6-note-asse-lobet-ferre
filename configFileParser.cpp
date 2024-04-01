#include <fstream>
#include <iostream>
#include "configFileParser.hpp"
#include "realEstateLand.hpp"
#include "station.hpp"

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
                            cout << "Instanciation de la case départ pas encore gérée" << endl;
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
                            RealEstateLand* new_real_estate_land = new RealEstateLand(name, price, color);
                            board.push_back(new_real_estate_land);
                            break;
                        }
                    }
                }
            }
            else if (!line.compare("[Communaute]"))
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
                            cout << "Instanciation des cases communauté pas encore gérée" << endl;
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
                            Station* new_station = new Station(name, price);
                            board.push_back(new_station);
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