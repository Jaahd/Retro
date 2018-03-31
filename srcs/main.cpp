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
        double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
        if (elapsed_secs == 10)
            std::cout << "time : {" << elapsed_secs << "}" << std::endl;
        env.handleKey(getch());
        env.printAll();
    }

    return 0;
}
