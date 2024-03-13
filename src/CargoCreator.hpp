#ifndef CARGOCREATOR_HPP
#define CARGOCREATOR_HPP

#include <memory>

#include "Fruit.hpp"
#include "Alcohol.hpp"
#include "Item.hpp"

class CargoCreator
{
public:
    std::unique_ptr<Fruit> createFruit(const std::string& name, unsigned amount, unsigned price, unsigned days) {
        return std::make_unique<Fruit>(name, amount, price, days);
    }

    std::unique_ptr<Alcohol> createAlcohol(const std::string& name, unsigned amount, unsigned price, unsigned percentage) {
        return std::make_unique<Alcohol>(name, amount, price, percentage);
    }

    std::unique_ptr<Item> createItem(const std::string& name, unsigned amount, unsigned price) {
        return std::make_unique<Item>(name, amount, price);
    }
};

#endif