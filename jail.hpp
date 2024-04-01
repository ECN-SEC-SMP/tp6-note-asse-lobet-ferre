#pragma once

#include <string>
#include <ostream>
#include "land.hpp"

using namespace std;

class Jail : public Land
{
private:

public:
    Jail(string name);
    ~Jail() override;

    void action() const override;
};

ostream& operator<<(ostream& os, const Jail& s);