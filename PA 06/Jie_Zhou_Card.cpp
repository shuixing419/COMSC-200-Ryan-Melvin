#include <iostream>
#include "Jie_Zhou_Card.h"

using namespace std;

// Initialize static arrays for face and suit names
const std::string Card::faces[13] = 
{
    "Ace", "Deuce", "Three", "Four", "Five", "Six",
    "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"
};

const std::string Card::suits[4] = 
{
    "Hearts", "Diamonds", "Clubs", "Spades"
};

Card::Card(int face, int suit) : face(face), suit(suit) {}

// Return string representation of card
std::string Card::toString() const 
{
    return faces[face] + " of " + suits[suit];
}