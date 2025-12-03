#include <iostream>
#include <string>
#include "Jie_Zhou_Ship.h"
#include "Jie_Zhou_CruiseShip.h"
#include "Jie_Zhou_CargoShip.h"
using namespace std;


int main()
{
    // Create an array of Ship pointers, initialized with
    // the addresses of 3 dynamically allocated objects.
    Ship *ships[3] = { new Ship("Going Merry", "1503"),
                       new CruiseShip("Flying Merry", "1503", 2800),
                       new CargoShip("Thousand Sunny", "1800", 20000)
                     };

    // Call each object's print function using polymorphism.
    for (int index=0; index < 3; index++)
    {
        ships[index]->print();
        cout << "----------------------------\n";
        
        delete ships[index];     //release memory (avoid memory leak)
        ships[index] = nullptr;   //avoid dangling pointer
    }
    
           
    system("PAUSE");
    return 0;
}
