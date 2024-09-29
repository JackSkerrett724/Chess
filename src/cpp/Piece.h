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

typedef enum
{
    WP = 1,
    WR = 5,
    WN = 3,
    WB = 3,
    WQ = 9,
    WK = 1000,
    BP = -1,
    BR = -5,
    BN = -3,
    BB = -3,
    BQ = -9,
    BK = -1000
}PieceValue;



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
