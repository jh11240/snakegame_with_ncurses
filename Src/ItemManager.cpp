#include"../Include/ItemManager.h"
#include<cstdlib>
using namespace std;

ItemManager::ItemManager(vector<IDraw*>& drawableObjects){
    Items.push_back(new Item());
    Items.push_back(new Item());
    Items.push_back(new Item());

    for(int i=0;i<3;i++){
        drawableObjects.push_back(Items[i]);
    }
}
ItemManager::~ItemManager(){
    Items.clear();
    vector<Item*>().swap(Items);
}
void ItemManager::GenerateItem(Item* item,int tmpPosX,int tmpPosY,bool tmpIsPoison){
    item->SetItem(tmpPosX,tmpPosY,tmpIsPoison);
    item->SetState(true);
    //스네이크바디와 안겹치게 랜덤으로 나타내려면 스네이크의 전체몸을 큰 직사각형으로 하고 그 직사각형 범위외부에서 짜는게 좋을듯
}
void ItemManager::CheckIfUnusedItemExist(){
    
    int tmpPosX=rand()%21,tmpPosY=rand()%21,tmpIsPoison=rand()%2;
    for(Item* elem: Items){

        //item중에 사용중이 아닌 아이템이라면 해당 아이템 세팅하고 표시
        if(!elem->GetState()) {
            //collider제거
            colMgr.DisableCollider(elem->getPos());
            //아이템 새로 생성
            GenerateItem(elem,tmpPosX,tmpPosY,tmpIsPoison);
            colMgr.SetNewCollider(make_pair(tmpPosX,tmpPosY),elem);
        }
    }
}