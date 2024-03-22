#pragma once

#include <string>

using namespace std;

class Joueur
{
    public:
        string name;
        int financialAssets;
        int position;

    protected:

    private:

        Joueur(string newName, int newFinancialAssets);

        int const getPlayerPosition();

        void buyHouse();
        void buyHotel();
        void buyRealEstateLand();
};