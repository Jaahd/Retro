#include "PlayerShip.hpp"

PlayerShip::PlayerShip(void) : _name("ship"), _pv(20), _lvl(1), _speed(1)
{
    std::cout << "player ship created" << std::endl;
}

PlayerShip::PlayerShip(std::string name) : _name(name), _pv(20), _lvl(1), _speed(1)
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

bool PlayerShip::move()
{
    return true;
}

int PlayerShip::rangedAtk()
{
    Missile *msl = new Missile();
    return 0;
}

std::string PlayerShip::getName(void) const
{
    return this->_name;
}
void PlayerShip::setName(std::string name)
{
    this->_name = name;
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
    this->_pv = rhs.getPv();
    this->_lvl = rhs.getLvl();
    this->_speed = rhs.getSpeed();
    return *this;
}
