#include <iostream>

#include "Ship.hpp"
#include "Cargo.hpp"
#include "Alcohol.hpp"
#include "Item.hpp"
#include "Fruit.hpp"
#include "Shop.hpp"

int main()
{
    Ship ship {0, "Black Widow", 1250, 50, 1000};
    std::cout << "Created ship: " << ship.getName() << '\n';

    std::cout << ship;

    Shop shop;

    return 0;
}
