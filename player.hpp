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

        void setPosition(int m);

        friend ostream& operator<<(ostream& os, const Player& player);
};
