//
// Created by Jack Skerrett on 9/18/2024.
//
#ifndef PIECE_H
#define PIECE_H
#include <string>

enum Color
{
    WHITE,
    BLACK
};

class Piece
{
    public:
        Piece(std::string label, Color color, int value);
        std::string GetLabel();
        Color GetColor();
        int GetValue();


    private:
        std::string m_label;
        Color m_color;
        int m_value;
};



#endif //PIECE_H
