#include "gtest/gtest.h"

#include "../Ship.hpp"
#include "../Cargo.cpp"
#include "../Alcohol.hpp"
#include "../Fruit.hpp"
#include "../Item.hpp"

struct ShipTest : public ::testing::Test
{
    Ship ship_{0, "Black Widow", 15, 50, 1000};
};

TEST_F(ShipTest, ShouldChangeName)
{
    ship_.changeName("White Kraken");
    EXPECT_EQ("White Kraken", ship_.getName());
}

TEST_F(ShipTest, ShouldHireSailorsIfTheShipIsBigEnough)
{
    // maxCrew == 50
    ship_ += 20;
    EXPECT_EQ(20, ship_.getActualCrew());
    ship_ += 15;
    EXPECT_EQ(35, ship_.getActualCrew());
    ship_ += 15;
    EXPECT_EQ(50, ship_.getActualCrew());
    ship_ += 15;
    EXPECT_EQ(50, ship_.getActualCrew());
}

TEST_F(ShipTest, ShouldFireSailors)
{
    ship_ += 20;
    EXPECT_EQ(20, ship_.getActualCrew());
    ship_ -= 15;
    EXPECT_EQ(5, ship_.getActualCrew());
    ship_ -= 10;
    EXPECT_EQ(0, ship_.getActualCrew());
}

TEST_F(ShipTest, ShouldLoadCargoOntoShipIfEnoughSpace)
{
    // capacity == 1000
    ship_.loadCargoOntoShip(Alcohol{"Beer", 800, 10, 6});
    EXPECT_EQ(800, ship_.getOccupiedSpace());
    ship_.loadCargoOntoShip(Fruit{"Banana", 200, 2, 30});
    EXPECT_EQ(1000, ship_.getOccupiedSpace());
    ship_.loadCargoOntoShip(Item{"Wood", 200, 15});
    EXPECT_EQ(1000, ship_.getOccupiedSpace());
}

TEST_F(ShipTest, ShouldUnloadCargoFromShipIfItExists)
{
    ship_.loadCargoOntoShip(Alcohol{"Beer", 400, 10, 6});
    ship_.loadCargoOntoShip(Fruit{"Banana", 200, 2, 30});
    EXPECT_EQ(600, ship_.getOccupiedSpace());
    ship_.unloadCargoFromShip(Alcohol{"Beer", 400, 10, 6});
    EXPECT_EQ(200, ship_.getOccupiedSpace());
    ship_.unloadCargoFromShip(Item{"Wood", 400, 10}); // This cargo doesn't exist on the ship
    EXPECT_EQ(200, ship_.getOccupiedSpace());
}

TEST_F(ShipTest, ShouldNotUnloadSameCargoTwiceFromShip)
{
    ship_.loadCargoOntoShip(Alcohol{"Banana", 200, 2, 30});
    EXPECT_EQ(200, ship_.getOccupiedSpace());
    ship_.unloadCargoFromShip(Alcohol{"Banana", 200, 10, 6});
    EXPECT_EQ(0, ship_.getOccupiedSpace());
    ship_.unloadCargoFromShip(Alcohol{"Banana", 200, 10, 6});
    EXPECT_EQ(0, ship_.getOccupiedSpace());
}

TEST_F(ShipTest, ShouldNotUnloadCargoFromShipIfAmountExceedsOccupiedSpace)
{
    ship_.loadCargoOntoShip(Fruit{"Banana", 200, 2, 30});
    EXPECT_EQ(200, ship_.getOccupiedSpace());
    ship_.unloadCargoFromShip(Fruit{"Banana", 300, 10, 6});
    EXPECT_EQ(200, ship_.getOccupiedSpace());
}
