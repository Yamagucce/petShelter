#ifndef BIRD_H
#define BIRD_H

#include "animal.h"

// Bird class inherits from Animal
// It has an additional attribute for flying ability
class Bird : public Animal
{
private:
    bool canFly; // true if bird can fly, false if it cannot

public:
    // Constructor: takes name, age, and flying ability
    Bird(std::string n, int a, bool fly);

    // Override display to show flying ability
    void display() const override;

    // Override speak to make bird sounds
    void speak() override;
};

#endif