#ifndef ICHARACTER_HPP
#define ICHARACTER_HPP

#include "IGameEntity.hpp"
#include "Environement.hpp"

class ICharacters
{
  public:
    ~ICharacters(void);

    virtual bool move() = 0;
    virtual int rangedAtK() = 0;
    void display(Environement const &env);
};

#endif //ICHARACTER_HPP
