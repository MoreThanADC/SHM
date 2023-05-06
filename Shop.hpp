#ifndef SHOP_HPP
#define SHOP_HPP

#include "Cargo.hpp"

#include <map>
#include <vector>

enum class Fruits {
    Banana,
    Coconut,
    Apple,
    Orange,
    Watermelon
};

enum class Alcohols {
    Beer,
    Whisky,
    Vodka,
    Gin,
    Rum
};

enum class Items {
    Wood,
    Cotton,
    Iron,
    Spices,
    Wheat
};

class Shop {
public:
    explicit Shop();

    void printAssortment();
    void generateAssortment();

private:

    std::vector<Cargo> assortment_;

    // maps contains type of cargo, base price and base amount
    using BasePrice = unsigned;
    using BaseAmount = unsigned;

    std::map<Fruits, std::pair<BasePrice, BaseAmount>> fruitsWithPrices{
        {Fruits::Banana, {10, 30}},
        {Fruits::Coconut, {30, 8}},
        {Fruits::Apple, {5, 50}},
        {Fruits::Orange, {20, 10}},
        {Fruits::Watermelon, {40, 4}}};

    std::map<Alcohols, std::pair<BasePrice, BaseAmount>> alcoholsWithPrices{
        {Alcohols::Beer, {10, 40}},
        {Alcohols::Whisky, {150, 3}},
        {Alcohols::Vodka, {50, 10}},
        {Alcohols::Gin, {70, 7}},
        {Alcohols::Rum, {100, 5}}};

    std::map<Items, std::pair<BasePrice, BaseAmount>> itemsWithPrices{
        {Items::Wood, {30, 20}},
        {Items::Cotton, {150, 5}},
        {Items::Iron, {100, 8}},
        {Items::Spices, {250, 2}},
        {Items::Wheat, {70, 10}}};
};

#endif