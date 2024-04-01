#pragma once

#include <string>
#include <ostream>
#include "land.hpp"

using namespace std;

class Tax : public Land
{
private:
    int tax = 0;

public:
    Tax(string name, int tax);
    ~Tax() override;

    void action() const override;
};

ostream& operator<<(ostream& os, const Tax& t);