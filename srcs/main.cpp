#include <iostream>
//#include "PlayerShip.hpp"
#include "Environment.hpp"
#include <ncurses.h>

int main(void)
{
    //PlayerShip toto("toto");
    Environment env;
    WINDOW *point = NULL;
    env.print(point, 5, 5);
    while (env.isActive())
    {
        env.handleKey(getch());
        env.print(point, 5, 5);
    }
    // std::cout << env.getH() << "height and" << env.getW() << "width\n";
    return 0;
}
