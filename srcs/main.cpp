#include <iostream>

#include "PlayerShip.hpp"
#include "Missile.hpp"
#include "Environment.hpp"
#include <ncurses.h>

int main(void)
{
    Environment env;

    env.handleKey(0);
    while (env.isActive())
    {
        env.handleKey(getch());
    }
    return 0;
}
