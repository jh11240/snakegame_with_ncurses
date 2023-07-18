#include"../Include/Wall.h"
#include "ncurses.h"
Wall::Wall(int tmpPosX,int tmpPosY){
    posX=tmpPosX;
    posY=tmpPosY;
}

void Wall::Draw(){
    mvprintw(posX,posY,"X");
}

void Wall::whenCollided(Snake* player){
    player->Die();
}