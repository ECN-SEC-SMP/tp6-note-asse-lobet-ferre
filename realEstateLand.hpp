#pragma once

#include <string>
#include "buyableLand.hpp"

enum class Color
{
    PURPLE,
    GREY,
    PINK,
    ORANGE,
    RED,
    YELLOW,
    GREEN,
    BLUE,
};

class RealEstateLand : public BuyableLand
{
private:
    int rent;
    Color color;

public:
    RealEstateLand(string name, int price, Color color);
    RealEstateLand(string name, int price, string color);
    ~RealEstateLand() override;

    Color getColor() const;
    int getRent() const override;
    void action() const override;
};

ostream& operator<<(ostream& os, const RealEstateLand& rel);