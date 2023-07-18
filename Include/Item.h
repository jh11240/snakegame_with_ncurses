#ifndef _Item_H
#define _Item_H
#include "IDraw.h"
#include"ICollidable.h"

class Item : public IDraw , public ICollidable
{
public:
    Item(int tmpPosX=0,int tmpPosY=0,bool tmpIsPoison=false);
    void SetItem(int tmpPosX,int tmpPosY, bool tmpIsPoison);
    void SetState(bool tmpIsUsing);
    pair<int,int> getPos();
    void Draw();
    void whenCollided(Snake* player);
    bool GetState();
    

private:
    bool isPoison;
    bool isUsing;
    int posX;
    int posY;
    int lifeTime;
};

#endif