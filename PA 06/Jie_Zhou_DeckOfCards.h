#ifndef Jie_Zhou_DECKOFCARDS_H
#define Jie_Zhou_DECKOFCARDS_H

#include <vector>
#include "Jie_Zhou_Card.h"

class DeckOfCards 
{
public:
    DeckOfCards();
    void shuffle();
    Card dealCard();
    bool moreCards() const;

private:
    std::vector<Card> deck;
    int currentCard;
};

#endif#pragma once
