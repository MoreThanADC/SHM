#include <iostream>

#include "Ship.hpp"

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
        << "Capacity: " << ship.cargo_.size() << '/' << ship.capacity_ << '\n'
        << "Crew: " << ship.actualCrew_ << '/' << ship.maxCrew_ << '\n';

    return os;
}
