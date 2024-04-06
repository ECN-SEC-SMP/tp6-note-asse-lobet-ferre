#pragma once

#include <string>

using namespace std;

class Player
{
    private:

        string name;
        int financialAssets;
        int movement;
        int nbDouble;
        int position;

    public:

        Player(string newName, int newFinancialAssets, int movement, int nbDouble, int position);

        void buyHouse();
        void buyHotel();
        void buyRealEstateLand();

        string getName() const;
        int getFinancialAssets() const;
        int getMovement() const;
        int getNbDouble() const;
        int getPosition () const;

        void setMovement(int m);

        friend ostream& operator<<(ostream& os, const Player& player);
};