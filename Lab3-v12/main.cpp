#include <iostream>
#include "factorys/headers/Motorcycle.h"

//              /   Bike   -->       Moped       \
//  Factory -->                                    --> Motorbike
//              \  Scooter --> Electric Scooter  /

int main() {
    Motorcycle moto("Audi AG", 21700, "Ducati", 275, 167, 148, 5.5);
    std::cout << moto;
    return 0;
}
/**
*  Factory name     -> Factory
*  Employees        -> Factory
*
*  Weight           -> Scooter
*  Power            -> Electrical
*
*  Brand            -> Bike
*  Max speed        -> Moped
*
*  Consumption      -> Motorbike
*  Num seats        ->
*
*  bike    >       moped           v
*  scooter > electrical scooter    > motorbike
*/

/*
 * Factory
 *
 * Bicycle Factory
 * Moped Factory
 *
 * Scooters Factory
 * Electric Scooters Factory
 *
 * Motorcycle Factory
 */