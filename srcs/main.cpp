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
    using namespace std;
    double lastTime = clock();
    env.handleKey(0, 0);
    while (env.isActive())
    {
        double current = clock();
        double tempo = current - lastTime;
        mvprintw(1,1, "elapsed time %f", ((float)tempo) / CLOCKS_PER_SEC);
        mvprintw(2,2, "tempo %f", ((float)tempo));
        tempo += clock();
        if (((float)tempo / CLOCKS_PER_SEC) * FPS > 1)
        {
        // float elapsed_time = ((float)t) / CLOCKS_PER_SEC;
        env.handleKey(getch(), tempo);
        env.printAll(tempo);
        lastTime = current;
        // tempo = 0;
        }
        
    }

    return 0;
}
