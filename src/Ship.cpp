#include <algorithm>
#include <iostream>
#include <vector>

#include "Ship.hpp"
#include "Cargo.hpp"
#include "observer/Time.hpp"
#include "Fruit.hpp"

Ship::Ship(const std::string& name, unsigned speed, unsigned maxCrew, unsigned capacity)
    : name_(name)
    , speed_(speed)
    , maxCrew_(maxCrew)
    , capacity_(capacity)
{
    cargo_.reserve(capacity_);
};

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

    Time& time = Time::getInstance();
    time.addObserver(cargoToAdd);
}

void Ship::unloadCargoFromShip(const std::shared_ptr<Cargo>& cargoToRemove) {
    auto removedCargo = std::find_if(cargo_.begin(), cargo_.end(),
                                     [&](const std::shared_ptr<Cargo>& cargo) {
                                         return *cargo == *cargoToRemove;
                                     });

    if (removedCargo == cargo_.end()) {
        std::cout << "[WARNING] " << cargoToRemove->getName() << " not found on the ship\n";
        return;
    }

    if (spaceOccupied_ < cargoToRemove->getAmount()) {
        std::cout << "[WARNING] Amount of " << cargoToRemove->getName() << " exceeds occupied space on the ship\n";
        return;
    }

    Time& time = Time::getInstance();
        std::cout << "ERASE!\n";
    time.removeObserver(*removedCargo);

    spaceOccupied_ -= (*removedCargo)->getAmount();
    std::cout << "ERASE!!\n";
    cargo_.erase(removedCargo);
}

void Ship::updateOnNextDay() {
    std::cout << spaceOccupied_ << " xD \n";

    /* Check if any fruit is rotten, if yes then remove it from the ship */
    for (auto it = cargo_.begin(); it != cargo_.end();) {
        if ((*it)->getType() == TypeOfCargo::Fruit) {
            const Fruit* fruit = dynamic_cast<const Fruit*>(it->get());
            if (fruit && fruit->isRotten()) {
                std::cout << "Fruit is rotten! Unload\n";
                unloadCargoFromShip(*it);
                continue; // Incrementing 'it' is unnecessary after cargo removal
            }
        }
        ++it; // Move iterator only if no cargo removal occurred
    }
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
       << "Speed: " << ship.speed_ << '\n'
       << "Capacity: " << ship.spaceOccupied_ << '/' << ship.capacity_ << '\n'
       << "Crew: " << ship.actualCrew_ << '/' << ship.maxCrew_ << '\n';

    return os;
}
