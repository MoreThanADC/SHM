#include <iostream>

#include "Ship.hpp"
#include "Cargo.hpp"
#include "Alcohol.hpp"
#include "Item.hpp"
#include "Fruit.hpp"
#include "Shop.hpp"
#include "Player.hpp"
#include "Shipyard.hpp"
#include "observer/Time.hpp"

int main()
{
    Shipyard shipyard{};
    Player player("Good Sailor", 3000u);

    auto ship = std::make_shared<Ship>("Black Widow", 1250, 50, 1000);

    auto banana = std::make_shared<Fruit>("Banana", 200, 2, 3);
    auto banana2 = std::make_shared<Fruit>("Banana", 200, 2, 5);
    auto banana3 = std::make_shared<Fruit>("Banana", 200, 2, 6);
    auto banana4 = std::make_shared<Fruit>("Banana", 200, 2, 7);

    Time& time = Time::getInstance();
    time.addObserver(ship);

    ship->loadCargoOntoShip(banana);
    ship->loadCargoOntoShip(banana2);
    ship->loadCargoOntoShip(banana3);
    ship->loadCargoOntoShip(banana4);

    time.nextDay();
    time.nextDay();
    time.nextDay();
    time.nextDay();
    time.nextDay();
    time.nextDay();
    time.nextDay();
    time.nextDay();
    time.nextDay();
    time.nextDay();
    return 0;
}
