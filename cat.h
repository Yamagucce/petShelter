#ifndef CAT_H
#define CAT_H

#include "animal.h"

// Cat class inherits from Animal
// It has an additional attribute for indoor/outdoor status
class Cat : public Animal
{
private:
    bool isIndoor; // true if cat is indoor-only, false if outdoor

public:
    // Constructor: takes name, age, and indoor status
    Cat(std::string n, int a, bool indoor);

    // Override display to show indoor status
    void display() const override;

    // Override speak to make cat sounds
    void speak() override;
};

#endif