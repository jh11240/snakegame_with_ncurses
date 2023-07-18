#ifndef _ICollidable_H
#define _ICollidable_H
#include"Snake.h"

class ICollidable{
public:
    virtual void whenCollided(Snake* player)=0;

};

#endif