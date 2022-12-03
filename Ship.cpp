#include <iostream>

#include "Ship.hpp"

void Ship::hireSailors(const unsigned crewToAdd)
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
}

void Ship::releaseSailors(const unsigned crewToFire)
{
    actualCrew_ > crewToFire
    ? actualCrew_ -= crewToFire
    : actualCrew_ = 0;
}
