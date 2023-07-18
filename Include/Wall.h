#ifndef _Wall_H
#define _Wall_H
#include "ICollidable.h"
#include "IDraw.h"
#include "Snake.h"

class Wall : public ICollidable , public IDraw
{   
public:
    Wall(int tmpPosX,int tmpPosY);
    void Draw();
    void whenCollided(Snake* player);
private:
    int posX;
    int posY;

};

#endif