#include <iostream>
#include "Jie_Zhou_FuelGauge.h"
#include "Jie_Zhou_Odometer.h"

int main() 
{
    FuelGauge fuelGauge;

    // Fill fuel tank to maximum capacity
    for (int i = 0; i < 15; i++) 
    {
        fuelGauge.incrementFuel();
    }

    Odometer odometer(&fuelGauge);

    // Drive until out of fuel
    while (fuelGauge.getFuel() > 0) 
    {
        odometer.incrementMileage();

        // Display current mileage and fuel level
        std::cout << "Mileage: " << odometer.getMileage() << "\n";
        std::cout << "Fuel level: " << fuelGauge.getFuel() << " gallons\n";
        std::cout << "-----------------------------\n";
    }

    std::cout << "Fuel ran out" << std::endl;
    return 0;
}