#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>
#include <memory>

#include "Ship.hpp"
#include "Shipyard.hpp"

class Player
{
public:
    explicit Player(const std::string& name, unsigned money);

    void buyShip(Shipyard& shipyard, unsigned id);

    unsigned getMoney() const { return money_; }
    Ship getShip() const { return *ship_; }

private:
    std::string name_;
    unsigned money_;
    std::unique_ptr<Ship> ship_;
};

#endif
