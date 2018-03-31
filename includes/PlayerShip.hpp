#ifndef PLAYERSHIP_HPP
#define PLAYERSHIP_HPP

#include <iostream>
#include "IGameEntity.hpp"

class PlayerShip : public IGameEntity
{
  public:
    PlayerShip(void);
    PlayerShip(std::string name);
    PlayerShip(PlayerShip const &src);
    ~PlayerShip(void);

    bool moveForward() = 0;
    bool moveLeft() = 0;
    bool moveRight() = 0;
    int rangedAtk();

    PlayerShip &operator=(PlayerShip const &rhs);
    std::string getName(void) const;
    void setName(std::string name);
    int getPv(void) const;
    void setPv(int pv);
    int getLvl(void) const;
    void setLvl(int lvl);
    int getSpeed(void) const;
    void setSpeed(int lvl);

  private:
    std::string _name;
    int _pv;
    int _lvl;
    int _speed; // usefull???
};

#endif // PLAYERSHIP_HPP
