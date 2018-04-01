#ifndef MISSILEPACK_HPP
#define MISSILEPACK_HPP

#include "Missile.hpp"
#include <iostream>

class MissilePack
{
  public:
	MissilePack(void);
	MissilePack(MissilePack const &src);
	~MissilePack(void);

	Missile **getValue(void) const;
	virtual int push(Missile *);
	virtual Missile *getOne(int) const;
	virtual int deleteOne(int n);
	void printAll(void);
	virtual int getCount(void) const;

	MissilePack &operator=(MissilePack const &rhs);

  private:
	Missile **_current;
	int _count;
};

#endif
