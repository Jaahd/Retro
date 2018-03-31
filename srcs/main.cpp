#include <iostream>

#include "PlayerShip.hpp"
#include "Missile.hpp"
#include "MissilePack.hpp"
#include "Environment.hpp"
#include <ncurses.h>

int main(void)
{
    PlayerShip toto("toto");
    //Missile &pouet = toto.launchMissile();
    // Environment env;
    MissilePack mpack;

    mpack.push(new Missile());
    mpack.push(new Missile());
    mpack.push(new Missile());

    // env.handleKey(0);
    // while (env.isActive())
    // {
    //     env.handleKey(getch());
    //     env.printAll();
    // }
    return 0;
}
