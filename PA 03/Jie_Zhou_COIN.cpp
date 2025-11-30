#include <cstdlib>
#include <ctime>
#include "Jie_Zhou_Coin.h"
using namespace std;

// Constructor: initialize random seed and toss coin
Coin::Coin() 
{
    srand(static_cast<unsigned int>(time(0)));
    toss();
}

// Toss coin: randomly set to heads or tails
void Coin::toss() 
{
    int randomValue = rand() % 2;
    if (randomValue == 0) 
    {
        sideUp = "heads";
    }
    else 
    {
        sideUp = "tails";
    }
}

// Return current side facing up
string Coin::getSideUp() const 
{
    return sideUp;
}