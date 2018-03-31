#include <iostream>
#include <ncurses.h>
#include <time.h>

#include "PlayerShip.hpp"
#include "Missile.hpp"
#include "MissilePack.hpp"
#include "Environment.hpp"

int main(void)
{
    //PlayerShip toto("toto");
    //Missile &pouet = toto.launchMissile();
    Environment env;
    using namespace std;
    clock_t begin = clock();

    env.handleKey(0);
    while (env.isActive())
    {
        clock_t end = clock();
        double elapsed_time = double(end - begin) / CLOCKS_PER_SEC;

        env.handleKey(getch());
        env.printAll(elapsed_time);
    }

    return 0;
}
