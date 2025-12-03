#include <iostream>
#include <string>
#include "Jie_Zhou_CruiseShip.h"
using namespace std;

// Initialize base Ship with name/year, then set passenger capacity
CruiseShip::CruiseShip(string n, string y, int m) : Ship(n, y) {
    maxPassengers = m;
}

int CruiseShip::getMaxPassengers() const {
    return maxPassengers;
}

void CruiseShip::setMaxPassengers(int m) {
    maxPassengers = m;
}

// CruiseShip displays name and passenger capacity (hides year)
void CruiseShip::print() const {
    cout << "Name: " << getName() << "\n";
    cout << "Maximum passengers: " << maxPassengers << "\n";
}