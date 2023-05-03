#ifndef ITEM_HPP
#define ITEM_HPP

#include "Cargo.hpp"

class Item : public Cargo
{
public:
    Item(std::string name, unsigned amount, unsigned price)
    : Cargo(name, amount, price, typeOfCargo::Item)
{
};

};

#endif