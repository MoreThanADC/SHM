#include <iostream>
#include <iomanip>

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

Cargo::Cargo(std::string name, unsigned amount, unsigned price, typeOfCargo type)
    : name_(name)
    , amount_(amount)
    , price_(price)
    , type_(type)
    {
    }

Cargo::Cargo(const Cargo& otherCargo)
{
    this->name_ = otherCargo.name_;
    this->amount_ = otherCargo.amount_;
    this->price_ = otherCargo.price_;
    this->type_= otherCargo.type_;
}

Cargo& Cargo::operator=(const Cargo& otherCargo)
{
    this->name_ = otherCargo.name_;
    this->amount_ = otherCargo.amount_;
    this->price_ = otherCargo.price_;
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
    os << std::setw(12) << std::left << translateTypeOfCargo(cargo.type_) << ' '
       << std::setw(12) << std::left << cargo.name_ << ' '
       << std::setw(12) << std::left << cargo.amount_ << ' '
       << std::setw(12) << std::left << cargo.price_ << '\n';

    return os;
}