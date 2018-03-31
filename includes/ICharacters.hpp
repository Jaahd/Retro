#ifndef ICHARACTER_HPP
#define ICHARACTER_HPP

#include "IGameEntity.hpp"

class ICharacters
{
  public:
    ~ICharacters(void);

    virtual bool move() = 0;
    virtual int rangedAtK() = 0;
};

#endif //ICHARACTER_HPP
