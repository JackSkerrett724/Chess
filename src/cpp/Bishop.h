//
// Created by jackp on 9/19/2024.
//

#ifndef BISHOP_H
#define BISHOP_H
#include "Piece.h"


class Bishop: public Piece
{
    public:
        Bishop(std::string label, Color color, std::pair<int,int> position);
        std::vector<std::pair<int,int>> GetMoves() override;
private:

};




#endif //BISHOP_H
