#include "gtest/gtest.h"

#include <memory>

#include "../Ship.hpp"

struct ShipTest : public ::testing::Test
{
    std::unique_ptr<Ship> ship_ = std::make_unique<Ship>(0, "Black Widow", 1250, 50, 100);
};

TEST_F(ShipTest, ShouldChangeName)
{
    ship_->changeName("White Kraken");
    EXPECT_EQ(ship_->getName(), "White Kraken");
}

TEST_F(ShipTest, ShouldHireSailorsIfTheShipIsBigEnough)
{
    // maxCrew == 50
    ship_->hireSailors(20);
    EXPECT_EQ(ship_->getActualCrew(), 20);
    ship_->hireSailors(15);
    EXPECT_EQ(ship_->getActualCrew(), 35);
    ship_->hireSailors(15);
    EXPECT_EQ(ship_->getActualCrew(), 50);
    ship_->hireSailors(15);
    EXPECT_EQ(ship_->getActualCrew(), 50);
}

TEST_F(ShipTest, ShouldFireSailors)
{
    ship_->hireSailors(20);
    EXPECT_EQ(ship_->getActualCrew(), 20);
    ship_->releaseSailors(15);
    EXPECT_EQ(ship_->getActualCrew(), 5);
    ship_->releaseSailors(10);
    EXPECT_EQ(ship_->getActualCrew(), 0);
}