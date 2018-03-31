#include "Enemy.hpp"
#include "MissilePack.hpp"
#include "PlayerShip.hpp"

Enemy::Enemy(void) : _x(0), _y(0), _width(1)
{
}

Enemy::Enemy(int x, int y, int width) : _x(x), _y(y), _width(width)
{
}

Enemy::Enemy(Enemy const &src)
{
    *this = src;
}

Enemy::~Enemy()
{
}

bool Enemy::checkHit(MissilePack &missiles, PlayerShip &player)
{

    if (this->_x + this->_width - player.getX() || player.getX() + player.getWidth() - this->_x)
        return true;

    for (int i = 0; i < missiles.getCount(); i++)
    {
        Missile *currMissile = missiles.getOne(i);
        if (this->_x + this->_width - currMissile->getX() || currMissile->getX() + currMissile->getWidth() - this->_x)
            delete currMissile;
    }

    return false;
}

int Enemy::getX(void) const
{
    return this->_x;
}
void Enemy::setX(int x)
{
    this->_x = x;
}
int Enemy::getY(void) const
{
    return this->_y;
}
void Enemy::setY(int y)
{
    this->_y = y;
}
int Enemy::getWidth(void) const
{
    return this->_width;
}
void Enemy::setWidth(int width)
{
    this->_width = width;
}
Enemy &Enemy::operator=(Enemy const &rhs)
{

    this->_x = rhs.getX();
    this->_y = rhs.getY();
    this->_width = rhs.getWidth();

    return *this;
}