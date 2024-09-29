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
    for(int i = 1; i<8; i++)
    {
        if(!upRight && !upLeft && !downRight && !downLeft) break;
        if(upRight && y-i >= 0 && x+i < 8)
        {
            if(Board::GetInstance().GetPieceAtLocation(std::make_pair(y-i,x+i))->GetLabel() == "--")
            {
                moves.emplace_back(y-i,x+i);
            }
            else if(Board::GetInstance().GetPieceAtLocation(std::make_pair(y-i,x+i))->GetColor() != GetColor())
            {
                moves.emplace_back(y-i,x+i);
                upRight = false;
            }
            else
            {
                upRight = false;
            }
        }
        if(upLeft && y-i >= 0 && x-i >= 0)
        {
            if(Board::GetInstance().GetPieceAtLocation(std::make_pair(y-i,x-i))->GetLabel() == "--")
            {
                moves.emplace_back(y-i,x-i);
            }
            else if(Board::GetInstance().GetPieceAtLocation(std::make_pair(y-i,x-i))->GetColor() != GetColor())
            {
                moves.emplace_back(y-i,x-i);
                upLeft = false;
            }
            else
            {
                upLeft = false;
            }
        }
        if(downRight && y+i < 8 && x+i < 8)
        {
            if(Board::GetInstance().GetPieceAtLocation(std::make_pair(y+i,x+i))->GetLabel() == "--")
            {
                moves.emplace_back(y+i,x+i);
            }
            else if(Board::GetInstance().GetPieceAtLocation(std::make_pair(y+i,x+i))->GetColor() != GetColor())
            {
                moves.emplace_back(y+i,x+i);
                downRight = false;
            }
            else
            {
                downRight = false;
            }
        }
        if(downLeft && y+i < 8 && x-i >= 0)
        {
            if(Board::GetInstance().GetPieceAtLocation(std::make_pair(y+i,x-i))->GetLabel() == "--")
            {
                moves.emplace_back(y+i,x-i);
            }
            else if(Board::GetInstance().GetPieceAtLocation(std::make_pair(y+i,x-i))->GetColor() != GetColor())
            {
                moves.emplace_back(y+i,x-i);
                downLeft = false;
            }
            else
            {
                downLeft = false;
            }
        }
    }
    return ValidateMoves(moves, GetColor());
}
