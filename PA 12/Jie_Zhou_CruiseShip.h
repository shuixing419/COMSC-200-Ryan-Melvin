#ifndef Jie_Zhou_CRUISESHIP_H
#define Jie_Zhou_CRUISESHIP_H

#include <iostream>
#include <string>
#include "Jie_Zhou_Ship.h"
using namespace std;

class CruiseShip : public Ship {
private:
    int maxPassengers;

public:
    // Constructor includes passenger capacity parameter
    CruiseShip(string n, string y, int m);

    // Accessor methods for passenger capacity
    int getMaxPassengers() const;
    void setMaxPassengers(int m);

    // Override print to show passenger capacity instead of year
    virtual void print() const override;
};

#endif#pragma once
