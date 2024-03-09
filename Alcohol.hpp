#ifndef ALCOHOL_HPP
#define ALCOHOL_HPP

#include "Cargo.hpp"

class Alcohol : public Cargo {
public:
    explicit Alcohol(std::string name, unsigned amount, unsigned price, unsigned alcoholContent);

    unsigned getAlcoholContent() const { return alcoholContent_; }

private:
    unsigned alcoholContent_;
    static const unsigned MAX_ALCOHOL_CONTENT = 96;
};

#endif
