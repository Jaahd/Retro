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

MissilePack &MissilePack::operator=(MissilePack const &rhs)
{

	this->_current = rhs.getValue();
	return *this;
}

void MissilePack::moveAll(void) const
{
	for (int i = 0; i < _count; i++)
	{
		_current[i]->move();
	}
}

int MissilePack::getCount(void)
{
	return _count;
}

Missile *MissilePack::getOne(int n)
{
	if (n < 0 || n > _count)
		return NULL;
	return _current[n];
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
	_current[_count++] = m;
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
			delta = 1;
	}
	if (_current)
		delete[] _current;
	_current = tmp;
	_current--;
	return _count;
}
