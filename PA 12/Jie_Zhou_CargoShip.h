#ifndef Jie_Zhou_CARGOSHIP_H
#define Jie_Zhou_CARGOSHIP_H

#include <iostream>
#include <string>
#include "Jie_Zhou_Ship.h"
using namespace std;

class CargoShip : public Ship {
private:
    int maxTonnage;

public:
    // Constructor includes tonnage capacity parameter
    CargoShip(string n, string y, int m);

    // Accessor methods for tonnage capacity
    int getMaxTonnage() const;
    void setMaxTonnage(int m);

    // Override print to show tonnage capacity instead of year
    virtual void print() const override;
};

#endif#pragma once
