#ifndef ENVIRONMENT_HPP
#define ENVIRONMENT_HPP
#include "PlayerShip.hpp"
#include "EnemyPack.hpp"
#include "Display.hpp"

class Environment
{
  public:
    Environment(void);
    Environment(Environment const &src);
    ~Environment(void);

    void handleKey(int key);
    void printAll();
    void print(int x, int y, int toDisplay) const;
    int checkCollisions();
    void removeObjects();

    bool isActive(void) const;
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
