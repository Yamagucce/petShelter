#include "dog.h"
#include <iostream>

// Dog class implementation

// Constructor: calls Animal constructor with name and age,
// then initializes the breed member
Dog::Dog(std::string n, int a, std::string b) : Animal(n, a), breed(b) {}

// Override display method: first call the base class display(),
// then add the dog-specific information (breed)
void Dog::display() const
{
    Animal::display(); // Show name and age from base class
    std::cout << "Breed: " << breed << std::endl;
}

// Override speak method: dogs say "Woof!"
void Dog::speak()
{
    std::cout << name << " says: Woof!" << std::endl;
}