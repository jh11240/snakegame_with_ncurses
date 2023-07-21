#include "../Include/Snake.h"
#include <ncurses.h>
using namespace std;

Snake::Snake(){
    snakeBody.push_back({5,5});
    snakeBody.push_back({6,5});
    snakeBody.push_back({7,5 });
    curHead=make_pair(5,5);
    direction='U';
}

/// @brief StartNode가 뱀의 head가 되어서 head부터 오른쪽으로 3가지 노드로 구성
/// @param StartNode 
Snake::Snake(pair<int,int> StartNode){
    snakeBody.push_back(StartNode);
    snakeBody.push_back((pair<int,int>){StartNode.first+1, StartNode.second});
    snakeBody.push_back((pair<int,int>){StartNode.first +2,StartNode.second});
    curHead=StartNode;
    direction='U';
}
Snake::~Snake(){
    snakeBody.clear();
    deque<pair<int,int>>().swap(snakeBody);
}
void Snake::Draw()
{
    for (auto it = snakeBody.cbegin(); it != snakeBody.cend(); ++it)
    {
        mvprintw(it->first,it->second, "#");
    }
}
void Snake::Move(char ch){
    pair<int,int> tmpPoint;
    switch(ch){
        case 'U':
        tmpPoint=make_pair(curHead.first-1, curHead.second);
        direction='U';
        break;
        case 'L':
        tmpPoint=make_pair(curHead.first, curHead.second-1);
        direction='L';
        break;
        case 'R':
        tmpPoint=make_pair(curHead.first, curHead.second+1);
        direction='R';
        break;
        case 'D':
        tmpPoint=make_pair(curHead.first+1, curHead.second);
        direction='D';
        break;
        case 'X':
        Move(direction);
        return;
    }

    //뒤로가면 죽음
    if(tmpPoint==prevHead) Die();
    //매 움직임마다 충돌처리매니저의 map값 갱신시키는것보단 나아보임
    if(IsSnakeBody(tmpPoint)) Die();

    snakeBody.push_front(tmpPoint);
    tmpTail=snakeBody.back();
    snakeBody.pop_back();
    prevHead=curHead;
    curHead=tmpPoint;
}
void Snake::Die(){
    isDead=true;
}

void Snake::Shrink(){
    snakeBody.pop_back();
}
void Snake::Extend(){
    snakeBody.push_back(tmpTail);
}
bool Snake::IsDead(){
    return isDead;
}

bool Snake::IsSnakeBody(pair<int,int> coordinate){
    if(find(snakeBody.begin(),snakeBody.end(),coordinate)!=snakeBody.end()){
        return true;
    }
    return false;
}