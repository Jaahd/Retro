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
	virtual int push(Enemy *);
	virtual Enemy *getOne(int) const;
	virtual int deleteOne(int n);
	virtual int getCount(void) const;

  private:
	Enemy **_current;
	int _count;
};

#endif
