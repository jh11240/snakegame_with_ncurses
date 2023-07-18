#include "../Include/Item.h"
#include <ncurses.h>


Item::Item(int tmpPosX, int tmpPosY, bool tmpIsPoison){
    lifeTime=10;
    posX=tmpPosX;
    posY=tmpPosY;
    isPoison=tmpIsPoison;
    isUsing=false;
}

void Item::SetItem(int tmpPosX, int tmpPosY, bool tmpIsPoison){
    lifeTime=10;
    posX=tmpPosX;
    posY=tmpPosY;
    isPoison=tmpIsPoison;
    isUsing=true;
}

void Item::SetState(bool tmpIsUsing){
    isUsing=tmpIsUsing;
}
pair<int,int> Item::getPos(){
    return make_pair(posX,posY);
}

bool Item::GetState(){
    return isUsing;
}

void Item::whenCollided(Snake* player){
    isUsing=false;
    if(isPoison) player->Shrink();
    else
    player->Extend();
}

void Item::Draw()
{
    if(!lifeTime) {
        isUsing=false;
    }
    if(!isUsing) return;
    lifeTime--;
    if(isPoison){
        mvprintw(posX,posY,"P");
    }
    else
        mvprintw(posX,posY,"@");
}
