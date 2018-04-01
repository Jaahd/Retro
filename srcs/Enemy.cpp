#include "Enemy.hpp"
#include "MissilePack.hpp"
#include "PlayerShip.hpp"

Enemy::Enemy(void) : _x(0), _y(10), _width(1), _speed(1), _toDisplay('O')
{
}

Enemy::Enemy(int x, int y, int width, int speed, int toDisplay) : _x(x), _y(y), _width(width), _speed(speed), _toDisplay(toDisplay)
{
}

Enemy::Enemy(Enemy const &src)
{
    *this = src;
}

Enemy::~Enemy()
{
}

int Enemy::checkHit(MissilePack &missiles, PlayerShip &player)
{

    int playerX = player.getX();
    int playerY = player.getY();
    int playerWidth = player.getWidth();
    int count = missiles.getCount();
    int mx;
    int mw;

    if (_y + _speed >= playerY)
    {
        if ((this->_x >= playerX && this->_x <= playerX + playerWidth) || (this->_x + _width >= playerX && this->_x + _width <= playerX + playerWidth))
        {
            player.pvLost();
            return true;
        }
    }
    for (int i = 0; i < count; i++)
    {
        Missile *currMissile = missiles.getOne(i);
        mx = currMissile->getX();
        mw = currMissile->getWidth();
        if (this->_y >= currMissile->getY() - currMissile->getSpeed() && (mx >= _x && mx <= _x + _width - 1 ))
        {
            missiles.deleteOne(i);
            return true;
        }
    }

    return false;
}
void Enemy::print()
{
    // mvprintw(2, 2, "enemy x(%d) y(%d)", this->_x, this->_y);
    this->_y += this->_speed;
    this->_display.print(this->_x, this->_y, COLOR_WHITE, this->_toDisplay);
    return;
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
