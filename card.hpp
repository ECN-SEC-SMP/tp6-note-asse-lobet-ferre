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

ostream& operator<<(ostream& os, const Card& s);