#ifndef Jie_Zhou_H
#define Jie_Zhou_COIN_H

#include <string>
using namespace std;

class Coin 
{
private:
    string sideUp;  // Current side facing up

public:
    Coin();         // Constructor
    void toss();    // Toss the coin
    string getSideUp() const;  // Get current side
};

#endif 