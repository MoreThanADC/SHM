#include <iostream>

#include "Ship.hpp"
#include "Cargo.hpp"
#include "Alcohol.hpp"
#include "Item.hpp"
#include "Fruit.hpp"

int main()
{
    Ship ship {0, "Black Widow", 1250, 50, 1000};
    std::cout << "Created ship: " << ship.getName() << '\n';

    std::cout << ship;

    Alcohol beer {"Beer", 15, 10, 5};
    ship.loadCargoOntoShip(beer);

    Item wood {"Wood", 90, 20};
    ship.loadCargoOntoShip(wood);

    Fruit banana {"Banana", 340, 5, 35};
    ship.loadCargoOntoShip(banana);

    ship.printCargos();

    std::cout << "Unload wood:\n";
    ship.unloadCargoFromShip(wood);

    ship.printCargos();

    std::cout << ship;

    ship.loadCargoOntoShip(banana);
    ship.loadCargoOntoShip(banana);

   std::cout << ship;

    ship.unloadCargoFromShip(banana);
    ship.unloadCargoFromShip(banana);

   std::cout << ship;

    return 0;
}
