#ifndef _ItemManager_H
#define _ItemManager_H

#include<vector>
#include "Item.h"
#include "CollisionManager.h"
using namespace std;

class ItemManager 
{
public:
    ItemManager(vector<IDraw*>& drawableObjects );
    ~ItemManager();
    void GenerateItem(Item* item,int posX,int posY, bool isPoison);
    void CheckIfUnusedItemExist();

private:
        CollisionManager& colMgr=CollisionManager::GetInstance();
    vector<Item*> Items;
    //int maxItemCnt; 동시에 세개까지라는게 동시에 두개도 허용인지 모르겠어서 일단 보류
};

#endif