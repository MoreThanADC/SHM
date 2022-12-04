#include <iostream>

#include "Ship.hpp"
#include "Cargo.hpp"

void Ship::loadCargoOntoShip(const Cargo& cargoToAdd)
{
    if (spaceOccupied_ + cargoToAdd.getAmount() > capacity_)
    {
        std::cout << "[WARNING] It is not possible to load " << cargoToAdd.getAmount() << ' ' << cargoToAdd.getName() 
            << " onto a ship because capacity is equal " << spaceOccupied_ << '/' << capacity_ << '\n';
    }
    else
    {
        spaceOccupied_ += cargoToAdd.getAmount();
        cargo_.push_back(cargoToAdd);
    }
}

Ship& Ship::operator+=(const unsigned crewToAdd)
{
    if (actualCrew_ + crewToAdd <= maxCrew_)
    {
        actualCrew_ += crewToAdd;
    }
    else
    {
        std::cout << "[WARNING] Ship is to small for " << actualCrew_ + crewToAdd
            << " sailors, max number of sailors is " << maxCrew_ << '\n';
    }

    return *this;
}

Ship& Ship::operator-=(const unsigned crewToFire)
{
    actualCrew_ > crewToFire
    ? actualCrew_ -= crewToFire
    : actualCrew_ = 0;

    return *this;
}

std::ostream& operator<<(std::ostream& os, const Ship& ship)
{
    os << "Name: " << ship.name_ << '\n'
        << "ID: " << ship.id_ << '\n'
        << "Speed: " << ship.speed_ << '\n'
        << "Capacity: " << ship.spaceOccupied_ << '/' << ship.capacity_ << '\n'
        << "Crew: " << ship.actualCrew_ << '/' << ship.maxCrew_ << '\n';

    return os;
}
