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
    void move();

    Missile &operator=(Missile const &rhs);

    int getX(void) const;
    void setX(int new_x);
    int getY(void) const;
    void setY(int new_y);
    int getSpeed(void) const;
    void setSpeed(int speed);
    int getDamages(void) const;
    void setDamages(int damages);

  private:
    int _x;
    int _y;
    int _speed;
    int _damages;
};

#endif //MISSILE_HPP
