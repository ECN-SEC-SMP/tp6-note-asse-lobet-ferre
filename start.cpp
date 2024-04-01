#include "start.hpp"

Start::Start(string name) : Land(name, Type::START) { }

Start::~Start() { }

void Start::action() const
{
    cout << "Passer son tour" << endl;
}

ostream& operator<<(ostream& os, const Start& s)
{
    os << static_cast<const Land&> (s);
    return os;
}