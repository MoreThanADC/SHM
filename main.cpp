#include <iostream>

#include "Ship.hpp"
#include "Cargo.hpp"
#include "Alcohol.hpp"
#include "Item.hpp"
#include "Fruit.hpp"
#include "Shop.hpp"
#include "Player.hpp"
#include "Shipyard.hpp"

int main()
{
    Shipyard shipyard{};
    Player player("Good Sailor", 3000u);

    shipyard.printShips();
    player.buyShip(shipyard, 1u);
    shipyard.printShips();
    player.buyShip(shipyard, 2u);
    shipyard.printShips();
    player.buyShip(shipyard, 3u);
    shipyard.printShips();

    Ship ship {"Black Widow", 1250, 50, 1000};
    std::cout << "Created ship: " << ship.getName() << '\n';

    std::cout << ship;

    Shop shop;

    return 0;
}
