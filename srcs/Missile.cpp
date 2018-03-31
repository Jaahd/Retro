#include <iostream>
#include "Missile.hpp"

Missile::Missile(void) : _speed(10), _damages(1)
{
    std::cout << "missile created" << std::endl;
}

Missile::Missile(int damages) : _speed(10), _damages(damages)
{
    std::cout << "missile created" << std::endl;
}

Missile::Missile(Missile const &src)
{
    std::cout << "missile created" << std::endl;
    *this = src;
}

Missile::~Missile()
{
    std::cout << "missile destroyed" << std::endl;
}

bool Missile::check_target()
{
    std::cout << "missile hit target" << std::endl;
    this->git~Missile();
    return true;
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
