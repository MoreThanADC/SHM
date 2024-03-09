#include <iostream>
#include <iomanip>

#include "Cargo.hpp"

namespace
{
    std::string translateTypeOfCargo(const TypeOfCargo type)
    {
        switch (type)
        {
            case TypeOfCargo::Item :
                return "Item";
            case TypeOfCargo::Alcohol :
                return "Alcohol";
            case TypeOfCargo::Fruit :
                return "Fruit";
            default :
                return "Invalid type of cargo";
        }
    }
}

Cargo::Cargo(std::string name, unsigned amount, unsigned price, TypeOfCargo type)
    : name_(name)
    , amount_(amount)
    , price_(price)
    , type_(type)
    {
    }

Cargo::Cargo(const Cargo& otherCargo)
{
    name_ = otherCargo.name_;
    amount_ = otherCargo.amount_;
    price_ = otherCargo.price_;
    type_= otherCargo.type_;
}

Cargo& Cargo::operator=(const Cargo& otherCargo)
{
    name_ = otherCargo.name_;
    amount_ = otherCargo.amount_;
    price_ = otherCargo.price_;
    type_ = otherCargo.type_;
    return *this;
}

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
                  << " as there are only " << amount_ << " on the ship.\n";
    }
    else
    {
        amount_ -= cargoToDelete;
    }

    return *this;
}

std::ostream& operator<<(std::ostream& os, const Cargo& cargo)
{
    os << std::setw(12) << std::left << translateTypeOfCargo(cargo.type_) << ' '
       << std::setw(12) << std::left << cargo.name_ << ' '
       << std::setw(12) << std::left << cargo.amount_ << ' '
       << std::setw(12) << std::left << cargo.price_ << '\n';

    return os;
}
