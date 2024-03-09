#ifndef FRUIT_HPP
#define FRUIT_HPP

#include "Cargo.hpp"

class Fruit : public Cargo {
public:
    explicit Fruit(std::string name, unsigned amount, unsigned price, unsigned daysToSpoil);

    unsigned getDaysToSpoil() const { return daysToSpoil_; }

private:
    unsigned daysToSpoil_;
};

#endif
