#include "gtest/gtest.h"

#include "../Cargo.hpp"

struct CargoTest : public ::testing::Test
{
    Cargo cargo_ {"default cargo", 250, 20, typeOfCargo::Item};
};
