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
