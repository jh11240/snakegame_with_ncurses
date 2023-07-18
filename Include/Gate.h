#ifndef _Gate_H
#define _Gate_H
#include <ncurses.h>
#include <vector>
#include "IDraw.h"
#include "ICollidable.h"
#include "CollisionManager.h"
using namespace std;
class Gate : public IDraw, public ICollidable
{
public:
    Gate(vector<IDraw*>& drawableObjects,pair<int,int> first, pair<int,int> second);

    void Draw();
    void whenCollided(Snake* s);

private:
    CollisionManager& colMgr=CollisionManager::GetInstance();
    pair<int,int> firstGatePos;
    pair<int,int> secondGatePos;

};

#endif