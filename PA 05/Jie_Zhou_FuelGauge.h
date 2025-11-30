#ifndef Jie_Zhou_FUELGAUGE_H
#define Jie_Zhou_FUELGAUGE_H

class FuelGauge 
{
private:
    int fuel;
    static const int maxFuel = 15;

public:
    FuelGauge();  // Initialize fuel gauge with default fuel level
    int getFuel() const;  // Return current fuel level
    void incrementFuel(); // Increase fuel level by one unit (max 15)
    void decrementFuel(); // Decrease fuel level by one unit (min 0)
};

#endif