#ifndef CARGO_HPP
#define CARGO_HPP

#include <iostream>
#include <string>

enum class typeOfCargo {
    Item,
    Alcohol,
    Fruit
};

class Cargo
{
public:
    explicit Cargo(std::string name, unsigned amount, unsigned price, typeOfCargo type);

    Cargo(const Cargo& otherCargo);
    Cargo& operator=(const Cargo& otherCargo);

    std::string getName() const { return name_; }
    typeOfCargo getType() const { return type_; }
    unsigned getAmount() const { return amount_; }
    unsigned getPrice() const { return price_; }

    Cargo& operator+=(const unsigned cargoToAdd);
    Cargo& operator-=(const unsigned cargoToDelete);

    bool operator==(const Cargo rhs) const 
    {
        return name_ == rhs.getName();
    };

    friend std::ostream& operator<<(std::ostream& os, const Cargo& cargo);

private:
    std::string name_;
    unsigned amount_;
    unsigned price_;
    typeOfCargo type_;
};

#endif