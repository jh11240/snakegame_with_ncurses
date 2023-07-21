#include"../Include/Board.h"

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
                  AddWall(drawableObjects,i,j);
            }
            else
            {
                if (j == 0 || j == GameBoardSizeYMax - 1)
                {
                     AddWall(drawableObjects,i,j);

                }
            }
        }
    }
}
void Board::AddWall(vector<IDraw*>& drawableObjects,int x,int y){
    entireBoard.push_back(new Wall(x, y));
    drawableObjects.push_back(entireBoard.back());
    colMgr.SetNewCollider({x, y}, entireBoard.back());
}
