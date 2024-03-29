#ifndef PLAYERSHIP_HPP
#define PLAYERSHIP_HPP

#include <iostream>
#include "Missile.hpp"
#include "MissilePack.hpp"
#include "Display.hpp"

#define DEAD -2

class PlayerShip
{
public:
  PlayerShip(void);
  PlayerShip(std::string const &name);
  PlayerShip(PlayerShip const &src);
  ~PlayerShip(void);

  void event(int key, int width);
  bool moveLeft();
  bool moveRight(int width);
  Missile &launchMissile();
  void print(std::string toDisplay) const;
  int pvLost();

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
  int getScore(void) const;
  void setScore(int score);
  void addPoint(int point);
  MissilePack &getMissiles();
  Display &getDisplay();

private:
  std::string _name;
  int _x;
  int _y;
  int _width;
  int _pv;
  int _lvl;
  int _armor;
  int _atk;
  int _speed;
  int _score;
  MissilePack _missiles;
  Display _display;
};

#endif // PLAYERSHIP_HPP
