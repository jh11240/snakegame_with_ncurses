#include "../Include/Gate.h"

Gate::Gate(vector<IDraw*>& drawableObjects,pair<int,int> firstPos, pair<int,int> secondPos){
    if(colMgr.CheckIfCollide(firstPos)){
        colMgr.DisableCollider(firstPos);
    }
    if(colMgr.CheckIfCollide(secondPos)){
        colMgr.DisableCollider(secondPos);
    }
    firstGatePos=firstPos;
    secondGatePos=secondPos;
    colMgr.SetNewCollider(firstGatePos,static_cast<ICollidable*>(this));
    colMgr.SetNewCollider(secondGatePos,static_cast<ICollidable*>(this));
    drawableObjects.push_back(static_cast<IDraw*>(this));
}

void Gate::Draw(){
    mvprintw(firstGatePos.first,firstGatePos.second,"O");
    mvprintw(secondGatePos.first,secondGatePos.second,"O");
}

void Gate::whenCollided(Snake* s){
    //첫번째 게이트를 뱀이 닿았을 때,
    if(s->GetHead()==firstGatePos){
        s->SetHead(secondGatePos);
        if(secondGatePos.first==0) s->SetDirection('D');
        else if (secondGatePos.first==20) s->SetDirection('U');
        else if(secondGatePos.second==0) s->SetDirection('R');
        else if(secondGatePos.second==20) s->SetDirection('L');
    }
    else if(s->GetHead()==secondGatePos){
        s->SetHead(firstGatePos);
        if(firstGatePos.first==0) s->SetDirection('D');
        else if (firstGatePos.first==20) s->SetDirection('U');
        else if(firstGatePos.second==0) s->SetDirection('R');
        else if(firstGatePos.second==20) s->SetDirection('L');
    }
}