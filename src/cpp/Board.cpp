#include <iostream>
#include "Board.h"


Board::Board(int board)
{
    m_board = board;
}

void Board::PrintBoard()
{
    std::cout<<m_board;
}