#include <ncurses.h>
#include "PlayerShip.hpp"
#include "PlayerShip.hpp"

PlayerShip::PlayerShip(void) : _name("ship"), _x(0), _pv(20), _lvl(1), _armor(0), _atk(1), _speed(1)
{
    std::cout << "player ship created" << std::endl;
}

PlayerShip::PlayerShip(std::string const &name) : _name(name), _x(0), _pv(20), _lvl(1), _armor(0), _atk(1), _speed(1)
{
    std::cout << "player ship created" << std::endl;
}

PlayerShip::PlayerShip(PlayerShip const &src)
{
    std::cout << "player ship created" << std::endl;
    *this = src;
}

PlayerShip::~PlayerShip()
{
    std::cout << "player ship destroyed" << std::endl;
}
void PlayerShip::event(int key, int width)
{
    switch (key)
    {
    case KEY_LEFT:
    {
        this->moveLeft();
        break;
    }
    case KEY_RIGHT:
    {
        this->moveRight(width);
        break;
    }
    case ' ':
    {
        this->launchMissile();
        break;
    }
    default:
        break;
    }
}

// bool PlayerShip::moveForward()
// {
//     return true;
// }
bool PlayerShip::moveLeft()
{
    if (this->_x > 0)
        this->_x--;
    return true;
}
bool PlayerShip::moveRight(int width)
{
    if (this->_x < width)
        this->_x++;
    return true;
}

Missile &PlayerShip::launchMissile()
{
    Missile *msl = new Missile(this->_atk);
    return *msl;
}

std::string PlayerShip::getName(void) const
{
    return this->_name;
}
void PlayerShip::setName(std::string name)
{
    this->_name = name;
}

int PlayerShip::getX(void) const
{
    return this->_x;
}
void PlayerShip::setX(int x)
{
    this->_x = x;
}
int PlayerShip::getY(void) const
{
    return this->_y;
}
void PlayerShip::setY(int y)
{
    this->_y = y;
}
int PlayerShip::getWidth(void) const
{
    return this->_width;
}
void PlayerShip::setWidth(int width)
{
    this->_width = width;
}
int PlayerShip::getPv(void) const
{
    return this->_pv;
}
void PlayerShip::setPv(int pv)
{
    this->_pv = pv;
}
int PlayerShip::getLvl(void) const
{
    return this->_lvl;
}
void PlayerShip::setLvl(int lvl)
{
    this->_lvl = lvl;
}
int PlayerShip::getArmor(void) const
{
    return this->_armor;
}
void PlayerShip::setArmor(int armor)
{
    this->_armor = armor;
}
int PlayerShip::getAtk(void) const
{
    return this->_atk;
}
void PlayerShip::setAtk(int atk)
{
    this->_armor = atk;
}
int PlayerShip::getSpeed(void) const
{
    return this->_speed;
}
void PlayerShip::setSpeed(int speed)
{
    this->_speed = speed;
}

PlayerShip &PlayerShip::operator=(PlayerShip const &rhs)
{
    this->_name = rhs.getName();
    this->_x = rhs.getX();
    this->_y = rhs.getY();
    this->_pv = rhs.getPv();
    this->_lvl = rhs.getLvl();
    this->_armor = rhs.getArmor();
    this->_atk = rhs.getAtk();
    this->_speed = rhs.getSpeed();

    return *this;
}
