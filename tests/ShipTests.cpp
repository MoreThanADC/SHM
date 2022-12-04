#include "gtest/gtest.h"

#include "../Ship.hpp"
#include "../Cargo.cpp"
#include "../Alcohol.hpp"
#include "../Fruit.hpp"

struct ShipTest : public ::testing::Test
{
    Ship ship_ {0, "Black Widow", 15, 50, 1000};
};

TEST_F(ShipTest, ShouldChangeName)
{
    ship_.changeName("White Kraken");
    EXPECT_EQ(ship_.getName(), "White Kraken");
}

TEST_F(ShipTest, ShouldHireSailorsIfTheShipIsBigEnough)
{
    // maxCrew == 50
    ship_+= 20;
    EXPECT_EQ(ship_.getActualCrew(), 20);
    ship_+= 15;
    EXPECT_EQ(ship_.getActualCrew(), 35);
    ship_+= 15;
    EXPECT_EQ(ship_.getActualCrew(), 50);
    ship_+= 15;
    EXPECT_EQ(ship_.getActualCrew(), 50);
}

TEST_F(ShipTest, ShouldFireSailors)
{
    ship_+= 20;
    EXPECT_EQ(ship_.getActualCrew(), 20);
    ship_-= 15;
    EXPECT_EQ(ship_.getActualCrew(), 5);
    ship_-= 10;
    EXPECT_EQ(ship_.getActualCrew(), 0);
}

TEST_F(ShipTest, ShouldLoadCargoOntoShipIfIsEnaughSpace)
{
    // capacity == 1000
    ship_.loadCargoOntoShip(Alcohol{"Beer", 800, 10, 6});
    EXPECT_EQ(ship_.getOccupiedSpace(), 800);
    ship_.loadCargoOntoShip(Fruit{"Banana", 200, 2, 30});
    EXPECT_EQ(ship_.getOccupiedSpace(), 1000);
    ship_.loadCargoOntoShip(Cargo{"Wood", 20, 15});
    EXPECT_EQ(ship_.getOccupiedSpace(), 1000);
}