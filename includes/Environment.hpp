#ifndef ENVIRONMENT_HPP
#define ENVIRONMENT_HPP
#include "PlayerShip.hpp"
#include "MissilePack.hpp"
#include "EnemyPack.hpp"
#include "Display.hpp"
#include <ncurses.h>
#include <iostream>

class Environment
{
  public:
    Environment(void);
    Environment(Environment const &src);
    ~Environment(void);

    bool isActive(void) const;
    void handleKey(int key);
    void print(int x, int y, int toDisplay) const;
    int checkCollisions();
    void printAll();
    void removeObjects();
    PlayerShip getPlayer() const;

    unsigned int getW(void) const;
    unsigned int getH(void) const;
    Environment &operator=(Environment const &rhs);

  private:
    unsigned int _w;
    unsigned int _h;
    bool _active;
    PlayerShip _player;
    Display _display;
    EnemyPack _enemies;
};

#endif
