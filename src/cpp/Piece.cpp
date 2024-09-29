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

std::vector<std::pair<int, int>> Piece::ValidateMoves(std::vector<std::pair<int,int>> moves)
{
    //Board::GetInstance().PrintBoard();
    std::vector<std::pair<int, int>> validMoves;
    for(std::pair<int,int> move : moves)
    {
        std::cout<<move.first<<" "<<move.second<<std::endl;
        if(move.first < 0 || move.first >= 8 || move.second < 0 || move.second >= 8)
        {
            continue;
        }
        if(Board::GetInstance().GetBoard()[move.first][move.second]->GetLabel() == "--")
        {
            validMoves.emplace_back(move);
        }
        //if(Board::GetInstance().GetBoard()[move.first][move.second])
    }
    return validMoves;
}




