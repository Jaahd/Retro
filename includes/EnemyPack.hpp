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

    int push(Enemy *);
    Enemy *getOne(int) const;
    int deleteOne(int n);
    void event(int width, int height);
    void printAll(void);
    void randomChump(int width);

    Enemy **getCurrent(void) const;
    int getCount(void) const;
    
    EnemyPack &operator=(EnemyPack const &rhs);

  private:
    Enemy **_current;
    int _count;
};

#endif
