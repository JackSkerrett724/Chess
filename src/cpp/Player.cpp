//
// Created by jackp on 10/1/2024.
//

#include "Player.h"

Player::Player(std::string name, Color color)
{
    m_name = name;
    m_color = color;
}

std::string Player::GetName()
{
    return m_name;
}

Color Player::GetColor()
{
    return m_color;
}

void Player::SetColor(Color color)
{
    m_color = color;
}

void Player::SetName(std::string name)
{
    m_name = name;
}

void Player::AddPiece(Piece* piece)
{
    m_pieces.push_back(*piece);
}

void Player::RemovePiece(Piece* piece)
{
    for(int i = 0; i < m_pieces.size(); i++)
    {
        if(m_pieces[i].GetPosition() == piece->GetPosition())
        {
            m_pieces.erase(m_pieces.begin() + i);
            break;
        }
    }
}


