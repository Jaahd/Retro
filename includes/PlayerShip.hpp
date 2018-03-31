#ifndef PLAYERSHIP_HPP
#define PLAYERSHIP_HPP

#include <iostream>
#include "IGameEntity.hpp"
#include "Missile.hpp"

class PlayerShip : public IGameEntity
{
  public:
    PlayerShip(void);
    PlayerShip(std::string name);
    PlayerShip(PlayerShip const &src);
    ~PlayerShip(void);

    void move(int key, int width);
    // bool moveForward();
    bool moveLeft();
    bool moveRight(int width);
    Missile &launchMissile();
    // void display(Environement const &env);

    PlayerShip &operator=(PlayerShip const &rhs);

    std::string getName(void) const;
    void setName(std::string name);
    int getPv(void) const;
    void setPv(int pv);
    int getLvl(void) const;
    void setLvl(int lvl);
    int getArmor(void) const;
    void setArmor(int armor);
    int getAtk(void) const;
    void setAtk(int Atk);
    int getSpeed(void) const;
    void setSpeed(int lvl);

  private:
    std::string _name;
    int _abs;
    int _pv;
    int _lvl;
    int _armor;
    int _atk;
    int _speed; // usefull???
};

#endif // PLAYERSHIP_HPP
