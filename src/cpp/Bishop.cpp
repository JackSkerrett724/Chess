//
// Created by jackp on 9/19/2024.
//

#include "Bishop.h"

#include "Board.h"


Bishop::Bishop(std::string label, Color color, std::pair<int,int> position) : Piece(label, color, 3, position)
{

}

std::vector<std::pair<int, int> > Bishop::GetMoves()
{
    std::vector<std::pair<int, int>> moves;
    bool upRight = true;
    bool upLeft = true;
    bool downRight = true;
    bool downLeft = true;
    int x = GetPosition().second;
    int y = GetPosition().first;
    for(int i = 0; i<8; i++)
    {
        if(upRight)
        {
            if(Board::GetInstance().GetBoard()[y-i][x+i]->GetLabel() == "--")
            {
                std::cout<<"upRight"<<std::endl;
                moves.emplace_back(y-i,x+i);
            }
            else upRight = false;

        }
    }
    return moves;
}
