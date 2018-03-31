#ifndef ENVIRONMENT_HPP
#define ENVIRONMENT_HPP
#include "PlayerShip.hpp"
#include "MissilePack.hpp"
#include "EnemyPack.hpp"
#include <ncurses.h>
#include <iostream>

class Environment
{
  public:
	Environment(void);								//canonical
	Environment(Environment const &src);			//canonical
	~Environment(void);								//canonical
	Environment &operator=(Environment const &rhs); //canonical
	unsigned int getW(void) const;
	unsigned int getH(void) const;
	bool isActive(void) const;
	void handleKey(int key);
	void print(WINDOW *local_win, int x, int y) const;
	void checkCollisions();
	void printAll(void) const;

  private:
	unsigned int _w;
	unsigned int _h;
	bool _active;
	PlayerShip _player;
	WINDOW *win;
	MissilePack _missiles;
	EnemyPack _enemies;
};

#endif
