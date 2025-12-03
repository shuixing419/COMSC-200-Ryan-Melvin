#ifndef Jie_Zhou_SHIP_H
#define Jie_Zhou_SHIP_H
#include <iostream>
#include <string>
using namespace std;

class Ship {
private:
    string name;
    string year;

public:
    // Constructor takes ship name and year built
    Ship(string n, string y);

    // Accessor methods for ship attributes
    string getName() const;
    string getYear() const;
    void setName(string n);
    void setYear(string y);

    // Virtual print function for polymorphic display
    virtual void print() const;

    // Virtual destructor for proper derived class cleanup
    virtual ~Ship();
};

#endif#pragma once
