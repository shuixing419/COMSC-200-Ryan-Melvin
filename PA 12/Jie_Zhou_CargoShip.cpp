#include <iostream>
#include <string>
#include "Jie_Zhou_CargoShip.h"
using namespace std;

// Initialize base Ship with name/year, then set tonnage capacity
CargoShip::CargoShip(string n, string y, int m) : Ship(n, y) {
    maxTonnage = m;
}

int CargoShip::getMaxTonnage() const {
    return maxTonnage;
}

void CargoShip::setMaxTonnage(int m) {
    maxTonnage = m;
}

// CargoShip displays name and tonnage capacity (hides year)
void CargoShip::print() const {
    cout << "Name: " << getName() << "\n";
    cout << "Cargo capacity: " << maxTonnage << "\n";
}