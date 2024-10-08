//
// Created by jackp on 9/19/2024.
//
#include <iostream>
#include <vector>
#include "Pawn.h"

#include "Board.h"


Pawn::Pawn(std::string label, Color color, std::pair<int,int> position) : Piece(label, color, 1, position)
{
    m_initPosition = position;
    m_hasMoved = false;
}

void Pawn::SetHasMoved()
{
    m_hasMoved = true;
}

std::vector<std::pair<int,int>> Pawn::GetMoves()
{
    if(GetPosition() != m_initPosition) SetHasMoved();
    std::vector<std::pair<int,int>> moves;
    int row = GetPosition().first;
    int col = GetPosition().second;

    if(GetColor() == Color::WHITE) {
        if(row > 0 && Board::GetInstance().GetPieceAtLocation(std::make_pair(row-1, col))->GetColor() == Color::NONE)
        {
            moves.emplace_back(row-1, col);
        }
        if(row > 0 && col > 0 && Board::GetInstance().GetPieceAtLocation(std::make_pair(row-1, col-1))->GetColor() == Color::BLACK)
        {
            moves.emplace_back(row-1, col-1);
        }
        if(row > 0 && col < 7 && Board::GetInstance().GetPieceAtLocation(std::make_pair(row-1, col+1))->GetColor() == Color::BLACK)
        {
            moves.emplace_back(row-1, col+1);
        }
        if(!m_hasMoved && row > 1 && Board::GetInstance().GetPieceAtLocation(std::make_pair(row-2, col))->GetColor() == Color::NONE)
        {
            moves.emplace_back(row-2, col);
        }
    }
    else
    {
        if(row < 7 && Board::GetInstance().GetPieceAtLocation(std::make_pair(row+1, col))->GetColor() == Color::NONE)
        {
            moves.emplace_back(row+1, col);
        }
        if(row < 7 && col > 0 && Board::GetInstance().GetPieceAtLocation(std::make_pair(row+1, col-1))->GetColor() == Color::WHITE)
        {
            moves.emplace_back(row+1, col-1);
        }
        if(row < 7 && col < 7 && Board::GetInstance().GetPieceAtLocation(std::make_pair(row+1, col+1))->GetColor() == Color::WHITE)
        {
            moves.emplace_back(row+1, col+1);
        }
        if(!m_hasMoved && row < 6 && Board::GetInstance().GetPieceAtLocation(std::make_pair(row+2, col))->GetColor() == Color::NONE)
        {
            moves.emplace_back(row+2, col);
        }
    }
    moves = ValidateMoves(moves, GetColor());
    return moves;
}