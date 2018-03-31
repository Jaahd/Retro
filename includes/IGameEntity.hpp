#ifndef IGAMEENTITY
#define IGAMEENTITY

class IGameEntity
{
public:
    virtual ~IGameEntity() {}

    virtual bool moveForward() = 0;
    virtual bool moveLeft() = 0;
    virtual bool moveRight() = 0;
};

#endif //IGAMEENTITY
