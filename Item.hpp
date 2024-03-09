#ifndef ITEM_HPP
#define ITEM_HPP

#include "Cargo.hpp"

class Item : public Cargo {
public:
    explicit Item(const std::string& name, unsigned amount, unsigned price);

    bool operator==(const Cargo& other) const override
    {
        const Item* otherItem = dynamic_cast<const Item*>(&other);
        if (otherItem)
        {
            return name_ == otherItem->getName();
        }

        return false;
    }
};

#endif
