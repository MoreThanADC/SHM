#include <iostream>

#include "Cargo.hpp"

Cargo& Cargo::operator+=(const unsigned cargoToAdd)
{
    amount_ += cargoToAdd;

    return *this;
}

Cargo& Cargo::operator-=(const unsigned cargoToDelete)
{
    if (cargoToDelete > amount_)
    {
        std::cout << "[WARNING] Can't remove " << cargoToDelete << " of " << name_
            << " on the ship is only " << amount_ << '\n';
    }
    else
    {
        amount_ -= cargoToDelete;
    }

    return *this;
}