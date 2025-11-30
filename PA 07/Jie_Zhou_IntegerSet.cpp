#include <iostream>
#include <vector>
#include "Jie_Zhou_IntegerSet.h"

using namespace std;

// Initialize set with 101 elements (0-100), all set to false initially
IntegerSet::IntegerSet() : set(101, false) {}

// Constructor that initializes set with given array of integers
IntegerSet::IntegerSet(const int elements[], int size) : set(101, false) 
{
    for (int i = 0; i < size; ++i) 
    {
        if (elements[i] >= 0 && elements[i] <= 100) 
        {
            set[elements[i]] = true;  // Mark the corresponding index as present
        }
        else {
            std::cout << "Invalid insert attempted!" << std::endl;
        }
    }
}

// Creates a new set that contains all elements from both sets (logical OR)
IntegerSet IntegerSet::unionOfSets(const IntegerSet& other) const 
{
    IntegerSet result;
    for (int i = 0; i < 101; ++i) 
    {
        result.set[i] = set[i] || other.set[i];  // Element present in either set
    }
    return result;
}

// Creates a new set containing only elements common to both sets (logical AND)
IntegerSet IntegerSet::intersectionOfSets(const IntegerSet& other) const 
{
    IntegerSet result;
    for (int i = 0; i < 101; ++i) 
    {
        result.set[i] = set[i] && other.set[i];  // Element present in both sets
    }
    return result;
}

// Adds a specific integer to the set if it's within valid range
void IntegerSet::insertElement(int k)
{
    if (k >= 0 && k <= 100) 
    {
        set[k] = true;  // Set the corresponding index to true
    }
    else 
    {
        std::cout << "Invalid Element" << std::endl;
    }
}

// Removes a specific integer from the set if it's within valid range
void IntegerSet::deleteElement(int k) 
{
    if (k >= 0 && k <= 100)
    {
        set[k] = false;  // Set the corresponding index to false
    }
}

// Displays the set contents in { } format, shows "---" for empty sets
void IntegerSet::printSet() const 
{
    bool empty = true;
    std::cout << "{ ";
    for (int i = 0; i < 101; ++i) 
    {
        if (set[i]) 
        {
            std::cout << i << " ";  // Print the actual integer value
            empty = false;
        }
    }
    if (empty) 
    {
        std::cout << "---";  // Indicate empty set
    }
    std::cout << "}" << std::endl;
}

// Compares two sets for exact equality by checking all positions
bool IntegerSet::isEqualTo(const IntegerSet& other) const 
{
    for (int i = 0; i < 101; ++i) 
    {
        if (set[i] != other.set[i]) 
        {
            return false;  // Sets differ at this position
        }
    }
    return true;  // All positions match
}

// Interactive method to populate set with user input until -1 is entered
void IntegerSet::inputSet() 
{
    int element;
    std::cout << "Enter an element (-1 to end): ";
    while (true) 
    {
        std::cin >> element;
        if (element == -1) break;  // Termination condition
        insertElement(element);     // Use existing insert method
        std::cout << "Enter an element (-1 to end): ";
    }
    std::cout << "Entry complete" << std::endl;
}