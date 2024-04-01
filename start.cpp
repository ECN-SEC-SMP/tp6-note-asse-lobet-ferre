#include "start.hpp"

Start::Start(string name) : Land(name, Type::START) { }

Start::~Start() { }

void Start::action() const
{
    cout << "Passer son tour" << endl;
}