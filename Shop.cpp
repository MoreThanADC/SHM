#include "Alcohol.hpp"
#include "Item.hpp"
#include "Fruit.hpp"
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

template <typename TypeOfCargo, typename PricesMap, typename TranslateFunction>
void Shop::generateCargo(const TypeOfCargo& cargoType, const PricesMap& pricesMap, const TranslateFunction& translateFunction) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(5, 15);

    for (const auto& [cargo, cargoInfo] : pricesMap)
    {
        auto factor = static_cast<double>(distrib(gen)) / 10.0;

        auto name = translateFunction(cargo);
        auto price = static_cast<unsigned>(cargoInfo.basePrice * factor);
        auto amount = static_cast<unsigned>(cargoInfo.baseAmount * factor);

        if (cargoType == TypeOfCargo::Alcohol)
        {
            unsigned alcoholContent = 20u * factor;
            assortment_.emplace_back(std::make_shared<Alcohol>(name, amount, price, alcoholContent));
        }
        else if (cargoType == TypeOfCargo::Fruit)
        {
            unsigned daysToSpoil = 30u * factor;
            assortment_.emplace_back(std::make_shared<Fruit>(name, amount, price, daysToSpoil));
        }
        else
        {
            assortment_.emplace_back(std::make_shared<Item>(name, amount, price));
        }
    }
}

void Shop::generateAssortment()
{
    generateCargo(TypeOfCargo::Alcohol, alcoholsWithPrices, translateNameOfAlcohol);
    generateCargo(TypeOfCargo::Fruit, fruitsWithPrices, translateNameOfFruit);
    generateCargo(TypeOfCargo::Item, itemsWithPrices, translateNameOfItem);
}

void Shop::printAssortment()
{
    std::cout << std::string(68, '#') << '\n';
    std::cout << std::internal << "#" << std::setw(40) << "SHOP ASSORTIMENT" << std::setw(28) << "#\n";
    std::cout << std::string(68, '#') << '\n';

    printAlcohols();
    std::cout << std::string(68, '=') << '\n';
    printFruits();
    std::cout << std::string(68, '=') << '\n';
    printItems();
}

void Shop::printAlcohols()
{
        std::cout << std::internal 
        << "Type" << std::setw(13)
        << "Name" << std::setw(15) 
        << "Amount" << std::setw(12) 
        << "Price" << std::setw(17)
        << "Percentage" << std::setw(8) << '\n';

    for (const auto& cargo : assortment_)
    {
        if (cargo->getType() == TypeOfCargo::Alcohol)
        {
            std::cout << *cargo;
        }
    }
}

void Shop::printFruits()
{
        std::cout << std::internal 
        << "Type" << std::setw(13)
        << "Name" << std::setw(15) 
        << "Amount" << std::setw(12) 
        << "Price" << std::setw(20)
        << "Days to spoil" << std::setw(8) << '\n';

    for (const auto& cargo : assortment_)
    {
        if (cargo->getType() == TypeOfCargo::Fruit)
        {
            std::cout << *cargo;
        }
    }
}

void Shop::printItems()
{
        std::cout << std::internal 
        << "Type" << std::setw(13)
        << "Name" << std::setw(15) 
        << "Amount" << std::setw(12) 
        << "Price" << std::setw(20) << '\n';

    for (const auto& cargo : assortment_)
    {
        if (cargo->getType() == TypeOfCargo::Item)
        {
            std::cout << *cargo << '\n';
        }
    }
}
