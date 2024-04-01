#pragma once

#include <string>
#include <iostream>

using namespace std;

enum class Type
{
    START,
    REAL_ESTATE_LAND,
    COMMUNITY_FUND,
    PUBLIC_SERVICE,
    STATION,
    LUCK,
    JAIL,
    FREE_PARK,
    GO_TO_JAIL,
    TAX,
};

class Land
{
protected:
    string name;
    Type type;

public:
    Land(string name, Type type);
    virtual ~Land();

    Type getType() const;
    string getName() const;
    virtual void action() const = 0;
};

ostream& operator<<(std::ostream& os, const Land& obj);