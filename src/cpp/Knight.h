//
// Created by jackp on 9/28/2024.
//

#include <iostream>
#include <string>
#include <Piece.h>
#include <vector>


#ifndef KNIGHT_H
#define KNIGHT_H



class Knight: public Piece
{
    public:
        Knight(std::string label, Color color, std::pair<int,int> position);
        std::vector<std::pair<int,int>> GetMoves() override;
    private:


};



#endif //KNIGHT_H
