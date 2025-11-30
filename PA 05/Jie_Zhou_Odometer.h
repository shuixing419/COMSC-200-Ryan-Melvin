#ifndef Jie_Zhou_ODOMETER_H
#define Jie_Zhou_ODOMETER_H

#include "Jie_Zhou_FuelGauge.h"

class Odometer 
{
private:
    int mileage;
    static const int maxMileage = 999999;
    FuelGauge* fuelGauge;

public:
    Odometer(FuelGauge* fg);
    int getMileage() const;
    void incrementMileage(); // Increment mileage and manage fuel consumption
};

#endif