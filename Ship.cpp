#include <algorithm>
#include <iostream>
#include <vector>

#include "Ship.hpp"
#include "Cargo.hpp"

void Ship::loadCargoOntoShip(const std::shared_ptr<Cargo>& cargoToAdd)
{
    if (spaceOccupied_ + cargoToAdd->getAmount() > capacity_)
    {
        std::cout << "[WARNING] Unable to load " << cargoToAdd->getAmount() << ' ' << cargoToAdd->getName() 
                  << " onto the ship. Capacity: " << spaceOccupied_ << '/' << capacity_ << '\n';
        return;
    }

    spaceOccupied_ += cargoToAdd->getAmount();
    cargo_.push_back(cargoToAdd);
}

void Ship::unloadCargoFromShip(const std::shared_ptr<Cargo>& cargoToRemove)
{
    auto removedCargo = std::find_if(cargo_.begin(), cargo_.end(),
                                     [&cargoToRemove](const std::shared_ptr<Cargo>& cargo) {
                                         return *cargo == *cargoToRemove;
                                     });

    if (removedCargo == cargo_.end()) {
        std::cout << "[WARNING] " << cargoToRemove->getName() << " not found on the ship\n";
        return;
    }

    if (spaceOccupied_ < cargoToRemove->getAmount())
    {
        std::cout << "[WARNING] Amout of " << cargoToRemove->getName() << " exceed occupied space on the ship\n";
        return;
    }

    spaceOccupied_ -= (*removedCargo)->getAmount();
    cargo_.erase(removedCargo);
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
        std::cout << "[WARNING] Ship is too small for " << actualCrew_ + crewToAdd
                  << " sailors. Maximum number of sailors is " << maxCrew_ << '\n';
    }

    return *this;
}

Ship& Ship::operator-=(const unsigned crewToFire)
{
    actualCrew_ = (actualCrew_ > crewToFire) ? (actualCrew_ - crewToFire) : 0;
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
