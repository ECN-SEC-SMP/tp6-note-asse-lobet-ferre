#pragma once

#include <string>
#include <ostream>
#include "land.hpp"

using namespace std;

class Parc : public Land
{
private:

public:
    Parc(string name);
    ~Parc() override;

    void action() const override;
};

ostream& operator<<(ostream& os, const Parc& p);