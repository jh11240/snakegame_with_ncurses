#ifndef _Board_H
#define _Board_H
#include<ncurses.h>
#include<vector>
#include "IDraw.h"
#include "ICollidable.h"
#include "CollisionManager.h"
#include "Snake.h"
#include "Wall.h"
class Board
{
public:
    Board(vector<IDraw*>& drawableObjects,bool ifMapExist);
    void AddWall(vector<IDraw*>& drawableObjects,int x,int y);
private:
    CollisionManager& colMgr=CollisionManager::GetInstance();
    vector<Wall*> entireBoard;
    int GameBoardSizeXMax;
    int GameBoardSizeYMax;
};

#endif