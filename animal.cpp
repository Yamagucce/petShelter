#include "animal.h"
#include <iostream>

// Animal class implementation

// Constructor: initializes the name and age member variables
// Uses an initializer list (: name(n), age(a)) which is efficient
Animal::Animal(std::string n, int a) : name(n), age(a) {}

// Virtual destructor: called when an Animal object is destroyed
// Virtual ensures derived class destructors are called properly
Animal::~Animal() {}

// Virtual display method: shows basic information about any animal
// This can be overridden by derived classes to show more specific info
void Animal::display() const
{
    std::cout << "Name: " << name << ", Age: " << age << std::endl;
}