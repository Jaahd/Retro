#ifndef MISSILE_HPP
#define MISSILE_HPP

class Missile
{
  public:
    Missile(void);
    Missile(int damages);
    Missile(Missile const &src);
    ~Missile(void);

    bool check_target(); // TODO

    Missile &operator=(Missile const &rhs);

    int getSpeed(void) const;
    void setSpeed(int speed);
    int getDamages(void) const;
    void setDamages(int damages);

  private:
    int _speed;
    int _damages;
};

#endif //MISSILE_HPP
