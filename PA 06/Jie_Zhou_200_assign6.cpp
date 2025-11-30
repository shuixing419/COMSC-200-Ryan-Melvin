#include <iostream>
#include <iomanip>
#include "Jie_Zhou_DeckOfCards.h"

using namespace std;

int main() 
{
    DeckOfCards deck;
    deck.shuffle();

    // Deal and display all cards in 4-column format
    int count = 0;
    while (deck.moreCards()) 
    {
        std::cout << std::setw(20) << std::left << deck.dealCard().toString();
        count++;
        if (count % 4 == 0) 
        {
            std::cout << std::endl;
        }
    }

    return 0;
}