#ifndef ENEMY_HPP
#define ENEMY_HPP

#include "MissilePack.hpp"
#include "PlayerShip.hpp"

class Enemy
{
  public:
    Enemy(void);
    Enemy(int x, int y, int width);
    Enemy(Enemy const &src);
    ~Enemy(void);

    bool checkHit(MissilePack &missiles, PlayerShip &palyer);

    Enemy &operator=(Enemy const &rhs);

    int getX(void) const;
    void setX(int x);
    int getY(void) const;
    void setY(int y);
    int getWidth(void) const;
    void setWidth(int width);

  private:
    int _x;
    int _y;
    int _width;
};

#endif //ENEMY_HPP
