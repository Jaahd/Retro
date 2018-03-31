#ifndef PLAYERSHIP_HPP
#define PLAYERSHIP_HPP

#include <iostream>
#include "IGameEntity.hpp"
#include "Missile.hpp"
#include "MissilePack.hpp"
#include "Display.hpp"

class PlayerShip : public IGameEntity
{
public:
  PlayerShip(void);
  PlayerShip(std::string const &name);
  PlayerShip(PlayerShip const &src);
  ~PlayerShip(void);

  // bool moveForward();
  void event(int key, int width);
  bool moveLeft();
  bool moveRight(int width);
  Missile &launchMissile();
  // void display(Environement const &env);

  PlayerShip &operator=(PlayerShip const &rhs);

  std::string getName(void) const;
  void setName(std::string name);
  int getX(void) const;
  void setX(int abs);
  int getY(void) const;
  void setY(int y);
  int getWidth(void) const;
  void setWidth(int width);
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
  void print(void) const;

private:
  std::string _name;
  int _x;
  int _y;
  int _width;
  int _pv;
  int _lvl;
  int _armor;
  int _atk;
  int _speed; // usefull???
  MissilePack _missiles;
  Display _display;
};

#endif // PLAYERSHIP_HPP
