#include "Item.hpp"

Item::Item(const std::string& name, unsigned amount, unsigned price)
    : Cargo(name, amount, price, TypeOfCargo::Item) {
}
