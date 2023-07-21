#ifndef _Snake_H
#define _Snake_H
#include "IDraw.h"

#include<deque>
using namespace std;


class Snake: public IDraw
{
public:
    Snake();
    ~Snake();
    Snake(pair<int,int> startNode);
    pair<int,int> GetHead(){return curHead;}
    void SetHead(pair<int,int> tmpHead){curHead=tmpHead;}
    char GetDir(){return direction;}
    void Draw();
    void SetDirection(char tmp){direction=tmp;}
    void Move(char ch);
    void Shrink();
    void Extend();
    bool IsDead();
     bool IsSnakeBody(pair<int,int> coordinate);
    void Die();

private:
    deque<pair<int,int>> snakeBody;
    pair<int,int> curHead;
    pair<int,int> prevHead;
    char direction;
    pair<int,int> tmpTail;
    bool isDead;
};

#endif
