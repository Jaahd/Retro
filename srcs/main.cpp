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

    env.handleKey(0, 0);
    int tempo = 0;
    while (env.isActive())
    {
       // tempo = ((clock())) % 1000;
        //mvprintw(2, 2, "tempo %d", tempo);
        env.handleKey(getch(), tempo);
        env.printAll(tempo);
        env.removeObjects();
        usleep(50000);
    }

    return 0;
}
