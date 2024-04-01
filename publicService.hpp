#pragma once

#include <string>
#include <ostream>
#include "buyableLand.hpp"

using namespace std;

class PublicService : public BuyableLand
{
private:

public:
    PublicService(string name, int price);
    ~PublicService() override;

    int getRent() const override;
    void action() const override;
};

ostream& operator<<(ostream& os, const PublicService& ps);