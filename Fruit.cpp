#include <iomanip>

#include "Fruit.hpp"

Fruit::Fruit(const std::string& name, unsigned amount, unsigned price, unsigned daysToSpoil)
    : Cargo(name, amount, price, TypeOfCargo::Fruit), daysToSpoil_(daysToSpoil) {
}

std::ostream&  Fruit::print(std::ostream& os) const {
    Cargo::print(os);
    os << std::setw(12) << std::left << getDaysToSpoil() << '\n';
    return os;
}