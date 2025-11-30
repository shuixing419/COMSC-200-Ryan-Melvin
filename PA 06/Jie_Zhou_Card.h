#ifndef Jie_Zhou_CARD_H
#define Jie_Zhou_CARD_H

#include <string>

class Card 
{
public:
    Card(int face, int suit);
    std::string toString() const;

private:
    int face;
    int suit;
    static const std::string faces[13];
    static const std::string suits[4];
};

#endif#pragma once
