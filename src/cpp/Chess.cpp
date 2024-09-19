#include <iostream>
#include "Board.h"
#include "Pawn.h"


int main()
{
    Board::GetInstance().PrintBoard();
    Pawn myPawn("WP", Color::WHITE, std::make_pair(1,1));
    myPawn.GetMoves();
    return 0;
}
