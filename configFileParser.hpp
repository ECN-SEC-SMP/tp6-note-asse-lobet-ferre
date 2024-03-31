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
