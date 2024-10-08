//
// Created by Jack Skerrett on 9/18/2024.
//

#include "Piece.h"

#include "Board.h"




Piece::Piece(std::string label, Color color, int value, std::pair<int,int> position)
{
    m_label = label;
    m_color = color;
    m_value = value;
    m_position = position;
}


std::string Piece::GetLabel()
{
    return m_label;
}

Color Piece::GetColor()
{
    return m_color;
}

int Piece::GetValue()
{
    return m_value;
}

std::pair<int, int> Piece::GetPosition()
{
    return m_position;
}

void Piece::SetPosition(std::pair<int, int> position)
{
    m_position = position;
}

std::vector<std::pair<int, int>> Piece::ValidateMoves(std::vector<std::pair<int,int>> moves, Color color)
{
    //Board::GetInstance().PrintBoard();
    std::vector<std::pair<int, int>> validMoves;
    for(std::pair<int,int> move : moves)
    {
        if(move.first < 0 || move.first >= 8 || move.second < 0 || move.second >= 8)
        {
            continue;
        }
        if(Board::GetInstance().GetPieceAtLocation(move)->GetLabel() == "--")
        {
            validMoves.emplace_back(move);
        }
        else if(Board::GetInstance().GetPieceAtLocation(move)->GetColor() != color)
        {
            validMoves.emplace_back(move);
        }
    }
    return validMoves;
}




