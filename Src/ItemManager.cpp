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
    
        int tmpPosX,tmpPosY,tmpIsPoison;
    for(Item* elem: Items){

        //item중에 사용중이 아닌 아이템이라면 해당 아이템 세팅하고 표시
        if(!elem->GetState()) {
            /* 이렇게 랜덤으로 좌표를 뽑아버리면 아이템끼리 겹칠수있다.
            떠오르는 방법은 
            (1,1)부터 (20,20)까지 모든 좌표를 pair형으로 관리하며,
            게이트 위치만 빼놓은 후 벡터에 넣어놓는다.
            그 후, 벡터 sort함수에 랜덤을 적용해서 랜덤정렬을 시킨 후,
            앞에서부터 좌표를 빼서 사용하는 방식도 좋을 것 같다.

            Snake객체에도 isSnakeBody라는 함수가 있으므로 
            앞에서 좌표를 뺄때 isSnakeBody로 체크하면서 snakeBody가 아닌 좌표만 호출하면 
            플레이어 몸에서 아이템이 생성하는 문제도 해결 할 수 있을 것이다.
            */
            tmpPosX=rand()%20,tmpPosY=rand()%20,tmpIsPoison=rand()%2;
            //collider제거
            colMgr.DisableCollider(elem->getPos());
            //아이템 새로 생성
            GenerateItem(elem,tmpPosX,tmpPosY,tmpIsPoison);
            colMgr.SetNewCollider(make_pair(tmpPosX,tmpPosY),elem);
        }
    }
}