//
// Created by jackp on 9/28/2024.
//

#include "King.h"


King::King(std::string label, Color color, std::pair<int,int> position) : Piece(label, color, 100, position)
{

}

std::vector<std::pair<int, int> > King::GetMoves()
{
    std::vector<std::pair<int,int>> moves;
    int x = GetPosition().second;
    int y = GetPosition().first;

    moves.emplace_back(y-1,x-1);
    moves.emplace_back(y-1,x);
    moves.emplace_back(y-1,x+1);
    moves.emplace_back(y,x-1);
    moves.emplace_back(y,x+1);
    moves.emplace_back(y+1,x-1);
    moves.emplace_back(y+1,x);
    moves.emplace_back(y+1,x+1);

    return ValidateMoves(moves, GetColor());
}