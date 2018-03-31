#ifndef INTERVAL_HPP
#define INTERVAL_HPP

#include <iostream>
#include <windows.h>

class Interval
{
private:
    unsigned int initial_;

public:
    // Ctor
    inline Interval() : initial_(GetTickCount())
    {
    }

    // Dtor
    virtual ~Interval()
    {
    }

    inline unsigned int value() const
    {
        return GetTickCount()-initial_;
    }
};

#endif //INTERVAL_HPP
