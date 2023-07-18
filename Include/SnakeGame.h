#ifndef _SnakeGame_H
#define _SnakeGame_H

#include "Snake.h"
#include "IDraw.h"
#include "Board.h"
#include "ItemManager.h"
#include "CollisionManager.h"
#include "Gate.h"
#include<vector>
using namespace std;
class SnakeGame{
public:
    SnakeGame();
    SnakeGame(pair<int,int> startPoint);
    ~SnakeGame();
    void Display();
    void StartGame();
private:
    int gameDelay;
    Snake* player;
    Board* entireBoard;
    Gate* gate;
    ItemManager* itemManager;
    CollisionManager& colMgr=CollisionManager::GetInstance();
    vector<IDraw*> drawableObjects;
};

#endif