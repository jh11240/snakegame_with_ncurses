#include"../Include/CollisionManager.h"
using namespace std;

CollisionManager::CollisionManager(){

}

CollisionManager::~CollisionManager(){
    //내용비우고
    collidableObjects.clear();
    //메모리 지움
    map<pair<int,int>,ICollidable *>().swap(collidableObjects);
}


void CollisionManager::SetNewCollider(pair<int,int> pos,ICollidable* obj){
    collidableObjects[pos]=obj;
}

void CollisionManager::DisableCollider(pair<int,int> pos){
    collidableObjects.erase(pos);
}

void CollisionManager::CheckIfCollide(Snake* player){
    //충돌 안했다면 return
    if(collidableObjects.find(player->GetHead()) == collidableObjects.end()){
        return;
    }
    //충돌 했다면 함수호출
    collidableObjects[player->GetHead()]->whenCollided(player);
}
bool CollisionManager::CheckIfCollide(pair<int,int> pos){
    //pos위치에 collidable object가 없다면
    if(collidableObjects.find(pos) == collidableObjects.end()){
        return false;
    }
    //pos위치에 collidable object가 있다면
    else return true;
}