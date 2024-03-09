#ifndef SHIP_HPP
#define SHIP_HPP

#include <iostream>
#include <string>
#include <vector>

#include "Cargo.hpp"

class Ship
{
public:
    explicit Ship(unsigned id, std::string name, unsigned speed, unsigned maxCrew, unsigned capacity)
    : id_(id)
    , name_(name)
    , speed_(speed)
    , maxCrew_(maxCrew)
    , capacity_(capacity)
{
    cargo_.reserve(capacity_);
};

void loadCargoOntoShip(const Cargo& cargoToAdd);
void unloadCargoFromShip(const Cargo& cargoToRemove);
void printCargos() const;

void changeName(const std::string& newName) { name_ = newName; }

std::string getName() const { return name_; }
unsigned getActualCrew() const { return actualCrew_; }
unsigned getOccupiedSpace() const { return spaceOccupied_; }

Ship& operator+=(const unsigned crewToAdd);
Ship& operator-=(const unsigned crewToFire);

friend std::ostream& operator<<(std::ostream& os, const Ship& ship);

private:
    const unsigned id_;
    std::string name_;
    unsigned speed_;
    const unsigned maxCrew_;
    unsigned capacity_;
    unsigned actualCrew_ = 0;
    unsigned spaceOccupied_ = 0;
    std::vector<Cargo> cargo_;
};

#endif
