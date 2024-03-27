#include <iostream>
#include "realEstateLand.hpp"

using namespace std;

int main()
{
    cout << "Bonjour monde!" << endl;
    RealEstateLand my_land("Mairie de doulon", 666, Color::GREEN);
    cout << my_land << endl;

    return 0;
}
