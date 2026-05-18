#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>

// This is the base class for all animals in our pet shelter
// It contains common attributes and methods that all animals share
class Animal
{
protected: // Protected means derived classes can access these, but outside code cannot
    std::string name; // Every animal has a name
    int age;          // Every animal has an age

public:
    // Constructor: called when creating a new Animal object
    Animal(std::string n, int a);

    // Virtual destructor: allows proper cleanup when deleting derived class objects
    virtual ~Animal();

    // Getter method to get the age (const means it doesn't modify the object)
    int getAge() const { return age; }

    // Virtual method: can be overridden by derived classes
    // Displays basic information about the animal
    virtual void display() const;

    // Pure virtual method: MUST be overridden by derived classes
    // The = 0 means there's no default implementation
    virtual void speak() = 0;
};

#endif