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