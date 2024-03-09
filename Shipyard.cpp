#include <iomanip>

#include "Shipyard.hpp"

Shipyard::Shipyard()
{
    createShips();
    setPrices();
};

void Shipyard::createShips()
{
    ships_.emplace(1u, std::make_unique<Ship>("Stormy Sparrow", 35u, 20u, 200u));
    ships_.emplace(2u, std::make_unique<Ship>("Black Kraken", 30u, 30u, 400u));
    ships_.emplace(3u, std::make_unique<Ship>("Sky Trader", 25u, 60u, 1000u));
}

void Shipyard::setPrices()
{
    for (const auto& [id, ship] : ships_)
    {
        if (id == 1u)
            ship->setPrice(1000u);
        else if (id == 2u)
            ship->setPrice(2000u);
        else if (id == 3u)
            ship->setPrice(4000u);
    }
}

std::optional<unsigned> Shipyard::getPrice(unsigned shipId)
{   
    for (const auto& [id, ship] : ships_)
    {
        if (id == shipId)
            return ship->getPrice();
    }

    std::cout << "[WARNING] Not found ship for given ID: " << shipId << '\n';
    return std::nullopt;
}

std::unique_ptr<Ship> Shipyard::sellShip(unsigned shipId)
{
    auto it = ships_.find(shipId);
    if (it != ships_.end())
    {
        std::unique_ptr<Ship> soldShip = std::move(it->second);
        ships_.erase(it);
        return soldShip;
    }

    std::cout << "[WARNING] Not found ship for given ID: " << shipId << '\n';
    return nullptr;
}

void Shipyard::printShips()
{
    std::cout << std::string(90, '#') << '\n';
    std::cout << std::internal << "#" << std::setw(50) << "SHIPS TO BUY" << std::setw(40) << "#\n";
    std::cout << std::string(90, '#') << '\n';

    for (const auto& [id, ship] : ships_)
    {
        std::cout << "ID: " << std::setw(2) << std::left << id 
            << " Name: " << std::setw(16) << std::left << ship->getName() 
            << " Speed: "  << std::setw(5) << std::left <<ship->getSpeed() 
            << " Capacity: " << std::setw(5) << std::left << ship->getCapacity()
            << " Max crew: " << std::setw(5) << std::left << ship->getMaxCrew()
            << " Price: " << std::setw(5) << std::left << ship->getPrice() << '\n';
    }
}