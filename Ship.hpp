#ifndef SHIP_HPP
#define SHIP_HPP

#include <iostream>
#include <string>
#include <vector>
#include <memory>

#include "Cargo.hpp"

class Ship
{
public:
    explicit Ship(std::string name, unsigned speed, unsigned maxCrew, unsigned capacity)
    : name_(name)
    , speed_(speed)
    , maxCrew_(maxCrew)
    , capacity_(capacity)
{
    cargo_.reserve(capacity_);
};

void loadCargoOntoShip(const std::shared_ptr<Cargo>& cargoToAdd);
void unloadCargoFromShip(const std::shared_ptr<Cargo>& cargoToRemove);
void printCargos() const;

void changeName(const std::string& newName) { name_ = newName; }

unsigned getSpeed() const { return speed_; }
unsigned getMaxCrew() const { return maxCrew_; }
unsigned getCapacity() const { return capacity_; }
unsigned getPrice() const { return price_; }
std::string getName() const { return name_; }

unsigned getActualCrew() const { return actualCrew_; }
unsigned getOccupiedSpace() const { return spaceOccupied_; }

void setPrice(unsigned newPrice) { price_ = newPrice; }

Ship& operator+=(const unsigned crewToAdd);
Ship& operator-=(const unsigned crewToFire);

friend std::ostream& operator<<(std::ostream& os, const Ship& ship);

private:
    std::string name_;
    unsigned speed_;
    const unsigned maxCrew_;
    unsigned capacity_;
    unsigned actualCrew_ = 0;
    unsigned spaceOccupied_ = 0;
    unsigned price_ = 0;
    std::vector<std::shared_ptr<Cargo>> cargo_;
};

#endif
