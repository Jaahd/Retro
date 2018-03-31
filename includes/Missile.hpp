#ifndef MISSILE_HPP
#define MISSILE_HPP

#include "Display.hpp"

class Missile
{
  public:
    Missile(void);
    Missile(int damages, int x, int y);
    Missile(Missile const &src);
    ~Missile(void);

    bool check_target(); // TODO
    void move();
    void print(int toDisplay, int elapsed_time);

    Missile &operator=(Missile const &rhs);

    int getX(void) const;
    void setX(int new_x);
    int getY(void) const;
    void setY(int new_y);
    int getWidth(void) const;
    void setWidth(int width);
    int getSpeed(void) const;
    void setSpeed(int speed);
    int getDamages(void) const;
    void setDamages(int damages);

  private:
    int _x;
    int _y;
    int _width;
    int _speed;
    int _damages;
    Display _display;
};

#endif //MISSILE_HPP
