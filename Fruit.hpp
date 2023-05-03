#ifndef FRUIT_HPP
#define FRUIT_HPP

#include "Cargo.hpp"

class Fruit : public Cargo
{
public:
    Fruit(std::string name, unsigned amount, unsigned price, unsigned daysToSpoil)
    : Cargo(name, amount, price, typeOfCargo::Fruit)
    , daysToSpoil_(daysToSpoil)
{
};

private:
    unsigned daysToSpoil_;
};

#endif