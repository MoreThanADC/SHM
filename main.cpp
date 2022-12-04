#include <iostream>

#include "Ship.hpp"

int main()
{
    Ship ship_ {0, "Black Widow", 1250, 50, 100};
    std::cout << "Created ship: " << ship_.getName() << '\n';

    ship_+= 20;
    ship_+= 50;
    std::cout << ship_;
    return 0;
}