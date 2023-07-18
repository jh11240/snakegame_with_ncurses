#include"../Include/Board.h"

Board::Board(){
    GameBoardSizeXMax=21;
    GameBoardSizeYMax=21;
}
Board::Board(vector<IDraw*>& drawableObjects,bool tmpIfMapExist){
    if(tmpIfMapExist) return;
    //text로 된 맵없다면 21로 초기화
    GameBoardSizeXMax=21;
    GameBoardSizeYMax=42;
    for (int i = 0; i < GameBoardSizeXMax; i++)
    {
        for (int j = 0; j < GameBoardSizeYMax; j++)
        {
            if (i == 0 || i == GameBoardSizeXMax - 1)
            {
                entireBoard.push_back(new Wall(i, j));
                drawableObjects.push_back(entireBoard.back());
                colMgr.SetNewCollider({i, j}, entireBoard.back());
            }
            else
            {
                if (j == 0 || j == GameBoardSizeYMax - 1)
                {
                    entireBoard.push_back(new Wall(i, j));
                    drawableObjects.push_back(entireBoard.back());
                    colMgr.SetNewCollider({i, j}, entireBoard.back());

                }
            }
        }
    }
}
void Board::AddWall(int x,int y){
    entireBoard.push_back(new Wall(x, y));
    colMgr.SetNewCollider({x, y}, entireBoard.back());
}

