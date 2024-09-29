#include <iostream>

#include "Bishop.h"
#include "Board.h"
#include "Pawn.h"
#include "Rook.h"

int main()
{
    Board::GetInstance().PrintBoard();

    return 0;
}
