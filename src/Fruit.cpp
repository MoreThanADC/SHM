#include <iomanip>

#include "Fruit.hpp"

Fruit::Fruit(const std::string& name, unsigned amount, unsigned price, unsigned daysToSpoil)
    : Cargo(name, amount, price, TypeOfCargo::Fruit), daysToSpoil_(daysToSpoil) {
}

void Fruit::updateOnNextDay()
{
    if (daysToSpoil_ > 0)
    {
        daysToSpoil_--;
        std::cout << daysToSpoil_ << '\n';
    }
    else
    {
        isRotten_ = true;
    }
}

std::ostream& Fruit::print(std::ostream& os) const 
{
    Cargo::print(os);
    os << std::setw(12) << std::left << getDaysToSpoil() << '\n';
    return os;
}

bool Fruit::operator==(const Cargo& other) const
{
    const Fruit* otherFruit = dynamic_cast<const Fruit*>(&other);
    if (otherFruit)
    {
        return name_ == otherFruit->getName() && 
            daysToSpoil_ == otherFruit->getDaysToSpoil();
    }

    return false;
}
