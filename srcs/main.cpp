#include <iostream>
#include <ncurses.h>
#include <time.h>

#include "PlayerShip.hpp"
#include "Missile.hpp"
#include "MissilePack.hpp"
#include "Environment.hpp"

#define FPS 60.0

int main(void)
{
    float elapsed_time = 6;
    //PlayerShip toto("toto");
    //Missile &pouet = toto.launchMissile();
    Environment env;
    //using namespace std;
    //double lastTime = clock();
    env.handleKey(0, 0);
    int tempo = 0;
    while (env.isActive())
    {
        tempo = (tempo + (CLOCKS_PER_SEC / 1000000)) % 1000;
        mvprintw(2, 2, "tempo %d", tempo);
        env.handleKey(getch(), tempo);
        env.printAll(tempo);
    }

    return 0;
}
