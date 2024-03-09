#include <iomanip>

#include "Alcohol.hpp"
#include "Cargo.hpp"

Alcohol::Alcohol(const std::string& name, unsigned amount, unsigned price, unsigned alcoholContent)
    : Cargo(name, amount, price, TypeOfCargo::Alcohol), alcoholContent_(alcoholContent) {
}

std::ostream& Alcohol::print(std::ostream& os) const {
    Cargo::print(os);
    os << std::setw(12) << std::left << getAlcoholContent() << '\n';
    return os;
}
