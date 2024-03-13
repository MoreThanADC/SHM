#include "gtest/gtest.h"

#include "../src/Shipyard.cpp"

struct ShipyardTest : public ::testing::Test
{
    Shipyard shipyard_{};

    // 1. "Stormy Sparrow", price: 1000u
    // 2. "Black Kraken", price: 2000u
    // 3. "Sky Trader", price: 4000u
};

TEST_F(ShipyardTest, ShouldReturnPriceOfShipWithGivenId)
{
    EXPECT_EQ(1000u, shipyard_.getPrice(1u));
    EXPECT_EQ(2000u, shipyard_.getPrice(2u));
    EXPECT_EQ(4000u, shipyard_.getPrice(3u));

    /* Ship with ID 4 doesn't exist */
    EXPECT_EQ(std::nullopt, shipyard_.getPrice(4u));
}

TEST_F(ShipyardTest, ShouldSellShipWithGivenId)
{
    auto soldShip = shipyard_.sellShip(1u);
    EXPECT_EQ("Stormy Sparrow", soldShip->getName());

    soldShip = shipyard_.sellShip(2u);
    EXPECT_EQ("Black Kraken", soldShip->getName());

    soldShip = shipyard_.sellShip(3u);
    EXPECT_EQ("Sky Trader", soldShip->getName());

    /* Ship with ID 4 doesn't exist */
    soldShip = shipyard_.sellShip(4u);
    EXPECT_EQ(nullptr, soldShip);
}
