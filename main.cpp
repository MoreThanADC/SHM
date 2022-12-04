#include <iostream>

#include "Ship.hpp"
#include "Cargo.hpp"
#include "Alcohol.hpp"

int main()
{
    Ship ship {0, "Black Widow", 1250, 50, 100};
    std::cout << "Created ship: " << ship.getName() << '\n';

    ship+= 20;
    ship+= 50;
    std::cout << ship;

    Alcohol beer {"Beer", 15, 20, 5};
    ship.loadCargoOntoShip(beer);
    std::cout << ship;

    Cargo wood {"Wood", 90, 20};
    ship.loadCargoOntoShip(wood);
    std::cout << ship;


    return 0;
}