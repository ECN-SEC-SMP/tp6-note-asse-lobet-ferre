#pragma once

#include <array>

// Forward declaration de la classe Box
class Box;

class Plateau {
private:
    std::array<Box*, 40> global; // Utilisation de pointeurs pour permettre la polymorphie
public:
    // Constructeur
    Plateau();
    // Destructeur
    ~Plateau();
    // Getter pour obtenir une case du plateau par son index
    Box* getBoxAt(int index) const;
};
