//
// Created by jackp on 9/19/2024.
//

#ifndef PAWN_H
#define PAWN_H
#include "Piece.h"


class Pawn : public Piece
{
    public:
        Pawn(std::string label, Color color, std::pair<int,int> position);
        void SetHasMoved();
        std::vector<std::pair<int,int>> GetMoves() override;
    private:
        bool m_firstMove;
        bool m_hasMoved;

};



#endif //PAWN_H
