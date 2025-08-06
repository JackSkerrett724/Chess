//
// Created by jackp on 9/28/2024.
//

#ifndef ROOK_H
#define ROOK_H
#include "Piece.h"


class Rook: public Piece
{
    public:
        Rook(std::string label, Color color, std::pair<int,int> position);
        std::vector<std::pair<int,int>> GetMoves() override;
    private:
};



#endif //ROOK_H
