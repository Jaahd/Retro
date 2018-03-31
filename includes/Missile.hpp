#ifndef MISSILE_HPP
#define MISSILE_HPP

class Missile
{
  public:
    Missile(void);
    Missile(int foo);
    Missile(Missile const &src);
    ~Missile(void);

    Missile &operator=(Missile const &rhs);

    int getValue(void) const;
    void setValue(int foo);

  private:
    int _foo;

};

Missile::Missile() : _speed(10), 
{
}

Missile::Missile(int foo) : _foo(foo)
{
}

Missile::Missile(Missile const &src)
{
    *this = src;
}

Missile::~Missile()
{
}

int Missile::getValue(void) const
{
    return this->_foo;
}

void Missile::setValue(int foo)
{
    this->_foo = foo;
}

Missile &Missile::operator=(Missile const &rhs) {

    this->_foo = rhs.getValue();
    return *this;
}

#endif //MISSILE_HPP
