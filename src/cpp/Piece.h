//
// Created by Jack Skerrett on 9/18/2024.
//
#ifndef PIECE_H
#define PIECE_H
#include <string>
#include <vector>

enum Color
{
    WHITE,
    BLACK
};

class Piece
{
    public:
    virtual ~Piece() = default;

    Piece(std::string label, Color color, int value, std::pair<int,int> position);
        std::string GetLabel();
        Color GetColor();
        int GetValue();
        std::pair<int,int> GetPosition();
        std::vector<std::pair<int,int>> ValidateMoves(std::vector<std::pair<int,int>> moves);
        virtual std::vector<std::pair<int,int>> GetMoves() = 0; //abstract function to be implemented to each individual piece class

    private:
        std::string m_label;
        Color m_color;
        int m_value;
        std::pair<int,int> m_position;
};



#endif //PIECE_H
