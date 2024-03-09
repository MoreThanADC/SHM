#include "Fruit.hpp"

Fruit::Fruit(std::string name, unsigned amount, unsigned price, unsigned daysToSpoil)
    : Cargo(name, amount, price, TypeOfCargo::Fruit), daysToSpoil_(daysToSpoil) {
}
