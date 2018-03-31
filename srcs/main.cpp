#include <iostream>

#include "PlayerShip.hpp"
#include "Missile.hpp"

int main(void)
{
    PlayerShip toto("toto");
    Missile  &msl = toto.launchMissile();
    msl.check_target();
    return 0;
}
