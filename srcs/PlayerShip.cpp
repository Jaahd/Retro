#include <ncurses.h>
#include "PlayerShip.hpp"

PlayerShip::PlayerShip(void) : _name("ship"), _abs(0), _pv(20), _lvl(1), _armor(0), _atk(1), _speed(1)
{
    std::cout << "player ship created" << std::endl;
}

PlayerShip::PlayerShip(std::string const & name) : _name(name), _abs(0), _pv(20), _lvl(1), _armor(0), _atk(1), _speed(1)
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
void PlayerShip::move(int key, int width)
{
    if (key == KEY_LEFT)
        this->moveLeft();
    if (key == KEY_RIGHT)
        this->moveRight(width);
}

// bool PlayerShip::moveForward()
// {
//     return true;
// }
bool PlayerShip::moveLeft()
{
    if (this->_abs > 0)
        this->_abs--;
    return true;
}
bool PlayerShip::moveRight(int width)
{
    if (this->_abs < width)
        this->_abs++;
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
int PlayerShip::getAbs(void) const
{
    return this->_abs;
}
void PlayerShip::setAbs(int abs)
{
    this->_abs = abs;
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
    this->_abs = rhs.getAbs();
    this->_pv = rhs.getPv();
    this->_lvl = rhs.getLvl();
    this->_armor = rhs.getArmor();
    this->_atk = rhs.getAtk();
    this->_speed = rhs.getSpeed();

    return *this;
}
