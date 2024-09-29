//
// Created by jackp on 9/28/2024.
//

#ifndef KING_H
#define KING_H
#include "Piece.h"



class King: public Piece {

public:
    King(std::string label, Color color, std::pair<int,int> position);
    std::vector<std::pair<int,int>> GetMoves() override;

private:
    bool m_isInCheck;
};



#endif //KING_H
