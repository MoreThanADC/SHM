#ifndef CARGO_HPP
#define CARGO_HPP

#include <iostream>
#include <string>
#include "observer/TimeDependentObject.hpp"

enum class TypeOfCargo {
    Item,
    Alcohol,
    Fruit
};

class Cargo : public TimeDependentObject {
public:
    explicit Cargo(const std::string& name, unsigned amount, unsigned price, TypeOfCargo type);
    virtual ~Cargo() = default;

    Cargo(const Cargo& otherCargo);

    std::string getName() const { return name_; }
    TypeOfCargo getType() const { return cargoType_; }
    unsigned getAmount() const { return amount_; }
    unsigned getPrice() const { return price_; }

    Cargo& operator+=(const unsigned cargoToAdd);
    Cargo& operator-=(const unsigned cargoToDelete);
    Cargo& operator=(const Cargo& otherCargo);
    virtual bool operator==(const Cargo& other) const = 0;

    virtual std::ostream& print(std::ostream& os) const;

    friend std::ostream& operator<<(std::ostream& os, const Cargo& cargo);

protected:
    std::string name_;
    unsigned amount_;
    unsigned price_;
    TypeOfCargo cargoType_;
};

#endif
