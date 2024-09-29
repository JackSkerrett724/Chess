//
// Created by jackp on 9/19/2024.
//
#include <iostream>
#include <vector>
#include "Pawn.h"



Pawn::Pawn(std::string label, Color color, std::pair<int,int> position) : Piece(label, color, 1, position)
{
    m_firstMove = true;
}

std::vector<std::pair<int,int>> Pawn::GetMoves()
{
    std::vector<std::pair<int,int>> moves;
    if(GetColor() == Color::WHITE)
    {
        moves.emplace_back(GetPosition().first-1,GetPosition().second);
        if(m_firstMove)moves.emplace_back(GetPosition().first-2,GetPosition().second);
    }
    else
    {
        moves.emplace_back(GetPosition().first+1,GetPosition().second);
        if(m_firstMove)moves.emplace_back(GetPosition().first+2,GetPosition().second);
    }
    m_firstMove = false;
    moves = ValidateMoves(moves, GetColor());
    return moves;

}