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

    void print();
    bool check_target();
    void move();

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

    Missile &operator=(Missile const &rhs);

  private:
    int _x;
    int _y;
    int _width;
    int _speed;
    int _damages;
    std::string _toDisplay;
    Display _display;
};

#endif //MISSILE_HPP
