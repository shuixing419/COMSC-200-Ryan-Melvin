#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Jie_Zhou_Die.h"

// Initialize die with specified sides and perform initial roll
Die::Die(int numSides) 
{
    srand(time(0));  // Seed random number generator
    sides = numSides;
    roll();
}

// Set number of sides and roll
void Die::setSides(int numSides) 
{
    sides = numSides;
    roll();
}

// Roll die: generate random value between 1 and sides
void Die::roll() 
{
    value = (rand() % sides) + 1;
}

// Return number of sides
int Die::getSides() const 
{
    return sides;
}

// Return current face value
int Die::getValue() const 
{
    return value;
}