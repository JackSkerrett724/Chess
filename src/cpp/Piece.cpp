//
// Created by Skerrett on 9/18/2024.
//

#include "Piece.h"


Piece::Piece(std::string label, Color color, int value)
{
    m_label = label;
    m_color = color;
    m_value = value;
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


