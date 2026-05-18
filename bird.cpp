#include "bird.h"
#include <iostream>

// Bird class implementation

// Constructor: calls Animal constructor, then sets flying ability
Bird::Bird(std::string n, int a, bool fly) : Animal(n, a), canFly(fly) {}

// Override display: show base info plus flying ability
void Bird::display() const
{
    Animal::display(); // Name and age
    std::cout << "Can Fly: " << (canFly ? "Yes" : "No") << std::endl;
}

// Override speak: birds say "Chirp!"
void Bird::speak()
{
    std::cout << name << " says: Chirp!" << std::endl;
}