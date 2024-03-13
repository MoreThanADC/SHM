#include "gtest/gtest.h"

#include "../src/Shipyard.hpp"
#include "../src/Player.hpp"

struct PlayerTest : public ::testing::Test
{
    Player player_{"Good Sailor", 3000u};
};

TEST_F (PlayerTest, ShouldBuyShipWithGivenId)
{
    // 1. "Stormy Sparrow", price: 1000
    // 2. "Black Kraken", price: 2000
    // 3. "Sky Trader", price: 4000
    Shipyard shipyard{};

    EXPECT_EQ(3000u, player_.getMoney());

    player_.buyShip(shipyard, 1u);
    EXPECT_EQ("Stormy Sparrow", player_.getShip().getName());
    EXPECT_EQ(2000u, player_.getMoney());

    player_.buyShip(shipyard, 2u);
    EXPECT_EQ("Black Kraken", player_.getShip().getName());
    EXPECT_EQ(0u, player_.getMoney());

    /* Not enough money for buy third ship */
    player_.buyShip(shipyard, 3u);
    EXPECT_EQ("Black Kraken", player_.getShip().getName());
    EXPECT_EQ(0u, player_.getMoney());
}