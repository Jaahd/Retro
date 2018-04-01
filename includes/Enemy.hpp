#ifndef ENEMY_HPP
#define ENEMY_HPP

#include <iostream>
#include "MissilePack.hpp"
#include "PlayerShip.hpp"

class Enemy
{
  public:
    Enemy(void);
    Enemy(int x, int y, int width, int speed, int pv, std::string toDisplay);
    Enemy(Enemy const &src);
    ~Enemy(void);

    void print();
    int checkHit(MissilePack &missiles, PlayerShip &palyer);

    int getX(void) const;
    void setX(int x);
    int getY(void) const;
    void setY(int y);
    int getWidth(void) const;
    void setWidth(int width);
    int getPv(void) const;
    void setPv(int pv);

    Enemy &operator=(Enemy const &rhs);

  private:
    int _x;
    int _y;
    int _width;
    int _speed;
    int _pv;
    std::string _toDisplay;
    Display _display;
};

#endif //ENEMY_HPP
