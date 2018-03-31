#ifndef MISSILEPACK_HPP
#define MISSILEPACK_HPP
#include "IPack.hpp"
#include "Missile.hpp"
#include <iostream>

class MissilePack
{
  public:
	MissilePack(void);
	MissilePack(MissilePack const &src);
	~MissilePack(void);

	MissilePack &operator=(MissilePack const &rhs);

	Missile **getValue(void) const;
	virtual int push(Missile *);
	virtual Missile *getOne(int);
	virtual int deleteOne(int n);
	virtual int getCount(void);
	void moveAll(void) const;

  private:
	Missile **_current;
	int _count;
};

#endif