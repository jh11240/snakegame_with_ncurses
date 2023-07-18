#ifndef _CollisionManager_H
#define _CollisionManager_H
#include "ICollidable.h"
#include "Snake.h"
#include<map>

using namespace std;
class CollisionManager{
private:
    CollisionManager();
    ~CollisionManager();
    map<pair<int,int>,ICollidable*> collidableObjects;
public:
    static CollisionManager& GetInstance(){
        static CollisionManager cManager;
        return cManager;
    }
    void SetNewCollider(pair<int,int> pos, ICollidable* obj);
    void DisableCollider(pair<int,int> delObj);
    void CheckIfCollide(Snake* player);
    bool CheckIfCollide(pair<int,int> pos);
};

#endif