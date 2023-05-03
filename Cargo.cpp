#include <iostream>

#include "Cargo.hpp"

namespace
{
    std::string translateTypeOfCargo(const typeOfCargo type)
    {
        switch (type)
        {
            case typeOfCargo::Item :
                return "Item";
            case typeOfCargo::Alcohol :
                return "Alcohol";
            case typeOfCargo::Fruit :
                return "Fruit";
            default :
                return "Invalid type of cargo";
        }
    }
}

Cargo::Cargo(const Cargo& otherCargo)
{
    this->name_ = otherCargo.name_;
    this->amount_ = otherCargo.amount_;
    this->basePrice_ = otherCargo.basePrice_;
    this->type_= otherCargo.type_;
}

Cargo& Cargo::operator=(const Cargo& otherCargo)
{
    this->name_ = otherCargo.name_;
    this->amount_ = otherCargo.amount_;
    this->basePrice_ = otherCargo.basePrice_;
    this->type_ = otherCargo.type_;
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
            << " on the ship is only " << amount_ << '\n';
    }
    else
    {
        amount_ -= cargoToDelete;
    }

    return *this;
}

std::ostream& operator<<(std::ostream& os, const Cargo& cargo)
{
    os << "Type: " << translateTypeOfCargo(cargo.type_) << ' '
        << "Name: " << cargo.name_ << ' '
        << "Amount: " << cargo.amount_ << ' '
        << "Price: " << cargo.basePrice_ << '\n';

    return os;
}