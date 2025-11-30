#include <iostream>
#include <algorithm>
#include <random>
#include <ctime>
#include "Jie_Zhou_DeckOfCards.h"

using namespace std;

// Initialize deck with 52 cards in order
DeckOfCards::DeckOfCards() : currentCard(0) 
{
    for (int suit = 0; suit < 4; ++suit) 
    {
        for (int face = 0; face < 13; ++face) 
        {
            deck.emplace_back(face, suit);
        }
    }
}

// Shuffle deck using current time as random seed
void DeckOfCards::shuffle() 
{
    std::shuffle(deck.begin(), deck.end(),
        std::default_random_engine(static_cast<unsigned int>(std::time(nullptr))));
    currentCard = 0;
}

// Deal next card and increment counter
Card DeckOfCards::dealCard() 
{
    if (moreCards()) 
    {
        return deck[currentCard++];
    }
    return Card(-1, -1); // Return invalid card if deck is empty
}

// Check if any cards remain to be dealt
bool DeckOfCards::moreCards() const 
{
    return currentCard < deck.size();
}