#include "Jie_Zhou_FuelGauge.h"

FuelGauge::FuelGauge() : fuel(0) {}

int FuelGauge::getFuel() const 
{
    return fuel;
}

void FuelGauge::incrementFuel() 
{
    if (fuel < maxFuel) 
    {
        fuel++;
    }
}

void FuelGauge::decrementFuel() 
{
    if (fuel > 0) 
    {
        fuel--;
    }
}