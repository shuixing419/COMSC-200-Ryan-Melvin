#include <iostream>
#include <string>
#include "Jie_Zhou_Ship.h"
using namespace std;

// Constructor implementation
Ship::Ship(string n, string y) {
    name = n;
    year = y;
}

// Getter and setter implementations
string Ship::getName() const {
    return name;
}

string Ship::getYear() const {
    return year;
}

void Ship::setName(string n) {
    name = n;
}

void Ship::setYear(string y) {
    year = y;
}

// Base class print displays name and year
void Ship::print() const {
    cout << "Name: " << name << "\n";
    cout << "Year built: " << year << "\n";
}

// Virtual destructor implementation
Ship::~Ship() = default;