#pragma once

#include <string>
#include <ostream>
#include "buyableLand.hpp"

using namespace std;

class Station : public BuyableLand
{
private:
    int rent;

public:
    Station(string name, int price);
    ~Station() override;

    int getRent() const override;
    void action() const override;
};

ostream& operator<<(ostream& os, const Station& s);