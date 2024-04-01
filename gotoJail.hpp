#pragma once

#include <string>
#include <ostream>
#include "land.hpp"

using namespace std;

class GotoJail : public Land
{
private:

public:
    GotoJail(string name);
    ~GotoJail() override;

    void action() const override;
};

ostream& operator<<(ostream& os, const GotoJail& gj);