#ifndef SHIPYARD_HPP
#define SHIPYARD_HPP

#include <map>
#include <memory>
#include <optional>

#include "Ship.hpp"

class Shipyard
{
public:
    explicit Shipyard();

    void printShips();
    std::unique_ptr<Ship> sellShip(unsigned id);
    std::optional<unsigned> getPrice(unsigned id);

private:
    void createShips();
    void setPrices();

    std::map<unsigned, std::unique_ptr<Ship>> ships_;
};

#endif
