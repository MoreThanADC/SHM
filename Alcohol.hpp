#ifndef ALCOHOL_HPP
#define ALCOHOL_HPP

#include "Cargo.hpp"

class Alcohol : public Cargo
{
public:
    Alcohol(std::string name, unsigned amount, unsigned price, unsigned alcoholContent)
    : Cargo(name, amount, price, typeOfCargo::Alcohol)
    , alcoholContent_(alcoholContent)
{
};

private:
    unsigned alcoholContent_;
    const unsigned MAX_ALCOHOL_CONTENT = 96;
};

#endif