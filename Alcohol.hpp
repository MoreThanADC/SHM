#include "Cargo.hpp"

class Alcohol : public Cargo
{
public:
    Alcohol(std::string name, unsigned amount, unsigned price, unsigned alcoholContent)
    : Cargo(name, amount, price)
    , alcoholContent_(alcoholContent)
{
};

private:
    unsigned alcoholContent_;
    const unsigned MAX_ALCOHOL_CONTENT = 96;
};