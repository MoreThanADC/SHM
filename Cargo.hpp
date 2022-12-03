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

Cargo& operator+=(const unsigned cargoToAdd);
Cargo& operator-=(const unsigned cargoToDelete);

private:
    const std::string name_;
    unsigned amount_;
    unsigned basePrice_;
};