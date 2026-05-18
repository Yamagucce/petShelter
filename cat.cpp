#include <iomanip>
#include <iostream>
#include "cat.h"

// Cat class implementation

// Constructor: calls Animal constructor, then sets indoor status
Cat::Cat(std::string n, int a, bool indoor) : Animal(n, a), isIndoor(indoor) {}

// Override display: show base info plus indoor status
void Cat::display() const
{
    Animal::display(); // Name and age
    std::cout << "Indoor: " << (isIndoor ? "Yes" : "No") << std::endl;
}

// Override speak: cats say "Meow!"
void Cat::speak()
{
    std::cout << name << " says: Meow!" << std::endl;
}
