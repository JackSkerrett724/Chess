//
// Created by jackp on 9/28/2024.
//

#ifndef EMPTY_H
#define EMPTY_H
#include "Piece.h"



class Empty: public Piece
{
    public:
        Empty( std::pair<int,int> position);
        std::vector<std::pair<int,int>> GetMoves() override;


};



#endif //EMPTY_H
