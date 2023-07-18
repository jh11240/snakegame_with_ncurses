#include<unistd.h>
#include<ncurses.h>
#include "../Include/SnakeGame.h"
#include "../Include/Input.h"
#include"../Include/CollisionManager.h"
using namespace std;

SnakeGame::SnakeGame(){
    gameDelay=1;
    player= new Snake();
    entireBoard=new Board(drawableObjects,false);
    itemManager=new ItemManager(drawableObjects);
    //게이트는 벽에 세워지면 벽을 지워야하므로 벽보다 늦게 생성자 실행되어야함.
    gate= new Gate(drawableObjects,make_pair(2,0),make_pair(3,20));
    drawableObjects.push_back(static_cast<IDraw*>( player));
}
SnakeGame::SnakeGame(pair<int,int> startPoint):colMgr(CollisionManager::GetInstance()){
    gameDelay=1;
    player= new Snake(startPoint);
    entireBoard=new Board(drawableObjects,false);
    itemManager=new ItemManager(drawableObjects);
    //게이트는 벽에 세워지면 벽을 지워야하므로 벽보다 늦게 생성자 실행되어야함.
    gate= new Gate(drawableObjects,make_pair(2,0),make_pair(3,20));

    drawableObjects.push_back(static_cast<IDraw*>( player));
}

SnakeGame::~SnakeGame(){
    delete player;
    delete entireBoard;
    delete itemManager;
    drawableObjects.clear();
    vector<IDraw*>().swap(drawableObjects);
}

void SnakeGame::Display(){
       for(auto it = drawableObjects.cbegin() ; it!= drawableObjects.cend(); ++it){
        (*it)->Draw();
    }
    refresh();
}

void SnakeGame::StartGame(){
    initscr();
    noecho();               //hide input on screen
    curs_set(false);        //hide cursor

    keypad(stdscr,TRUE);    
    nodelay(stdscr,TRUE);   //getchar non-blocking mode로 실행
    while(1){
        //죽었다면 끝냄
        if(player->IsDead()) break;
        //아이템 매니저에서 아이템 생성
        itemManager->CheckIfUnusedItemExist();
        player->Move(getInput());
        colMgr.CheckIfCollide(player);
        clear();
        Display();
        sleep(gameDelay);
    }
    endwin();
}