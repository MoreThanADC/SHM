#include "Alcohol.hpp"

Alcohol::Alcohol(std::string name, unsigned amount, unsigned price, unsigned alcoholContent)
    : Cargo(name, amount, price, TypeOfCargo::Alcohol), alcoholContent_(alcoholContent) {
}
