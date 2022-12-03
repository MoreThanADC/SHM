#include "Cargo.hpp"

class Fruit : public Cargo
{
    Fruit(std::string name, unsigned amount, unsigned price, unsigned daysToSpoil)
    : Cargo(name, amount, price)
    , daysToSpoil_(daysToSpoil)
{
};

private:
    unsigned daysToSpoil_;
};