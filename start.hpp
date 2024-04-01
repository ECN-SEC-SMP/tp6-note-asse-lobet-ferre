#pragma once

#include <string>
#include <ostream>
#include "land.hpp"

using namespace std;

class Start : public Land
{
private:

public:
    Start(string name);
    ~Start() override;

    void action() const override;
};

ostream& operator<<(ostream& os, const Start& s);