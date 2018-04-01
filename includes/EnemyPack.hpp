#ifndef EnemyPack_HPP
#define EnemyPack_HPP

#include "Enemy.hpp"
#include <iostream>

class EnemyPack
{
  public:
	EnemyPack(void);
	EnemyPack(EnemyPack const &src);
	~EnemyPack(void);

	EnemyPack &operator=(EnemyPack const &rhs);

	Enemy **getValue(void) const;
	int push(Enemy *);
	Enemy *getOne(int) const;
	int deleteOne(int n);
	int getCount(void) const;
    void event(int width);
    void printAll(void);
    void randomChump(int width);
    void checkCollisions(PlayerShip &player);

  private:
	Enemy **_current;
	int _count;
};

#endif
