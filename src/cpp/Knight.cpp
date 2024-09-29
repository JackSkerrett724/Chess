//
// Created by jackp on 9/28/2024.
//

#include "Knight.h"


Knight::Knight(std::string label, Color color, std::pair<int,int> position) : Piece(label, color, 3, position)
{

}

std::vector<std::pair<int, int> > Knight::GetMoves()
{
    std::vector<std::pair<int,int>> moves;
    int x = GetPosition().second;
    int y = GetPosition().first;

    moves.emplace_back(y-2,x-1);
    moves.emplace_back(y-2,x+1);
    moves.emplace_back(y-1,x-2);
    moves.emplace_back(y-1,x+2);
    moves.emplace_back(y+1,x-2);
    moves.emplace_back(y+1,x+2);
    moves.emplace_back(y+2,x-1);
    moves.emplace_back(y+2,x+1);

    return ValidateMoves(moves);
}

