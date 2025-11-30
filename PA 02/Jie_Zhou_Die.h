#ifndef Jie_Zhou_Die_H
#define Jie_Zhou_Die_H

class Die 
{
private:
    int sides;  // Number of sides
    int value;  // Current face value

public:
    Die(int numSides);          // Initialize with sides and perform initial roll
    void setSides(int numSides); // Set new sides and roll
    void roll();                // Generate new random value
    int getSides() const;       // Return number of sides
    int getValue() const;       // Return current value
};

#endif // Jie_Zhou_Die_H