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

void Pawn::SetHasMoved()
{
    m_hasMoved = true;
}

std::vector<std::pair<int,int>> Pawn::GetMoves()
{
    if(m_hasMoved) m_firstMove = false;
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
    moves = ValidateMoves(moves, GetColor());
    return moves;

}