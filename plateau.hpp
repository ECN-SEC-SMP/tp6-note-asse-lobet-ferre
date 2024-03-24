#pragma once

#include <array>

// Forward declaration de la classe Box
class Box;

class Plateau {
private:
    std::array<Box*, 40> plateau; // Utilisation de pointeurs pour permettre la polymorphie
public:
    // Constructeur
    Plateau();
    // Destructeur
    ~Plateau();
};
