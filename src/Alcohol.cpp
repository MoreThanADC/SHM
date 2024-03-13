#include <iomanip>

#include "Alcohol.hpp"
#include "Cargo.hpp"

Alcohol::Alcohol(const std::string& name, unsigned amount, unsigned price, unsigned alcoholContent)
    : Cargo(name, amount, price, TypeOfCargo::Alcohol), alcoholContent_(alcoholContent)
{}

void Alcohol::updateOnNextDay()
{
    if (alcoholContent_ < MAX_ALCOHOL_CONTENT)
        alcoholContent_++;
}

std::ostream& Alcohol::print(std::ostream& os) const {
    Cargo::print(os);
    os << std::setw(12) << std::left << getAlcoholContent() << '\n';
    return os;
}

bool Alcohol::operator==(const Cargo& other) const
{
    const Alcohol* otherAlcohol = dynamic_cast<const Alcohol*>(&other);
    if (otherAlcohol)
    {
        return name_ == otherAlcohol->getName() && 
            alcoholContent_ == otherAlcohol->getAlcoholContent();
    }

    return false;
}
