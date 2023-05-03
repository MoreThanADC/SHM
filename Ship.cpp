#include <algorithm>
#include <iostream>
#include <vector>

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

void Ship::unloadCargoFromShip(const Cargo& cargoToRemove)
{
    auto removedCargo = std::remove_if(cargo_.begin(), cargo_.end(),
                            [&cargoToRemove](Cargo cargo){return cargo.getName() == cargoToRemove.getName();});

    if (removedCargo == cargo_.end())
    {
        std::cout << "[WARNING] " << cargoToRemove.getName() << " not found on the ship\n";
        return;
    }

    if (spaceOccupied_ < cargoToRemove.getAmount())
    {
        std::cout << "[WARNING] Amout of " << cargoToRemove.getName() << " exceed occupied space on the ship\n";
        return;
    }

    spaceOccupied_ -= cargoToRemove.getAmount();
    cargo_.erase(removedCargo, cargo_.end());
}

void Ship::printCargos() const
{
    for (const auto& cargo : cargo_)
    {
        std::cout << cargo;
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
