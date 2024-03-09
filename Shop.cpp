#include "Shop.hpp"

#include <random>
#include <iomanip>

namespace
{

std::string translateNameOfFruit(Fruits fruitName)
{
    switch(fruitName)
    {
        case Fruits::Banana : return "Banana";
        case Fruits::Coconut : return "Coconut";
        case Fruits::Apple : return "Apple";
        case Fruits::Orange : return "Orange";
        case Fruits::Watermelon : return "Watermelon";
        default : return "Unknown fruit";
    }
}

std::string translateNameOfAlcohol(Alcohols alcoholName)
{
    switch(alcoholName)
    {
        case Alcohols::Beer : return "Beer";
        case Alcohols::Whisky : return "Whisky";
        case Alcohols::Vodka : return "Vodka";
        case Alcohols::Gin : return "Gin";
        case Alcohols::Rum : return "Rum";
        default : return "Unknown alcohol";
    }
}

std::string translateNameOfItem(Items itemName)
{
    switch(itemName)
    {
        case Items::Wood : return "Wood";
        case Items::Cotton : return "Cotton";
        case Items::Iron : return "Iron";
        case Items::Spices : return "Spices";
        case Items::Wheat : return "Wheat";
        default : return "Unknown item";
    }
}

}

Shop::Shop()
{
    generateAssortment();
    printAssortment();
}

void Shop::generateAssortment()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(5, 15);

    auto generateCargo = [&](const auto& cargoType, const auto& pricesMap, auto translateFunction) {
        for (const auto& [cargo, cargoInfo] : pricesMap)
        {
            auto factor = static_cast<double>(distrib(gen)) / 10.0;

            auto name = translateFunction(cargo);
            unsigned price = static_cast<unsigned>(cargoInfo.basePrice * factor);
            unsigned amount = static_cast<unsigned>(cargoInfo.baseAmount * factor);

            assortment_.emplace_back(Cargo(name, amount, price, cargoType));
        }
    };

    generateCargo(TypeOfCargo::Fruit, fruitsWithPrices, translateNameOfFruit);
    generateCargo(TypeOfCargo::Alcohol, alcoholsWithPrices, translateNameOfAlcohol);
    generateCargo(TypeOfCargo::Item, itemsWithPrices, translateNameOfItem);
}

void Shop::printAssortment()
{
    std::cout << std::string(50, '#') << '\n';
    std::cout << std::internal << "#" << std::setw(32) << "SHOP ASSORTIMENT" << std::setw(18) << "#\n";
    std::cout << std::string(50, '#') << '\n';

    std::cout << std::internal 
        << "No" << std::setw(7) 
        << "Type" << std::setw(13)
        << "Name" << std::setw(15) 
        << "Amount" << std::setw(12) 
        << "Price" << std::setw(8) << '\n';

    std::cout << std::string(50, '=') << '\n';

    unsigned counter = 1;
    for (const auto& cargo : assortment_)
    {
        std::cout << std::setw(5) << std::left << counter++ << cargo;
    }
}
