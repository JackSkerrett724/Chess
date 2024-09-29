//
// Created by jackp on 9/28/2024.
//
#include "Piece.h"
#ifndef QUEEN_H
#define QUEEN_H



class Queen: public Piece
{
    public:
        Queen(std::string label, Color color, std::pair<int,int> position);
        std::vector<std::pair<int,int>> GetMoves() override;
};



#endif //QUEEN_H
