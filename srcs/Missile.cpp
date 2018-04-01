#include <iostream>
#include "Missile.hpp"
#include "Missile.hpp"

Missile::Missile(void) : _speed(1), _damages(1), _toDisplay('.')
{
    //std::cout << "missile created" << std::endl;
}

Missile::Missile(int damages, int x, int y) : _x(x), _y(y), _speed(1), _damages(damages), _toDisplay('.')
{
    // std::cout << "missile created" << std::endl;
}

Missile::Missile(Missile const &src)
{
    // std::cout << "missile created" << std::endl;
    *this = src;
}

Missile::~Missile()
{
    // std::cout << "missile destroyed -- x:[" << this->_x << "] y[" << this->_y << std::endl;
}

void Missile::print()
{
    this->_y -= this->_speed;
    this->_display.print(this->_x, this->_y, COLOR_WHITE, this->_toDisplay);
    return;
}

bool Missile::check_target()
{
    //std::cout << "missile hit target" << std::endl;
    this->~Missile();
    return true;
}

void Missile::move()
{
    this->_y -= 1;
}

int Missile::getX(void) const
{
    return this->_x;
}
void Missile::setX(int new_x)
{
    this->_x = new_x;
}
int Missile::getY(void) const
{
    return this->_y;
}
void Missile::setY(int new_y)
{
    this->_y = new_y;
}
int Missile::getWidth(void) const
{
    return this->_width;
}
void Missile::setWidth(int width)
{
    this->_width = width;
}
int Missile::getSpeed(void) const
{
    return this->_speed;
}
void Missile::setSpeed(int speed)
{
    this->_speed = speed;
}
int Missile::getDamages(void) const
{
    return this->_damages;
}
void Missile::setDamages(int damages)
{
    this->_damages = damages;
}

Missile &Missile::operator=(Missile const &rhs)
{

    this->_damages = rhs.getDamages();
    this->_speed = rhs.getSpeed();

    return *this;
}
