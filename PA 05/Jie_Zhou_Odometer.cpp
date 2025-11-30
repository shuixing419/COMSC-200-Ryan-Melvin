#include "Jie_Zhou_Odometer.h"

Odometer::Odometer(FuelGauge* fg) : mileage(0), fuelGauge(fg) {}

int Odometer::getMileage() const 
{
    return mileage;
}

void Odometer::incrementMileage() 
{
    if (mileage < maxMileage) 
    {
        mileage++;
    }
    else 
    {
        mileage = 0; // Reset at max mileage
    }

    // Consume 1 gallon every 24 miles
    if (mileage % 24 == 0) 
    {
        fuelGauge->decrementFuel();
    }
}