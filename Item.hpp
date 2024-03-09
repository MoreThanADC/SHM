#ifndef ITEM_HPP
#define ITEM_HPP

#include "Cargo.hpp"

class Item : public Cargo {
public:
    explicit Item(std::string name, unsigned amount, unsigned price);


private:
};

#endif
