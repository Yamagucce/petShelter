#ifndef DOG_H
#define DOG_H

#include "animal.h"

// Dog class inherits from Animal (public inheritance)
// This means Dog IS-AN Animal and can use all public/protected Animal methods
// It adds its own specific attribute (breed) and overrides some methods
class Dog : public Animal
{
private:
    std::string breed; // Dogs have a specific breed

public:
    // Constructor: takes name, age (from Animal), and breed (Dog-specific)
    Dog(std::string n, int a, std::string b);

    // Override the display method to include breed information
    void display() const override;

    // Override the speak method to make dog sounds
    void speak() override;
};

#endif