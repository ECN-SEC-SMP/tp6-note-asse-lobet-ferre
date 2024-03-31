#pragma once

#include <string>
#include <iostream>

using namespace std;

enum class Type
{
    START,
    JAIL,
    PUBLIC_SERVICE,
    STATION,
    REAL_ESTATE_LAND
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