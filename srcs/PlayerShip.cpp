#include <ncurses.h>
#include <iostream>
#include "PlayerShip.hpp"


PlayerShip::PlayerShip(void) : _name("ship"), _x(10), _width(5), _pv(5), _lvl(1), _armor(0), _atk(1), _speed(2), _score(0)
{
}

PlayerShip::PlayerShip(std::string const &name) : _name(name), _x(10), _width(5), _pv(5), _lvl(1), _armor(0), _atk(1), _speed(2), _score(0)
{
}

PlayerShip::PlayerShip(PlayerShip const &src)
{
    *this = src;
}

PlayerShip::~PlayerShip()
{
}

void PlayerShip::print(std::string toDisplay) const
{
    _display.print(_x, _y, COLOR_WHITE, toDisplay);
    return;
}
int PlayerShip::pvLost()
{
    this->_pv--;
    return this->_pv;
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
        this->_missiles.push(&(this->launchMissile()));
        break;
    }
    default:
        break;
    }
}

bool PlayerShip::moveLeft()
{
    if (this->_x - _speed > 0)
        this->_x -= _speed;
    else
        this->_x = 1;
    return true;
}

bool PlayerShip::moveRight(int width)
{
    if (this->_x + _width + 1 < width)
        this->_x += _speed;
    else
        this->_x = width - _width - 1;
    return true;
}

Missile &PlayerShip::launchMissile()
{
    Missile *msl = new Missile(this->_atk, this->_x + (this->_width / 2), this->_y);
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
    this->_pv = pv < 0 ? 0 : pv;
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
MissilePack &PlayerShip::getMissiles(void)
{
    return this->_missiles;
}
Display &PlayerShip::getDisplay(void)
{
    return this->_display;
}

int PlayerShip::getScore(void) const
{
    return this->_score;
}

void PlayerShip::setScore(int score)
{
    this->_score = score;
}

void PlayerShip::addPoint(int point)
{
    _score += point;
}

PlayerShip &PlayerShip::operator=(PlayerShip const &rhs)
{
    this->_name = rhs.getName();
    this->_x = rhs.getX();
    this->_y = rhs.getY();
    this->_width = rhs.getWidth();
    this->_pv = rhs.getPv();
    this->_lvl = rhs.getLvl();
    this->_armor = rhs.getArmor();
    this->_atk = rhs.getAtk();
    this->_speed = rhs.getSpeed();
    this->_score = rhs.getScore();

    return *this;
}
