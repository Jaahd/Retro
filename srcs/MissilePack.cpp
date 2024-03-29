#include "MissilePack.hpp"

MissilePack::MissilePack(void) : _current(0x0), _count(0)
{
}

MissilePack::MissilePack(MissilePack const &src)
{
    *this = src;
}

MissilePack::~MissilePack()
{
    if (!_current)
        return;
    for (int i = 0; i < _count; i++)
    {
        delete _current[i];
    }
    delete[] _current;
}

Missile **MissilePack::getValue(void) const
{
    return this->_current;
}

void MissilePack::printAll(void)
{
    for (int i = 0; i < this->_count; i++)
        this->_current[i]->print();
}

int MissilePack::getCount(void) const
{
    return this->_count;
}

Missile *MissilePack::getOne(int n) const
{
    if (n < 0 || n > this->_count)
        return NULL;
    return this->_current[n];
}

int MissilePack::push(Missile *m)
{
    Missile **tmp;
    if (!m)
        return _count;
    tmp = new Missile *[_count + 1];
    for (int i = 0; i < _count; i++)
    {
        tmp[i] = _current[i];
    }
    if (_current)
        delete[] _current;
    _current = tmp;
   _current[_count] = m;
   _count++;
    return _count;
}

int MissilePack::deleteOne(int n)
{
    Missile **tmp;
    int delta = 0;

    if (n < 0)
        return _count;
    tmp = new Missile *[_count - 1];
    for (int i = 0; i < _count; i++)
    {
        if (i != n)
            tmp[i - delta] = _current[i];
        else if (i == n)
        {
			delete _current[i];
			delta = 1;
		}
    }
    if (_current)
        delete[] _current;
    _current = tmp;
    _count--;
    return _count;
}

MissilePack &MissilePack::operator=(MissilePack const &rhs)
{
    this->_current = rhs.getValue();
    this->_count = rhs.getCount();
    return *this;
}
