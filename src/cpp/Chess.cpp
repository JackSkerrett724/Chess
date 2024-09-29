#include <iostream>

#include "Bishop.h"
#include "Board.h"
#include "Pawn.h"
#include "Rook.h"

int main()
{
    Board::GetInstance().PrintBoard();
    Pawn myPawn("WP", Color::WHITE, std::make_pair(6,0));
    std::cout<<Board::GetInstance().GetBoard()[6][0].GetLabel()<<std::endl;
    myPawn.GetMoves();
    std::cout<<"PawnMoves"<<std::endl;
    for(std::pair<int,int> move : myPawn.GetMoves())
    {
        std::cout<<move.first<<","<<move.second<<std::endl;
    }
    Bishop myBishop("WB", Color::WHITE, std::make_pair(4,4));

    return 0;
}
