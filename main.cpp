#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "animal.h"
#include "dog.h"
#include "cat.h"
#include "bird.h"

int main()
{
    // This vector will store pointers to Animal objects
    // We use pointers because Animal is an abstract class (has pure virtual functions)
    // and we want to store different types of animals (Dog, Cat, Bird) in the same list
    std::vector<Animal *> animals;

    // Open the file that contains animal data
    std::ifstream file("animals.txt");
    if (!file)
    {
        std::cout << "Error opening file animals.txt" << std::endl;
        return 1;
    }

    // Read each line from the file and create the appropriate animal objects
    std::string type;
    while (file >> type) // Read the type of animal first
    {
        // All animals have a name and age
        std::string name;
        int age;

        // Read the common attributes
        file >> name >> age;

        // Create the specific type of animal based on the type read
        if (type == "Dog")
        {
            std::string breed;
            file >> breed; // Dogs have an extra breed attribute
            animals.push_back(new Dog(name, age, breed));
        }
        else if (type == "Cat")
        {
            std::string indoorStr;
            file >> indoorStr; // Cats have an indoor/outdoor status
            // Convert string to boolean: "true"/"1" = true, anything else = false
            bool indoor = (indoorStr == "true" || indoorStr == "1");
            animals.push_back(new Cat(name, age, indoor));
        }
        else if (type == "Bird")
        {
            std::string flyStr;
            file >> flyStr; // Birds have flying ability
            bool fly = (flyStr == "true" || flyStr == "1");
            animals.push_back(new Bird(name, age, fly));
        }
    }
    file.close(); // Always close files when done

    // Main menu loop - keeps showing menu until user chooses to exit
    int choice;
    do
    {
        // Display the menu options
        std::cout << "\nPet Shelter Menu:\n";
        std::cout << "1. Display all animals\n";
        std::cout << "2. Make all animals speak\n";
        std::cout << "3. Display animals older than a given age\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter choice: ";
        std::cin >> choice;

        // Handle the user's choice
        if (choice == 1)
        {
            // Loop through all animals and display their information
            for (auto a : animals) // 'auto' automatically figures out the type
            {
                a->display(); // Call the display method (different for each animal type)
                std::cout << std::endl;
            }
        }
        else if (choice == 2)
        {
            // Make each animal "speak" by calling their speak method
            for (auto a : animals)
            {
                a->speak(); // This will print different sounds for different animals
            }
        }
        else if (choice == 3)
        {
            // Ask user for minimum age and show animals older than that
            int minAge;
            std::cout << "Enter minimum age: ";
            std::cin >> minAge;
            bool found = false; // Track if we found any animals
            for (auto a : animals)
            {
                if (a->getAge() > minAge) // Check if animal is old enough
                {
                    a->display();
                    std::cout << std::endl;
                    found = true;
                }
            }
            if (!found)
            {
                std::cout << "No animals found older than " << minAge << " years.\n";
            }
        }
        else if (choice == 4)
        {
            // Exit - the loop will end
        }
        else
        {
            std::cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 4); // Keep looping until user chooses 4

    // Clean up memory - very important when using 'new'
    // Delete all the animal objects we created with 'new'
    for (auto a : animals)
    {
        delete a; // Free the memory
    }
    animals.clear(); // Clear the vector (though not strictly necessary here)

    return 0;
}