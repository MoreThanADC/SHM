#ifndef CARGO_HPP
#define CARGO_HPP

#include <string>

class Cargo
{
public:
    explicit Cargo(std::string name, unsigned amount, unsigned price)
    : name_(name)
    , amount_(amount)
    , basePrice_(price)
{
};

unsigned getAmount() const { return amount_; }
std::string getName() const { return name_; }

Cargo& operator+=(const unsigned cargoToAdd);
Cargo& operator-=(const unsigned cargoToDelete);

private:
    const std::string name_;
    unsigned amount_;
    unsigned basePrice_;
};

#endif