#include "Player.hpp"

Player::Player(const std::string& name, unsigned money) 
    : name_(name), money_(money) {}

void Player::buyShip(Shipyard& shipyard, unsigned id)
{
    auto price = shipyard.getPrice(id);
    if (price && money_ >= price)
    {
        money_ -= price.value();
        ship_ = shipyard.sellShip(id);
    }
}
