#include <iostream>
#include <ncurses.h>
#include <time.h>
#include <unistd.h>
#include "PlayerShip.hpp"
#include "Missile.hpp"
#include "MissilePack.hpp"
#include "Environment.hpp"

#define FPS 60.0

int main(void)
{
    Environment env;

    env.handleKey(0);
    while (env.isActive())
    {
        env.checkCollisions();
        env.handleKey(getch());
        env.printAll();
        env.removeObjects();
        usleep(50000);
    }

    return 0;
}
